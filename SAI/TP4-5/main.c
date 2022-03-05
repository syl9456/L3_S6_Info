#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"



int main(int argc, char *argv[]){



	karbre A = boule2arbre(200, 200, 2000, 1000);
	
	printf("\n\n");

	kAfficher(A);

	printf("\n\n");

}