#include "GL/gl.h"
#include "GL/glut.h"


/*
*	Primitive de trace_picel(x,y)
*/

float taille_Pixel;

void trace_pixel(int x, int y){
	glBegin(GL_QUADS);
		glVertex2i(x-0.5, y-0.5);
		glVertex2i(x-0.5, y+0.5);
		glVertex2i(x+0.5, y+0.5);
		glVertex2i(x+0.5, y-0.5);
	glEnd();
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
	trace_pixel(0, 0);
	trace_pixel(-1, -1);
	trace_pixel(-2, -2);
	trace_pixel(-3, -3);
	trace_pixel(1, 1);
	trace_pixel(2, 2);
	trace_pixel(3, 3);
	trace_pixel(4, 4);
	trace_pixel(5, 5);
	trace_pixel(-4, -4);
	trace_pixel(-5, -5);
	glFlush();
}


int main(int argc, char *argv[]){

	if(argc == 1){
		taille_Pixel = 1;
	}
	else{
		taille_Pixel = atof(argv[1]);
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