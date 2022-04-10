#ifndef VECTOR_H
#define VECTOR_H
 
typedef struct vec{
	int data[1][3];
}vec;

typedef struct matrice{
	int data[3][3];
}matrice;

matrice multiMatrice(matrice mat1, matrice mat2);

vec multiMatriceVector(matrice m, vec v);

vec multiVectorVector(vec v1, vec v2);

vec addVectorVector(vec v1, vec v2);

vec subVectorVector(vec v1, vec v2);

vec multiVarVector(int n, vec v);
 
#endif