#include "GL/gl.h"
#include "GL/glut.h"


/*
*	FONCTION D'AFFICHAGE
*/

void Affichage(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 100, 0, 100, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_POINTS);
	// définition des points
	// ...
	glEnd();
	glFlush();
}


int main(int argc, char *argv[]){
	
	/* Initialisation de GLUT */
	glutInit(&argc, argv);

	/* Initialisation du mode d'affichage */
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	/* On fixe la taille et la position de la fenêtre */
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);

	/* Creation de la fenêtre */
	glutCreateWindow("Exercice 1");

	/* On affiche */
	glutDisplayFunc(Affichage);

	glutMainLoop();


	return 0;
}