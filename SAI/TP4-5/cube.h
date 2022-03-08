#ifndef CUBE_H
#define CUBE_H

#define PROFMAX 4

typedef struct sommet{
	int x, y, z;
}sommet;

typedef struct cube{
	sommet s1;
	sommet s2;
}cube;


int cubeContenueDansBoule(cube c, int Cx, int Cy, int Cz, int r);
int cubePasContientBoule(cube c, int Cx, int Cy, int Cz, int r);

#endif
