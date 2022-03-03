#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"



int main(int argc, char *argv[]){

	karbre A1 = kConsArbre(0, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A2 = kConsArbre(1, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A3 = kConsArbre(1, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A4 = kConsArbre(0, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A5 = kConsArbre(0, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A6 = kConsArbre(1, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A7 = kConsArbre(0, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());
	karbre A8 = kConsArbre(1, kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide(), kArbreVide());

	karbre A = kConsArbre(0, A1, A2, A3, A4, A5, A6, A7, A8);
	
	printf("\n\n");

	kAfficher(A);

	printf("\n\n");

}