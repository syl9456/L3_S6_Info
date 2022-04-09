#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"
#include "math.h"
#include "GL/gl.h"
#include "GL/glut.h"

/***** Variables de la caméra *****/
int camX = 10;
int camY = 10;
int camZ = -20;
int lookX = 10;
int lookY = 10;
int lookZ = 10;
int upX = 0;
int upY = 1;
int upZ = 0;
int camSpeed = 1;
/***********************************/




void GererClavier(unsigned char touche, int x, int y){
	printf("\n Touche : %c\n", touche);
	/* AVANCER */
	if(touche == 'z'){ 
		camX += camSpeed * lookX;
		camY += camSpeed * lookY;
		camZ += camSpeed * lookZ;
		printf("%d %d %d\n", camX, camY, camZ);
	}
	/* RECULER */
	if(touche == 'q'){ 

	}
	/* GAUCHE */
	if(touche == 's'){ 
		camX += camSpeed * -lookX;
		camY += camSpeed * -lookY;
		camZ += camSpeed * -lookZ;
		printf("%d %d %d\n", camX, camY, camZ);
	}
	/* DROITE */
	if(touche == 'd'){ 

	}
}

void MouvementSouris(int x, int y){

	
}


void maison(){
	glBegin(GL_QUADS);
		/* Base de la maison */
		glColor3f(0.9, 0.9, 0.9);
		glVertex3f(0-5, 0-5, 0-5);
		glVertex3f(0-5, 0-5, 10-5);
		glVertex3f(10-5, 0-5, 10-5);
		glVertex3f(10-5, 0-5, 0-5);
		/* mur devant */
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(0-5, 0-5, 0-5);
		glVertex3f(0-5, 10-5, 0-5);
		glVertex3f(10-5, 10-5, 0-5);
		glVertex3f(10-5, 0-5, 0-5);
		/* mur gauche */
		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(0-5, 0-5, 0-5);
		glVertex3f(0-5, 10-5, 0-5);
		glVertex3f(0-5, 10-5, 10-5);
		glVertex3f(0-5, 0-5, 10-5);
		/* mur droit */
		glColor3f(0.6, 0.6, 0.6);
		glVertex3f(10-5, 0-5, 0-5);
		glVertex3f(10-5, 10-5, 0-5);
		glVertex3f(10-5, 10-5, 10-5);
		glVertex3f(10-5, 0-5, 10-5);
		/* mur derriere */
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(0-5, 0-5, 10-5);
		glVertex3f(0-5, 10-5, 10-5);
		glVertex3f(10-5, 10-5, 10-5);
		glVertex3f(10-5, 0-5, 10-5);
		/* toiture droite */
		glColor3f(0, 0.2, 0.5);
		glVertex3f(10-5, 10-5, 0-5);
		glVertex3f(5-5, 15-5, 0-5);
		glVertex3f(5-5, 15-5, 10-5);
		glVertex3f(10-5, 10-5, 10-5);
		/* toiture gauche */
		glColor3f(0, 0.2, 0.5);
		glVertex3f(0-5, 10-5, 0-5);
		glVertex3f(5-5, 15-5, 0-5);
		glVertex3f(5-5, 15-5, 10-5);
		glVertex3f(0-5, 10-5, 10-5);
	glEnd();
	glBegin(GL_TRIANGLES);
		/* toiture avant */
		glColor3f(0.1, 0.3, 0.32);
		glVertex3f(0-5, 10-5, 0-5);
		glVertex3f(5-5, 15-5, 0-5);
		glVertex3f(10-5, 10-5, 0-5);
		/* toiture arriere */
		glColor3f(0.1, 0.3, 0.32);
		glVertex3f(0-5, 10-5, 10-5);
		glVertex3f(5-5, 15-5, 10-5);
		glVertex3f(10-5, 10-5, 10-5);
	glEnd();
}


void MonAffichage(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 10000);
	gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, upX, upY, upZ);
	/* Définition de la maison */
	maison();
	glutKeyboardFunc(GererClavier);
	glutMotionFunc(MouvementSouris);
	glFlush();
} 



int main(int argc, char *argv[]){

	/* Initialisation de GLUT */
	glutInit(&argc, argv);

	/* Initialisation du mode d'affichage */
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);

	/* On fixe la taille et la position de la fenêtre */
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);

	/* Creation de la fenêtre */
	glutCreateWindow("Projet");
	glEnable(GL_DEPTH_TEST);

	

	/* On affiche */
	glutDisplayFunc(MonAffichage);

	glutMainLoop();

}