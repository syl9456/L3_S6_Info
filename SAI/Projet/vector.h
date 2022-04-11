#ifndef VECTOR_H
#define VECTOR_H

typedef struct vec{
	float data[1][4];
}vec;

typedef struct matrice{
	float data[4][4];
}matrice;

matrice multiMatrice(matrice mat1, matrice mat2);

vec rotationZ(vec v, float angle);

vec rotationY(vec v, float angle);

#endif 