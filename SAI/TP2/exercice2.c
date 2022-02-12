#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>

typedef struct point{
	int x;
	int y;
}point;

typedef struct cote{
	point p1;
	point p2;
}cote;

float taille_Pixel;
int nbCote;
int nbPoint;
double M1, M2, K1, K2;
int Xmin, Xmax;
int indiceEntrant = 0;

cote coteCandidat[1000];
int coteEntrant[1000];
int coteSortant[1000];
point tabPoint[1001];

/*
*	Primitive de trace_picel(x,y)
*/

void trace_pixel(int x, int y){
	glBegin(GL_QUADS);
		glVertex2f(x-0.5, y-0.5);
		glVertex2f(x-0.5, y+0.5);
		glVertex2f(x+0.5, y+0.5);
		glVertex2f(x+0.5, y-0.5);
	glEnd();
}

/*
*	CONSTRUIT LA LCC
*/

void LCC(){
	/* On construit tout les segment dans l'ordre autre que le dernier point vers le premier*/
	for(int i = 0; i < nbPoint; i++){
		coteCandidat[nbCote].p1.x = tabPoint[i].x;
		coteCandidat[nbCote].p1.y = tabPoint[i].y;
		coteCandidat[nbCote].p2.x = tabPoint[i+1].x;
		coteCandidat[nbCote].p2.y = tabPoint[i+1].y;
		nbCote++;
	}
	/* Segment du dernier au premier point */
	coteCandidat[nbCote].p1.x = tabPoint[nbPoint].x;
	coteCandidat[nbCote].p1.y = tabPoint[nbPoint].y;
	coteCandidat[nbCote].p2.x = tabPoint[0].x;
	coteCandidat[nbCote].p2.y = tabPoint[0].y;
	nbCote++;

	printf("\n** Liste des Côtes **\n\n");
	for(int i = 0; i < nbCote; i++){
		printf("[Côte %d] : (%d, %d) --> (%d, %d)\n",
				i,
				coteCandidat[i].p1.x,
				coteCandidat[i].p1.y,
				coteCandidat[i].p2.x,
				coteCandidat[i].p2.y);
	}
	printf("\n");
}

/*
*	CONSTRUIT LA LCE
*/

void LCE(int Ymin, int Ymax){

	int nbMis = 0;
	int fait[nbCote];

	for(int i = 0; i < nbCote; i++){
		fait[i] = 0;
	}

	for(int i = Ymin; i <= Ymax; i++){
		for(int j = 0; j < nbCote; j++){
			if(coteCandidat[j].p1.y <= coteCandidat[j].p2.y){
				if(i >= coteCandidat[j].p1.y && fait[j] == 0){
					coteEntrant[nbMis] = j;
					fait[j] = 1;
					nbMis++;
				}
			}
			else{
				if(i >= coteCandidat[j].p2.y && fait[j] == 0){
					coteEntrant[nbMis] = j;
					fait[j] = 1;
					nbMis++;
				}
			}
		}
	}

	printf("\n Tableau LCE : ");

	for(int i = 0; i < nbCote; i++){
		printf("[%d]", coteEntrant[i]);
	}
	printf("\n\n");

}

/*
*	CONSTRUIT LA LCS
*/

void LCS(int Ymin, int Ymax){

	int nbMis = 0;
	int fait[nbCote];
	int fait2[nbCote];

	for(int i = 0; i < nbCote; i++){
		fait[i] = 0;
		fait2[i] = 0;
	}

	for(int i = Ymin; i <= Ymax; i++){
		for(int j = 0; j < nbCote; j++){
			if(coteCandidat[j].p1.y <= coteCandidat[j].p2.y){
				if(i >= coteCandidat[j].p1.y && fait[j] == 0){
					fait[j] = 1;
				}
				if(i >= coteCandidat[j].p2.y && fait[j] == 1 && fait2[j] == 0){
					coteSortant[nbMis] = j;
					fait2[j] = 1;
					nbMis++;
				}
			}
			else{
				if(i >= coteCandidat[j].p2.y && fait[j] == 0){
					fait[j] = 1;
				}
				if(i >= coteCandidat[j].p1.y && fait[j] == 1 && fait2[j] == 0){
					coteSortant[nbMis] = j;
					fait2[j] = 1;
					nbMis++;
				}
			}
		}
	}

	printf("\n Tableau LCS : ");

	for(int i = 0; i < nbCote; i++){
		printf("[%d]", coteSortant[i]);
	}
	printf("\n\n");

}

