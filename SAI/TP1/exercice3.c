#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>


/*
*	Primitive de trace_picel(x,y)
*/

float taille_Pixel;
int monX1, monY1, monX2, monY2;

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

void tracerSegment(int x1, int y1, int x2, int y2){
	float X, Y;
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	float m = deltaY/deltaX;
	if(deltaX>deltaY){
		Y = y1;
		for(X = x1; X <= x2; X++){
			trace_pixel(X, Y);
			Y += m;
		}
	}
	else{
		X = x1;
		for(Y = y1; Y <= y2; Y++){
			trace_pixel(X, Y);
			X += (1/m);
		}
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
	tracerSegment(monX1, monY1, monX2, monY2);
	glFlush();
}


int main(int argc, char *argv[]){

	if(argc != 6){
		printf("\n\nUsage : ./Exercice3 [x1] [y1] [x2] [y2] [TaillePixel]\n\n");
		exit(1);
	}
	else{
		taille_Pixel = atof(argv[5]);
		monX1 = atoi(argv[1]);
		monY1 = atoi(argv[2]);
		monX2 = atoi(argv[3]);
		monY2 = atoi(argv[4]);
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