#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "cube.h"

int cubeContenueDansBoule(cube c, int Cx, int Cy, int Cz, int r){
	/* On test si les 8 sommets extrémité du cube sont dans la sphère */
	if((pow(c.s1.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) < pow(r, 2)){ /* Sommet 1 */
		if((pow(c.s2.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) < pow(r, 2)){ /* Sommet 2 */
			if((pow(c.s2.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) < pow(r, 2)){ /* Sommet 3 */
				if((pow(c.s2.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) < pow(r, 2)){ /* Sommet 4 */
					if((pow(c.s1.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) < pow(r, 2)){ /* Sommet 5 */
						if((pow(c.s2.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) < pow(r, 2)){ /* Sommet 6 */
							if((pow(c.s1.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) < pow(r, 2)){ /* Sommet 7 */
								if((pow(c.s1.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) < pow(r, 2)){ /* Sommet 8 */
									return 1;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}


int cubePasContientBoule(cube c, int Cx, int Cy, int Cz, int r){
	/* On test si les 8 sommets extrémité du cube sont en dehors de la sphère */
	if((pow(c.s1.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) > pow(r, 2)){ /* Sommet 1 */
		if((pow(c.s2.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) > pow(r, 2)){ /* Sommet 2 */
			if((pow(c.s2.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) > pow(r, 2)){ /* Sommet 3 */
				if((pow(c.s2.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) > pow(r, 2)){ /* Sommet 4 */
					if((pow(c.s1.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s1.z - Cz, 2)) > pow(r, 2)){ /* Sommet 5 */
						if((pow(c.s2.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) > pow(r, 2)){ /* Sommet 6 */
							if((pow(c.s1.x - Cx, 2))+(pow(c.s1.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) > pow(r, 2)){ /* Sommet 7 */
								if((pow(c.s1.x - Cx, 2))+(pow(c.s2.y - Cy, 2))+(pow(c.s2.z - Cz, 2)) > pow(r, 2)){ /* Sommet 8 */
									/* On test si c'est pas dans le cube */
									if(Cx < c.s1.x - r || Cy < c.s1.y - r || Cz < c.s1.z - r || Cx > c.s2.x + r || Cy > c.s2.y + r || Cz > c.s2.z + r){
										return 1;
									}
									else{
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}


int cubeContenueDansParal(cube cc, cube c){
	/* On test si les 8 sommets extrémité du cube sont dans le parralélogramme */
	if(cc.s1.x <= c.s1.x && c.s1.x <= cc.s2.x && cc.s1.y <= c.s1.y && c.s1.y <= cc.s2.y && cc.s1.z <= c.s1.z && c.s1.z <= cc.s2.z){ /* Sommet 1 */
		if(cc.s1.x <= c.s2.x && c.s2.x <= cc.s2.x && cc.s1.y <= c.s2.y && c.s2.y <= cc.s2.y && cc.s1.z <= c.s2.z && c.s2.z <= cc.s2.z){ /* Sommet 2 */
			if(cc.s1.x <= c.s2.x && c.s2.x <= cc.s2.x && cc.s1.y <= c.s1.y && c.s1.y <= cc.s2.y && cc.s1.z <= c.s1.z && c.s1.z <= cc.s2.z){ /* Sommet 3 */
				if(cc.s1.x <= c.s2.x && c.s2.x <= cc.s2.x && cc.s1.y <= c.s2.y && c.s2.y <= cc.s2.y && cc.s1.z <= c.s1.z && c.s1.z <= cc.s2.z){ /* Sommet 4 */
					if(cc.s1.x <= c.s1.x && c.s1.x <= cc.s2.x && cc.s1.y <= c.s2.y && c.s2.y <= cc.s2.y && cc.s1.z <= c.s1.z && c.s1.z <= cc.s2.z){ /* Sommet 5 */
						if(cc.s1.x <= c.s2.x && c.s2.x <= cc.s2.x && cc.s1.y <= c.s1.y && c.s1.y <= cc.s2.y && cc.s1.z <= c.s2.z && c.s2.z <= cc.s2.z){ /* Sommet 6 */
							if(cc.s1.x <= c.s1.x && c.s1.x <= cc.s2.x && cc.s1.y <= c.s1.y && c.s1.y <= cc.s2.y && cc.s1.z <= c.s2.z && c.s2.z <= cc.s2.z){ /* Sommet 7 */
								if(cc.s1.x <= c.s1.x && c.s1.x <= cc.s2.x && cc.s1.y <= c.s2.y && c.s2.y <= cc.s2.y && cc.s1.z <= c.s2.z && c.s2.z <= cc.s2.z){ /* Sommet 8 */
									return 1;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}


int cubePasContientParal(cube cc, cube c){
	if(!cubeContenueDansParal(cc, c)){
		if((cc.s1.x + (cc.s2.x - cc.s1.x) < c.s1.x) || (cc.s1.y + (cc.s2.y - cc.s1.y) < c.s1.y) || (cc.s1.z + (cc.s2.z - cc.s1.z) < c.s1.z)){
			return 1;
		}
		else if((cc.s2.x - (cc.s2.x - cc.s1.x) > c.s2.x) || (cc.s2.y - (cc.s2.y - cc.s1.y) > c.s2.y) || (cc.s2.z - (cc.s2.z - cc.s1.z) > c.s2.z)){
			return 1;
		}
	}
	return 0;
}

