
typedef struct sommet{
	int x, y, z;
}point;

typedef struct cube{
	sommet s1;
	sommet s2;
}cube;


int contenueDansBoule(cube monCube, int Cx, int Cy, int Cz);
int pasIntersecBoule(cube monCube, int Cx, int Cy, int Cz);