void calculeIntersec(int y0){

	/* Coté A */

	int xA1 = coteCandidat[coteEntrant[indiceEntrant]].p1.x;
	int yA1 = coteCandidat[coteEntrant[indiceEntrant]].p1.y;
	int xA2 = coteCandidat[coteEntrant[indiceEntrant]].p2.x;
	int yA2 = coteCandidat[coteEntrant[indiceEntrant]].p2.y;

	/* Coté B */

	int xB1 = coteCandidat[coteEntrant[indiceEntrant+1]].p1.x;
	int yB1 = coteCandidat[coteEntrant[indiceEntrant+1]].p1.y;
	int xB2 = coteCandidat[coteEntrant[indiceEntrant+1]].p2.x;
	int yB2 = coteCandidat[coteEntrant[indiceEntrant+1]].p2.y;


	/* Test de quel coté vas être le Xmin et le Xmax */

	if((xA1 <= xB1 && xA1 <= xB2) || (xA2 <= xB1 && xA2 <= xB2)){ /* Coté A Xmin et B Xmax */
		if(yA1 - yA2 == 0 || yB2 - yB1 == 0){ /* Cote A ou B Horizontaux */
			if(xA1 < xA2){
				Xmin = xA1;
				if(xB1 > xB2){
					Xmax = xB1;
				}
				else{
					Xmax = xB2;
				}
				return;
			}
			else{
				Xmin = xA2;
				if(xB1 > xB2){
					Xmax = xB1;
				}
				else{
					Xmax = xB2;
				}
				return;
			}
		}
		if(xA2 - xA1 == 0 && xB2 - xB1 == 0){ /* Ligne vertical A et B */
			Xmin = xA1;
			Xmax = xB1;
			return;
		}
		else if(xA2 - xA1 == 0){ /* Ligne vertical coté A */
			Xmin = xA1;
			M2 = (double)(yB2 - yB1) / (xB2 - xB1); /* Calcule du coef directeur du coté B */
			K2 = -((M2 * xB1) - yB1); 			/* Calcule de K pour l'équation [y = m*x + K] */
			Xmax = -((K2 - y0) / M2);
		}
		else if(xB2 - xB1 == 0){ /* Ligne vertical coté B */
			Xmax = xB1;
			M1 = (double)(yA2 - yA1) / (xA2 - xA1); /* Calcule du coef directeur du coté A */
			K1 = -((M1 * xA1) - yA1);			/* Calcule de K pour l'équation [y = m*x + K] */
			Xmin = -((K1 - y0) / M1);
		}
		else{
			/* Calcule des coef directeur des coté (M1 prend celui du Xmin et M2 le Xmax) */
			M1 = (double)(yA2 - yA1) / (xA2 - xA1);
			M2 = (double)(yB2 - yB1) / (xB2 - xB1);

			/* Calcule de K pour l'équation [y = m*x + K] */
			K1 = -((M1 * xA1) - yA1);
			K2 = -((M2 * xB1) - yB1);

			/* Calcule de Xmin et Xmax */
			Xmin = -((K1 - y0) / M1);
			Xmax = -((K2 - y0) / M2);
		}
	}
	else{ 	/* Coté B Xmin et A Xmax */
		if(yA1 - yA2 == 0 || yB2 - yB1 == 0){ /* Cote A ou B Horizontaux */
			if(xA1 < xA2){
				Xmin = xA1;
				if(xB1 > xB2){
					Xmax = xB1;
				}
				else{
					Xmax = xB2;
				}
				return;
			}
			else{
				Xmin = xA2;
				if(xB1 > xB2){
					Xmax = xB1;
				}
				else{
					Xmax = xB2;
				}
				return;
			}
		}
		if(xA2 - xA1 == 0 && xB2 - xB1 == 0){ /* Ligne vertical A et B */
			Xmin = xB1;
			Xmax = xA1;
			return;
		}
		else if(xA2 - xA1 == 0){ /* Ligne vertical coté A */
			Xmax = xA1;
			M1 = (double)(yB2 - yB1) / (xB2 - xB1); /* Calcule du coef directeur du coté B */
			K1 = -((M1 * xB1) - yB1); 			/* Calcule de K pour l'équation [y = m*x + K] */
			Xmin = -((K1 - y0) / M1);
		}
		else if(xB2 - xB1 == 0){ /* Ligne vertical coté B */
			Xmin = xB1;
			M2 = (double)(yA2 - yA1) / (xA2 - xA1); /* Calcule du coef directeur du coté A */
			K2 = -((M2 * xA1) - yA1);			/* Calcule de K pour l'équation [y = m*x + K] */
			Xmax = -((K1 - y0) / M1);
		}
		else{
			/* Calcule des coef directeur des coté (M1 prend celui du Xmin et M2 le Xmax) */
			M2 = (double)(yA2 - yA1) / (xA2 - xA1);
			M1 = (double)(yB2 - yB1) / (xB2 - xB1);

			/* Calcule de K pour l'équation [y = m*x + K] */
			K2 = -((M2 * xA1) - yA1);
			K1 = -((M1 * xB1) - yB1);

			/* Calcule de Xmin et Xmax */
			Xmin = -((K1 - y0) / M1);
			Xmax = -((K2 - y0) / M2);
		}
	}

}

