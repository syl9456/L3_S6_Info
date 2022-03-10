#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"



int main(int argc, char *argv[]){



	/*karbre A1 = boule2arbre(512, 512, 512, 1200);
	karbre A2 = boule2arbre(1536, 512, 512, 1200);
	karbre interA1A2;
	
	printf("\n\n");

	kAfficher(A1);

	printf("\n\n");

	kAfficher(A2);

	printf("\n\n");

	interA1A2 = intersection(A1, A2);
	kAfficher(interA1A2);*/

	printf("\n\n");

	cube monParal;
	monParal.s1.x = 0; monParal.s1.y = 0; monParal.s1.z = 0;
	monParal.s2.x = 2048; monParal.s2.y = 1024; monParal.s2.z = 2048;
	karbre P1 = paral2arbre(monParal);

	kAfficher(P1);

	printf("\n\n");

}