#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"
#include "math.h"
#include "formes.h"
#include "GL/gl.h"
#include "GL/glut.h"

/****************************************************************/
// angle de rotation de la direction de la caméra
float angleXZ=0.0f;
float angleY=0.0f;

// vecteur représentant la direction de la caméra
float lx=0.0f, ly = 1.0f, lz=-1.0f;

// XZ position of the camera
float x=0.0f, y=1.0f, z=5.0f;

// Les états des touches. Initialisé a zéro quand aucune touche n'est pressée
float deltaAngleXZ = 0.0f;
float deltaAngleY = 0.0f;
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


void stringFpsToBitmap(
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

void bouttonSouris(int button, int state, int x, int y) {

	// démarrer UN mouvement uniquement si le bouton gauche de la souris est pressé
	/*if (button == GLUT_LEFT_BUTTON) {

		// Lorsque le bouton est relâché
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// Etat  = GLUT_DOWN
			xOrigin = x;
		}
	}*/
}

void mouvementSouris(int x, int y) {

	// Si le bouton gauche est enfoncé.
	/*if (xOrigin >= 0) {

		// Update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// Update la Direction de la Caméra
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}*/
}

void changementTaille(int ww, int hh) {

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

void appuieLettreClavier(unsigned char key, int xx, int yy) { 	

	switch(key){
		case 'x' :
			exit(0);
			break;
		case 'z' :
			deltaMove = 0.5f;
			break;
		case 's' :
			deltaMove = -0.5f;
			break;
	}
       
} 

void appuieToucheClavier(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : 
			deltaAngleXZ = -0.02f; 
			angleXZ += deltaAngleXZ; 
			break;
		case GLUT_KEY_RIGHT :
			deltaAngleXZ = 0.02f; 
			angleXZ += deltaAngleXZ; 
			break;
		case GLUT_KEY_UP : 
			deltaAngleY = 0.02f; 
			angleY += deltaAngleY; 
			break;
		case GLUT_KEY_DOWN : 
			deltaAngleY = -0.02f; 
			angleY += deltaAngleY; 
			break;
	}
}

void relachementToucheClavier(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngleXZ = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaAngleY = 0.0f;break;
		case 122 : deltaMove = 0.0f; break;
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

void calculPosCamera(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void calculDirCamera() {

	lx = cos(angleXZ) * cos(angleY);
	ly = sin(angleY);
	lz = sin(angleXZ) * cos(angleY);
}

void construireMonde(void) {

	if (deltaMove)
		calculPosCamera(deltaMove);
	if (deltaAngleXZ || deltaAngleY)
		calculDirCamera();

	// on clear les buffer de couleur et de profondeur

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// On réinitialise les transformations
	glLoadIdentity();
	// On setup la caméra comme vue en TP
	gluLookAt(	x, 1.0f, z,
			x+lx, y+ly,  z+lz,
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
			dessinerMaison();
			glPopMatrix();
		}
	}

	for(int i = -3; i < 3; i++){
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*30.0,0,j * 30.0);
			dessinerArbre(2, 7);
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
	stringFpsToBitmap(5,30,0,GLUT_BITMAP_HELVETICA_18,s);
	glPopMatrix();

	restorePerspectiveProjection();


	glutSwapBuffers();
}


// -----------------------------------
//             MAIN
// -----------------------------------


int main(int argc, char *argv[]) {

	// Initialise GLUT et créer la fenêtre
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(700,700);
	glutCreateWindow("Projet SAI");

	// On enregistre les callbacks
	glutDisplayFunc(construireMonde);
	glutReshapeFunc(changementTaille);
	glutIdleFunc(construireMonde);

	// Gestion du clavier
	//glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(appuieLettreClavier);
	glutSpecialFunc(appuieToucheClavier);
	glutSpecialUpFunc(relachementToucheClavier);

	// Gestion de la souris
	glutMouseFunc(bouttonSouris);
	glutMotionFunc(mouvementSouris);

	// OpenGL initialisation
	glEnable(GL_DEPTH_TEST);

	// On entre dans le cycle de traitement des événements GLUT
	glutMainLoop();

	return 1;
}