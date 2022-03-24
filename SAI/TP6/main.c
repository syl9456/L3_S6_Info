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
karbre s1, s2, intersec;
int mode = 0;

void affiche_cube(int x1, int y1, int z1, int x2, int y2, int z2){
    glBegin(GL_QUADS);
      glColor3f(1,1,1);
      //face bas
      glVertex3f(x1,y1,z2);
      glVertex3f(x2,y1,z2);
      glVertex3f(x2,y2,z1);
      glVertex3f(x1,y1,z1);

      glColor3f(0.9,0.9,0.9);
      //face dessus
      glVertex3f(x1,y2,z2);
      glVertex3f(x2,y2,z2);
      glVertex3f(x2,y2,z1);
      glVertex3f(x1,y2,z1);

      //cotés
      glColor3f(0.8,0.8,0.8);
      //1
      glVertex3f(x1,y2,z2);
      glVertex3f(x2,y2,z2);
      glVertex3f(x2,y1,z2);
      glVertex3f(x1,y1,z2);

      glColor3f(0.7,0.7,0.7);
      //2
      glVertex3f(x2,y1,z2);
      glVertex3f(x2,y2,z2);
      glVertex3f(x2,y2,z1);
      glVertex3f(x2,y1,z1);

      glColor3f(0.6,0.6,0.6);
      //3
      glVertex3f(x1,y1,z1);
      glVertex3f(x2,y1,z1);
      glVertex3f(x2,y2,z1);
      glVertex3f(x1,y2,z1);
      
      glColor3f(0.5,0.5,0.5);
      //3
      glVertex3f(x1,y2,z2);
      glVertex3f(x1,y1,z2);
      glVertex3f(x1,y1,z1);
      glVertex3f(x1,y2,z1);
    glEnd();
}

void afficherKarbre3D(karbre A){

    /* arbre vide ? */
    if (A == NULL){
        return;
    }

    switch (A->donnee)
    {
        case VIDE : break ;
        case PLEIN :
        	affiche_cube(A->c.s1.x,
        				 A->c.s1.y,
        				 A->c.s1.z,
        				 A->c.s2.x,
        				 A->c.s2.y,
        				 A->c.s2.z); 
        	break ;
        case COMPLEXE : break ;
        default : printf("Je suis la et c'est pas normal\n"); break ;
    }
  
    /* Affichage des fils*/
    for(int y = 0; y < K; y++){
    	afficherKarbre3D(A->fils[y]);
    }
}


void Animer(){
	if(sensRotation){
		angle += 0.01;
		if (angle > 360) 
			angle = 0;
		glutPostRedisplay();
	}
	else{
		angle -= 0.01;
		if (angle < 0) 
			angle = 360;
		glutPostRedisplay();
	}
	persoX = 2048 * cos(angle);
	persoZ = 2048 * sin(angle);
}

void GererClavier(unsigned char touche, int x, int y){
	printf("\n Touche : %c\n", touche);
	if(touche == 'a'){
		sensRotation = !sensRotation;
	}
	if(touche == 'z'){
		mode = !mode;
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
	glFrustum(-1, 1, -1, 1, 1, 3000);
	gluLookAt(persoX, 1024, persoZ, 1024, 1024, 1024, 0, 1, 0);
	/* Définition de la maison */
	/*maison();*/
	switch(mode){
		case 0: /* Affiche 2 sphere */
			afficherKarbre3D(s1);
			afficherKarbre3D(s2);
			break;
		case 1: /* Affiche Intersection */
			afficherKarbre3D(intersec);
			break;
		default:
			break;
	}
	glutKeyboardFunc(GererClavier);
	glutIdleFunc(Animer);
	glRotatef(angle,0,0,1);
	glFlush();
} 



int main(int argc, char *argv[]){

	/* Test des paramètres */
	if(argc != 1){
		printf("\n\tUsage : ./tp3D\n");
	}

	printf("\n\n\tL'appuie sur la touche A permet de :\n");
	printf("\t\tChanger le sens de rotation du(des) volumes\n");
	printf("\tL'appuie sur la touche Z permet de switcher entre :\n");
	printf("\t\t--> Affichez une boule de centre Ω1 et de rayon r1. Puis une boule de centre Ω2 et de rayon r2\n");
	printf("\t\t--> Déclenchez la construction de l’intersection de ces deux boules, et affichez le résultat\n\n");

	/* Initialisation de GLUT */
	glutInit(&argc, argv);

	/* Initialisation du mode d'affichage */
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);

	/* On fixe la taille et la position de la fenêtre */
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);

	/* Creation de la fenêtre */
	glutCreateWindow("TP6");
	glEnable(GL_DEPTH_TEST);

	/* On créer 2 sphère */
	s1 = boule2arbre(1024, 800, 1024, 500);
	s2 = boule2arbre(1024, 1100, 1024, 500);

	/* On créer l'intersection */
	intersec = intersection(s1, s2);

	/* On affiche */
	glutDisplayFunc(MonAffichage);

	glutMainLoop();

}