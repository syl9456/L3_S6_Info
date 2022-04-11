#include <stdio.h>
#include <math.h>
#include "vector.h"


matrice multiMatrice(matrice mat1, matrice mat2){
	matrice result;
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 3; j++){
			result.data[i][j] = 0;
			for(int k = 0; k <= 3; k++){
				result.data[i][j] = result.data[i][j] + (mat1.data[i][k] * mat2.data[k][j]);
			}
		}
	}
	return result;
}

vec rotationZ(vec v, float angle){
	vec result;
	result.data[0][0] = (cos(angle) * v.data[0][0]) - (sin(angle) * v.data[0][1]);
	result.data[0][1] = (sin(angle) * v.data[0][0]) + (cos(angle) * v.data[0][1]);
	result.data[0][2] = v.data[0][2];
	result.data[0][3] = 1;
	return result;
}

vec rotationY(vec v, float angle){
	vec result;
	result.data[0][0] = (cos(angle) * v.data[0][0]) + (sin(angle) * v.data[0][2]);
	result.data[0][1] = v.data[0][1];
	result.data[0][2] = (-sin(angle) * v.data[0][0]) + (cos(angle) * v.data[0][2]);
	result.data[0][3] = 1;
	return result;
}

