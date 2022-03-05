#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"



int main(int argc, char *argv[]){



	karbre A = boule2arbre(1024, 1024, 1024, 5000);
	
	printf("\n\n");

	kAfficher(A);

	printf("\n\n");

}