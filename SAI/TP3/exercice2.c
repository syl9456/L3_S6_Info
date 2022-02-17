#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>
#include <math.h>

/* Structure */

typedef struct point{
	float donnee[1][3];
}point;

typedef struct matrice{
	float donnee[3][3];
}matrice;

/* Variables */

float taille_Pixel;
point A; 
point B; 
point C; 
point D;
matrice S;
matrice R;
matrice T;

/*
*	Primitive de trace_picel(x,y)
*/

void trace_pixel(int x, int y){
	glBegin(GL_QUADS);
		glVertex2f(x-0.5, y-0.5);
		glVertex2f(x-0.5, y+0.5);
		glVertex2f(x+0.5, y+0.5);
		glVertex2f(x+0.5, y-0.5);
	glEnd();
}

/*
*	Fonction qui calcule le produit entre 2 matrices
*/
matrice multiMatrice(matrice mat1, matrice mat2){
	matrice result;
	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			result.donnee[i][j] = 0;
			for(int k = 0; k <= 2; i++){
				result.donnee[i][j] = result.donnee[i][j] + (mat1.donnee[i][k] * mat2.donnee[k][j]);
			}
		}
	}
	return result;
}

/*
*	Fonction qui calcule le produit entre 2 matrices
*/
point multiMatricePoint(matrice m, point p){
	point result;
	for(int i = 0; i <= 0; i++){
		for(int j = 0; j <= 2; j++){
			result.donnee[i][j] = 0;
			for(int k = 0; k <= 2; i++){
				result.donnee[i][j] = result.donnee[i][j] + (p.donnee[i][k] * m.donnee[k][j]);
			}
		}
	}
	return result;
}

/*
	Fonction qui donne la matrice S associée a un changement d’échelle 
	par rapport a l’origine d’un facteur 2 selon l’axe Ox et 3 selon 
	l’axe Oy
	---------
	| 3 0 0 |
	| 0 2 0 |
	| 0 0 1 |
	---------
*/
matrice genereS(){
	matrice m;
	m.donnee[0][0] = 3;
	m.donnee[0][1] = 0;
	m.donnee[0][2] = 0;
	m.donnee[1][0] = 0;
	m.donnee[1][1] = 2;
	m.donnee[1][2] = 0;
	m.donnee[2][0] = 0;
	m.donnee[2][1] = 0;
	m.donnee[2][2] = 1;
	return m;
}

/*
	Fonction qui donne la matrice R associée a une rotation d’un angle π/3 
	par rapport au point 
		 -----
	O′ = | 2 |
		 | 1 |
		 -----
*/
matrice genereR(){
	matrice m;
	m.donnee[0][0] = 0.5;
	m.donnee[0][1] = sqrt(3)/2;
	m.donnee[0][2] = 0;
	m.donnee[1][0] = sqrt(3)/2;
	m.donnee[1][1] = 0.5;
	m.donnee[1][2] = 0;
	m.donnee[2][0] = 1 - (sqrt(3)/2);
	m.donnee[2][1] = 0.5 - sqrt(3);
	m.donnee[2][2] = 1;
	return m;
}

/*														 
	Fonction qui donne la matrice T associée a une 		 ------
	translation de vecteur t 							 | -3 |
	----------											 | -1 |
	| 1 0 -3 |											 ------
	| 0 1 -1 |
	| 0 0  1 |
	----------
*/
matrice genereT(){
	matrice m;
	m.donnee[0][0] = 1;
	m.donnee[0][1] = 0;
	m.donnee[0][2] = 0;
	m.donnee[1][0] = 0;
	m.donnee[1][1] = 1;
	m.donnee[1][2] = 0;
	m.donnee[2][0] = -3;
	m.donnee[2][1] = -1;
	m.donnee[2][2] = 1;
	return m;
}

/*														
	Fonction qui génère un point a partir des coordonées 
	donné en paramètre
*/

point generePoint(int x, int y){
	point p;
	p.donnee[0][0] = x;
	p.donnee[0][1] = y;
	p.donnee[0][2] = 1;
	return p;
}

void Affichage(){
	int i = 0;
	point A1 = A;
	point B1 = B;
	point C1 = C;
	point D1 = D;

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5/taille_Pixel, 5/taille_Pixel, -5/taille_Pixel, 5/taille_Pixel, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* Dessin */
	glBegin(GL_POLYGON);
		glVertex2f(A1.donnee[0][0], A1.donnee[0][1]);
		glVertex2f(B1.donnee[0][0], B1.donnee[0][1]);
		glVertex2f(C1.donnee[0][0], C1.donnee[0][1]);
		glVertex2f(D1.donnee[0][0], D1.donnee[0][1]);
	glEnd();
	glFlush();
}


int main(int argc, char *argv[]){

	if(argc != 2){
		printf("\n\nUsage : ./Exercice2 [TaillePixel]\n\n");
		exit(1);
	}
	else{
		taille_Pixel = atof(argv[1]);
	}

	S = genereS();
	R = genereR();
	T = genereT();
	A = generePoint(-1, -1);
	B = generePoint(3, 0);
	C = generePoint(1, 2);
	D = generePoint(-1, 3);

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
	
}
