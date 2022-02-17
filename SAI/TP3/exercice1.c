#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>

/* Structure */

typedef struct point{
	float donnee[1][3];
}point;

typedef struct matrice{
	float donnee[3][3];
}matrice;


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


int main(int argc, char *argv[]){

	return 1;

}