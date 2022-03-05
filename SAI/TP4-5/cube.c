#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "cube.h"

int cubeContenueDansBoule(cube c, int Cx, int Cy, int Cz, int r){
	/* On test si les 2 sommets extrémité du cube sont dans la sphère (Si c'est le cas, les 6 autres le seront car c'est un cube) */
	if((pow(c.s1.x + Cx, 2))+(pow(c.s1.y + Cy, 2))+(pow(c.s1.z + Cz, 2)) < pow(r, 2)){ /* Sommet 1 */
		if((pow(c.s2.x + Cx, 2))+(pow(c.s2.y + Cy, 2))+(pow(c.s2.z + Cz, 2)) < pow(r, 2)){ /* Sommet 2 */
			return 1;
		}
	}
	return 0;
}

int cubePasContientBoule(cube c, int Cx, int Cy, int Cz, int r){
	/* On test si les 2 sommets du cube sont en dehors de la sphère */
	if(c.s1.x > Cx+r || c.s1.y > Cy+r || c.s1.z > Cz+r || c.s2.x < Cx-r || c.s2.y < Cy-r || c.s2.z < Cz-r){
		return 1;
	}
	return 0;
}

