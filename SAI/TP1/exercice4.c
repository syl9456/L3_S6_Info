
#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>


/*
*	Primitive de trace_picel(x,y)
*/

float taille_Pixel;
int monX1, monY1, monX2, monY2, typeBress;

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

void bressenhamElementaire(int x1, int y1, int x2, int y2){
	int X;
	int Y = y1;
	float m = (y2-y1)/(x2-x1);
	float erreur;
	for(X = x1; X <= x2; X++){
		trace_pixel(X, Y);
		erreur += m;
		if(erreur >= 0.5){
			Y++;
			erreur -= 1;
		}
	}
}


void bressenhamEntier(int x1, int y1, int x2, int y2){
	int Y = y1;
	int X;
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	int erreur = -deltaX;


	if(deltaX != 0){
		if(deltaX > 0){
			if(deltaY != 0){
				if(deltaY > 0){
					if(deltaX >= deltaY){ 				/* 1er Octant */
						for(X = x1; X <= x2; X++){
							trace_pixel(X, Y);
							erreur += 2 * deltaY;
							if(erreur >= 0){
								Y++;
								erreur -= 2 * deltaX;
							}
						}
					}
					else{								/* 2em Octant */
						X = x1;
						for(Y = y1; Y <= y2; Y++){
							trace_pixel(X, Y);
							erreur += 2 * deltaX;
							if(erreur >= 0){
								X++;
								erreur -= 2 * deltaY;
							}
						}
					}
				}
				else{
					if(deltaX >= -deltaY){ 				/* 8em Octant */
						for(X = x1; X <= x2; X++){
							trace_pixel(X, -Y);
							erreur += 2 * -deltaY;
							if(erreur >= 0){
								Y++;
								erreur -= 2 * deltaX;
							}
						}
					}
					else{ 								/* 7em Octant */
						X = x1;
						for(Y = y1; Y >= y2; Y--){
							trace_pixel(X, Y);
							erreur += 2 * deltaX;
							if(erreur >= 0){
								X++;
								erreur -= 2 * -deltaY;
							}
						}
					}
				}
			}
			else{ 										/* Vecteur horizontal de gauche a droite */
				for(X = x1; X <= x2; X++){
					trace_pixel(X, Y);
				}
			}
		}
		else{
			if(deltaY != 0){
				if(deltaY > 0){
					if(-deltaX >= deltaY){				/* 4em Octant */
						for(X = x1; X >= x2; X--){
							trace_pixel(X, Y);
							erreur += 2 * deltaY;
							if(erreur >= 0){
								Y++;
								erreur -= 2 * -deltaX;
							}
						}
					}
					else{ 								/* 3em Octant */
						X = x1;
						for(Y = y1; Y <= y2; Y++){
							trace_pixel(-X, Y);
							erreur += 2 * -deltaX;
							if(erreur >= 0){
								X++;
								erreur -= 2 * deltaY;
							}
						}
					}
				}
				else{ 									/* 5em Octant */
					if(deltaX <= deltaY){
						for(X = x1; X >= x2; X--){
							trace_pixel(X, Y);
							erreur += 2 * -deltaY;
							if(erreur >= 0){
								Y--;
								erreur -= 2 * -deltaX;
							}
						}
					}
					else{								/* 6em Octant */
						X = x1;
						for(Y = y1; Y >= y2; Y--){
							trace_pixel(X, Y);
							erreur += 2 * -deltaX;
							if(erreur >= 0){
								X--;
								erreur -= 2 * -deltaY;
							}
						}
					}
				}
			}
			else{ 										/* Vecteur horizontal de droite a gauche */
				for(X = x1; X >= x2; X--){
					trace_pixel(X, Y);
				}
			}
		}
	}
	else{
		if(deltaY != 0){
			if(deltaY > 0){ 							/* Vecteur vertical de bas en haut */
				X = x1;
				for(Y = y1; Y <= y2; Y++){
					trace_pixel(X, Y);
				}
			}
			else{										/* Vecteur vertical de haut en bas */
				X = x1;
				for(Y = y1; Y >= y2; Y--){
					trace_pixel(X, Y);
				}
			}
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
	if(typeBress == 1){
		bressenhamElementaire(monX1, monY1, monX2, monY2);
	}
	else if(typeBress == 2){
		bressenhamEntier(monX1, monY1, monX2, monY2);
	}
	glFlush();
}


int main(int argc, char *argv[]){

	if(argc != 7){
		printf("\n\nUsage : ./Exercice4 [x1] [y1] [x2] [y2] [TaillePixel] [1 = bressenhamElementaire || 2 = bressenhamEntier]\n\n");
		exit(1);
	}
	else{
		taille_Pixel = atof(argv[5]);
		monX1 = atoi(argv[1]);
		monY1 = atoi(argv[2]);
		monX2 = atoi(argv[3]);
		monY2 = atoi(argv[4]);
		typeBress = atoi(argv[6]);
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