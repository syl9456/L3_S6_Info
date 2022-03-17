#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"
#include "math.h"
#include "GL/gl.h"
#include "GL/glut.h"

int sensRotation = 1;
float angle = 0;
float persoX, persoZ;


void affiche_cube(int x1, int y1, int z1, int x2, int y2, int z2){
	glBegin(GL_QUADS);
		/* Base du cube */
		glColor3f(0.9, 0.9, 0.9);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y1, z2);
		glVertex3f(x2, y1, z2);
		glVertex3f(x2, y1, z1);
		/* coté gauche du cube */
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y2, z1);
		glVertex3f(x1, y2, z2);
		glVertex3f(x2, y1, z2);
		/* coté droit du cube  */
		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(x2, y1, z1);
		glVertex3f(x2, y2, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y1, z2);
		/* coté avant du cube  */
		glColor3f(0.6, 0.6, 0.6);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y2, z1);
		glVertex3f(x2, y2, z1);
		glVertex3f(x2, y1, z1);
		/* coté arriere du cube  */
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(x1, y1, z2);
		glVertex3f(x1, y2, z2);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y1, z2);
		/* coté au dessus du cube  */
		glColor3f(0.4, 0.4, 0.4);
		glVertex3f(x1, y2, z1);
		glVertex3f(x1, y2, z2);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y2, z1);
	glEnd();
}

void Animer(){
	if(sensRotation){
		angle += 0.0001;
		if (angle > 360) 
			angle = 0;
		glutPostRedisplay();
	}
	else{
		angle -= 0.0001;
		if (angle < 0) 
			angle = 360;
		glutPostRedisplay();
	}
	persoX = 15 * cos(angle);
	persoZ = 15 * sin(angle);
}

void GererClavier(unsigned char touche, int x, int y){
	printf("\n Touche : %c\n", touche);
	if(touche == 'a'){
		sensRotation = !sensRotation;
	}
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
	glFrustum(-1, 1, -1, 1, 5, 100);
	gluLookAt(persoX, 5, persoZ, 0, 0, 0, 0, 1, 0);
	/* Définition de la maison */
	/*maison();*/
	affiche_cube(-2, -2, -2, 2, 2, 2);
	glutKeyboardFunc(GererClavier);
	glutIdleFunc(Animer);
	glRotatef(angle,0,0,1);
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
	glutCreateWindow("Maison");
	glEnable(GL_DEPTH_TEST);

	/* On affiche */
	glutDisplayFunc(MonAffichage);

	glutMainLoop();

}