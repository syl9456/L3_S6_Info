#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void dessinerMaison() {

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


void dessinerArbre(int epaisseur ,int taille){
  glBegin(GL_QUADS);
                /* Base de l'arbre*/
	        glColor3f(0.35, 0.23, 0.06);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, epaisseur);
		glVertex3f(epaisseur, 0, epaisseur);
		glVertex3f(epaisseur, 0, 0);
		/* mur devant */
		glVertex3f(0, 0, 0);
		glVertex3f(0, taille, 0);
		glVertex3f(epaisseur, taille, 0);
		glVertex3f(epaisseur, 0, 0);
		/* mur gauche */
		glVertex3f(0, 0, 0);
		glVertex3f(0, taille, 0);
		glVertex3f(0, taille, epaisseur);
		glVertex3f(0, 0, epaisseur);
		/* mur droit */
		glVertex3f(epaisseur, 0, 0);
		glVertex3f(epaisseur, taille, 0);
		glVertex3f(epaisseur, taille, epaisseur);
		glVertex3f(epaisseur, 0, epaisseur);
		/* mur derriere */
		glVertex3f(0, 0, epaisseur);
		glVertex3f(0, taille, epaisseur);
		glVertex3f(epaisseur, taille, epaisseur);
		glVertex3f(epaisseur, 0, epaisseur);
   glEnd();
   glColor3f(0,0.5,0);
   glTranslatef(1,taille-2,0);
   glutSolidSphere(3.0f,20,20);
   glTranslatef(0,-(taille-2),0);
}


void dessinerescalier(float epaisseur,float taille, int nbmarches){
  int i =0;
  //boucle pour escalier
    for(i = 0; i<nbmarches;i++){
		glBegin(GL_QUADS);
                /* Base de la marche*/
	        glColor3f(0.8, 0.8, 0.8);
		glVertex3f(0,0.1,0);
		glVertex3f(taille,0.1,0);
		glVertex3f(taille,0.1,epaisseur);
		glVertex3f(0, 0.1, epaisseur);
		/*haut de la marche*/
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(0,epaisseur,0);
		glVertex3f(taille,epaisseur,0);
		glVertex3f(taille,epaisseur,epaisseur);
		glVertex3f(0,epaisseur, epaisseur);
		/* mur devant */
		glVertex3f(0, 0, 0);
		glVertex3f(0,epaisseur, 0);
		glVertex3f(taille,epaisseur, 0);
		glVertex3f(taille, 0, 0);
		/* mur gauche */
		glVertex3f(0, 0, 0);
		glVertex3f(0, epaisseur, 0);
		glVertex3f(0, epaisseur, epaisseur);
		glVertex3f(0, 0, epaisseur);
		/* mur droit */
		glVertex3f(taille, 0, 0);
		glVertex3f(taille, epaisseur, 0);
		glVertex3f(taille, epaisseur, epaisseur);
		glVertex3f(taille, 0, epaisseur);
		/* mur derriere */
		glVertex3f(0, 0, epaisseur);
		glVertex3f(0,epaisseur, epaisseur);
		glVertex3f(taille,epaisseur, epaisseur);
		glVertex3f(taille, 0, epaisseur);
		glEnd();
		glTranslatef(0,epaisseur,epaisseur);
  }
}

