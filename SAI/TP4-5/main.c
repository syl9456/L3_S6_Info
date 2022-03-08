#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"



int main(int argc, char *argv[]){



	karbre A1 = boule2arbre(512, 512, 512, 1000);
	karbre A2 = boule2arbre(1024, 1024, 1024, 600);
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