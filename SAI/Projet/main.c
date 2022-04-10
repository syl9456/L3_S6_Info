#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"
#include "vector.h"
#include "math.h"
#include "GL/gl.h"
#include "GL/glut.h"

/****************************************************************/
// angle de rotation de la direction de la caméra
float angle=0.0;

// vecteur représentant la direction de la caméra
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f,z=5.0f;

// Les états des touches. Initialisé a zéro quand aucune touche n'est pressée
float deltaAngle = 0.0f;
float deltaMove = 0;

// Une variable pour stocker la position X où la souris est cliquée.
int xOrigin = -1;

// Variables pour calculer les images par seconde
int frame;
long time, timebase;
char s[50];

// largeur et hauteur de la fenêtre
int h,w;
/***************************************************************/

void dessinerBonhommeNeige() {

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
}

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

// -----------------------------------
//             SOURIS
// -----------------------------------

void mouseButton(int button, int state, int x, int y) {

	// démarrer UN mouvement uniquement si le bouton gauche de la souris est pressé
	if (button == GLUT_LEFT_BUTTON) {

		// Lorsque le bouton est relâché
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// Etat  = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y) {

	// Si le bouton gauche est enfoncé.
	if (xOrigin >= 0) {

		// Update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// Update la Direction de la Caméra
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void changeSize(int ww, int hh) {

	h = hh;
	w = ww;
	// Empêche un diviseur par zéro, lorsque la fenêtre est trop courte
	// (On ne peut pas faire une fenêtre de largeur nulle).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// On utilise la matrice de projection
	glMatrixMode(GL_PROJECTION);

	// Reset Matrice
	glLoadIdentity();

	// Défini la fenêtre d'affichage comme étant la fenêtre entière
	glViewport(0, 0, w, h);

	// Défini la bonne perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// On retourne à la vue du modèle
	glMatrixMode(GL_MODELVIEW);
}

// -----------------------------------
//             KEYBOARD
// -----------------------------------

void processNormalKeys(unsigned char key, int xx, int yy) { 	

        if (key == 'x')
              exit(0);
} 

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.01f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.01f; break;
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}

void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	// Restaure la matrice de projection précédente
	glPopMatrix();

	// On reviens au mode d'affichage du modèle
	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection() {

	// On se met en mode Projection
	glMatrixMode(GL_PROJECTION);

	// On sauvegarde la matrice précédente qui contient les réglages pour la projection en perspective
	glPushMatrix();

	// On reset la matrice
	glLoadIdentity();

	// On définis une projection orthographique 2D
	gluOrtho2D(0, w, h, 0);

	// On reviens au mode de visualisation du modèle
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void renderScene(void) {

	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

	// on clear les buffer de couleur et de profondeur

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// On réinitialise les transformations
	glLoadIdentity();
	// On setup la caméra comme vue en TP
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

        // On déssine un sol a la hauteur 0
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

        // On déssine 36 maison 
	for(int i = -3; i < 3; i++){
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*20.0,0,j * 20.0);
			dessinerBonhommeNeige();
			glPopMatrix();
		}
	}

	// On calcule les FPS ici
	frame++;

	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"Projet SAI - FPS:%4.2f",
			frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}

        // Affiche une chaîne de caractères (fps) avec des polices bitmap
	setOrthographicProjection();

	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(5,30,0,GLUT_BITMAP_HELVETICA_18,s);
	glPopMatrix();

	restorePerspectiveProjection();


	glutSwapBuffers();
}


// -----------------------------------
//             MAIN
// -----------------------------------


int main(int argc, char **argv) {

	// Initialise GLUT et créer la fenêtre
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(700,700);
	glutCreateWindow("Projet SAI");

	// On enregistre les callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// Gestion du clavier
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// Gestion de la souris
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL initialisation
	glEnable(GL_DEPTH_TEST);

	// On entre dans le cycle de traitement des événements GLUT
	glutMainLoop();

	return 1;
}