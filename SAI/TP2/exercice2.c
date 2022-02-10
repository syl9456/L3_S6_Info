#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>

typedef struct cote{
	int x1;
	int y1;
	int x2;
	int y2;
}cote;


/*
*	Primitive de trace_picel(x,y)
*/

float taille_Pixel;
int monX1, monY1, monR;
int nbCote;
cote coteCandidat[1000];
cote coteEntrant[1000];
cote coteSortant[1000];

void trace_pixel(int x, int y){
	glBegin(GL_QUADS);
		glVertex2f(x-0.5, y-0.5);
		glVertex2f(x-0.5, y+0.5);
		glVertex2f(x+0.5, y+0.5);
		glVertex2f(x+0.5, y-0.5);
	glEnd();
}

void LCE(int Ymin, int Ymax){

	int nbMis;

	for(int i = Ymin - 2; i <= Ymax + 2; i++){
		for(int y = 0; y < nbCote; y++){
			if(coteCandidat[y].y1 <= coteCandidat[y].y2){
				if(i >= coteCandidat[y].y1){
					coteEntrant[nbMis] = y;
				}
			}
		}
	}

}

void LCS(int Ymin, int Ymax){

}

/*
*	Remplissage
*/

void remplissageBalayage(){
	int Ymin = 2147000000;
	int Ymax = -2147000000;
	int t;
	int Xmin;
	int Xmax;

	/* On cherche Ymin et Ymax */

	for(int i=0; i<nbCote; i++){
		if(coteCandidat[i].y1 < Ymin){
			Ymin = coteCandidat[i].y1;
		}
		if(coteCandidat[i].y2 < Ymin){
			Ymin = coteCandidat[i].y2;
		}
		if(coteCandidat[i].y1 > Ymax){
			Ymax = coteCandidat[i].y1;
		}
		if(coteCandidat[i].y2 > Ymax){
			Ymax = coteCandidat[i].y2;
		}
	}

	for(int y0 = Ymin; y0 <= Ymax; y0++){

	}
	
}


/*
*	FONCTION D'AFFICHAGE
*/

void Affichage(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5/taille_Pixel, 5/taille_Pixel, -5/taille_Pixel, 5/taille_Pixel, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* Définition des points */
	remplissageBalayage();
	glFlush();
}


int main(int argc, char *argv[]){

	FILE *monFichier;

	if(argc != 3){
		printf("\n\nUsage : ./Exercice2 [Fichier des Points] [TaillePixel]\n\n");
		exit(1);
	}
	else{
		taille_Pixel = atof(argv[2]);
		monFichier = fopen(argv[1], "r+");

	    if (monFichier != NULL)
	    {
	        // On peut lire et écrire dans le fichier
	        while(fscanf(monFichier, "%d, %d\n", &coteCandidat[nbCote].x, &coteCandidat[nbCote].y) != EOF){
		        /*printf("\nOn a chargé le point : (%d, %d)", coteCandidat[nbCote].x, coteCandidat[nbCote].y);*/
		        nbCote++;
		    }
	    }
	    else
	    {
	        // On affiche un message d'erreur si on veut
	        printf("\nImpossible d'ouvrir le fichier %s\n", argv[1]);
	        exit(0);
	    }
	}
	
	/* Initialisation de GLUT */
	glutInit(&argc, argv);

	/* Initialisation du mode d'affichage */
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	/* On fixe la taille et la position de la fenêtre */
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);

	/* Creation de la fenêtre */
	glutCreateWindow("Exercice 2");

	/* On affiche */
	glutDisplayFunc(Affichage);

	glutMainLoop();


	return 0;
}