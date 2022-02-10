#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>


/*
*	Primitive de trace_picel(x,y)
*/

float taille_Pixel;
int monX1, monY1, monR;

void trace_pixel(int x, int y){
	glBegin(GL_QUADS);
		glVertex2f(x-0.5, y-0.5);
		glVertex2f(x-0.5, y+0.5);
		glVertex2f(x+0.5, y+0.5);
		glVertex2f(x+0.5, y-0.5);
	glEnd();
}


/*
*	TRACER SEGMENT
*/

void cercleBressenham(int x1, int y1, int r){
	int X = 0;
	int Y = r;
	float d = (5/4) - r;
	trace_pixel(Y+x1, X+y1);
	trace_pixel(-Y+x1, -X+y1);
	trace_pixel(-X+x1, -Y+y1);
	trace_pixel(X+x1, Y+y1);
	while(Y > X){
		if(d < 0){
			d += (2*X) + 5;
		}
		else{
			d += (2*X) - (2*Y) + 5;
			Y--;
		}
		X++;
		trace_pixel(X+x1, Y+y1); 		/* Octant 2 */
		trace_pixel(Y+x1, X+y1); 		/* Octant 1 */
		trace_pixel(-X+x1, Y+y1);     	/* Octant 3 */
		trace_pixel(-Y+x1, X+y1); 		/* Octant 4 */
		trace_pixel(X+x1, -Y+y1);		/* Octant 5 */
		trace_pixel(Y+x1, -X+y1);		/* Octant 6 */
		trace_pixel(-X+x1, -Y+y1);		/* Octant 7 */
		trace_pixel(-Y+x1, -X+y1);		/* Octant 8 */
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
	cercleBressenham(monX1, monY1, monR);
	glFlush();
}


int main(int argc, char *argv[]){

	if(argc != 5){
		printf("\n\nUsage : ./Exercice1 [x1] [y1] [RayonCercle] [TaillePixel]\n\n");
		exit(1);
	}
	else{
		taille_Pixel = atof(argv[4]);
		monX1 = atoi(argv[1]);
		monY1 = atoi(argv[2]);
		monR = atoi(argv[3]);
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