/*
*	Remplissage
*/

void remplissageBalayage(){
	int Ymin = 2147000000;
	int Ymax = -2147000000;

	/* On cherche Ymin et Ymax */

	for(int i=0; i<nbCote; i++){
		if(coteCandidat[i].p1.y < Ymin){
			Ymin = coteCandidat[i].p1.y;
		}
		if(coteCandidat[i].p2.y < Ymin){
			Ymin = coteCandidat[i].p2.y;
		}
		if(coteCandidat[i].p1.y > Ymax){
			Ymax = coteCandidat[i].p1.y;
		}
		if(coteCandidat[i].p2.y > Ymax){
			Ymax = coteCandidat[i].p2.y;
		}
	}

	LCE(Ymin, Ymax);
	LCS(Ymin, Ymax);

	for(int y0 = Ymin; y0 < Ymax; y0++){

		/* Test si on sort d'un coté */

		if(y0 >= coteCandidat[coteEntrant[indiceEntrant]].p1.y && y0 >= coteCandidat[coteEntrant[indiceEntrant]].p2.y && y0 >= coteCandidat[coteEntrant[indiceEntrant+1]].p1.y && y0 >= coteCandidat[coteEntrant[indiceEntrant+1]].p2.y){
			indiceEntrant += 2;
		}
		else if(y0 >= coteCandidat[coteEntrant[indiceEntrant]].p1.y && y0 >= coteCandidat[coteEntrant[indiceEntrant]].p2.y){
			indiceEntrant++;
		}
		else if(y0 >= coteCandidat[coteEntrant[indiceEntrant+1]].p1.y && y0 >= coteCandidat[coteEntrant[indiceEntrant+1]].p2.y){
			indiceEntrant++;
		}

		/* Calcule de M1, M2, K1, K2, Xmin, Xmax avec y0 */

		calculeIntersec(y0);

		for(int i = Xmin; i <= Xmax; i++){
			trace_pixel(i, y0);
		}
		
	}
	for(int i = 0; i <= nbPoint; i++){
		trace_pixel(tabPoint[i].x-200, tabPoint[i].y);
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

	nbPoint = 0;
	FILE *monFichier;

	if(argc != 3){
		printf("\n\nUsage : ./Exercice2 [Fichier des Points] [TaillePixel]\n\n");
		exit(1);
	}
	else{
		taille_Pixel = atof(argv[2]); /* Setup de la taille des pixel */
		monFichier = fopen(argv[1], "r+"); /* On ouvre le fichier des points */

	    if (monFichier != NULL){
	        // On peut lire et écrire dans le fichier
	        while(fscanf(monFichier, "(%d, %d)\n", &tabPoint[nbPoint].x, &tabPoint[nbPoint].y) != EOF){
		        /*printf("\nOn a chargé le point : (%d, %d)", coteCandidat[nbCote].x, coteCandidat[nbCote].y);*/
		        nbPoint++;
		    }
		    nbPoint--;
		    LCC(); /* Construit la liste des côtés candidat */
	    }
	    else{
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