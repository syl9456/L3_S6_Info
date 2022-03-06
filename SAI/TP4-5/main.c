#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"



int main(int argc, char *argv[]){



	karbre A1 = boule2arbre(200, 200, 2000, 1000);
	karbre A2 = boule2arbre(100, 100, 2000, 1000);
	karbre interA1A2;
	
	printf("\n\n");

	kAfficher(A1);

	printf("\n\n");

	kAfficher(A2);

	printf("\n\n");

	interA1A2 = intersection(A1, A2);
	kAfficher(interA1A2);

	printf("\n\n");

}