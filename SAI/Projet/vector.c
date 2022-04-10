
#include <stdio.h>
#include <math.h>
#include "vector.h"


matrice multiMatrice(matrice mat1, matrice mat2){
	matrice result;
	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			result.data[i][j] = 0;
			for(int k = 0; k <= 2; k++){
				result.data[i][j] = result.data[i][j] + (mat1.data[i][k] * mat2.data[k][j]);
			}
		}
	}
	return result;
}

vec multiMatriceVector(matrice m, vec v){
	vec result;
	result.data[0][0] = (m.data[0][0] * v.data[0][0]) + (m.data[1][0] * v.data[0][1]) + (m.data[2][0] * v.data[0][2]);
	result.data[0][1] = (m.data[0][1] * v.data[0][0]) + (m.data[1][1] * v.data[0][1]) + (m.data[2][1] * v.data[0][2]);
	result.data[0][2] = (m.data[0][2] * v.data[0][0]) + (m.data[1][2] * v.data[0][1]) + (m.data[2][2] * v.data[0][2]);
	return result;
}

vec multiVectorVector(vec v1, vec v2){
	vec result;
	result.data[0][0] = (v1.data[0][1] * v2.data[0][2]) - (v1.data[0][2] * v2.data[0][1]);
	result.data[0][1] = (v1.data[0][1] * v2.data[0][0]) - (v1.data[0][0] * v2.data[0][2]);
	result.data[0][2] = (v1.data[0][0] * v2.data[0][1]) - (v1.data[0][1] * v2.data[0][0]);
	return result;
}

vec addVectorVector(vec v1, vec v2){
	vec result;
	result.data[0][0] = v1.data[0][0] + v2.data[0][0];
	result.data[0][0] = v1.data[0][1] + v2.data[0][1];
	result.data[0][0] = v1.data[0][2] + v2.data[0][2];
	return result;
}

vec subVectorVector(vec v1, vec v2){
	vec result;
	result.data[0][0] = v1.data[0][0] - v2.data[0][0];
	result.data[0][0] = v1.data[0][1] - v2.data[0][1];
	result.data[0][0] = v1.data[0][2] - v2.data[0][2];
	return result;
}

vec multiVarVector(int n, vec v){
	vec result;
	result.data[0][0] = v.data[0][0] * n;
	result.data[0][1] = v.data[0][1] * n;
	result.data[0][2] = v.data[0][2] * n;
	return result;
}

