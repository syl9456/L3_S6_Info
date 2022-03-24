#ifndef KARBRE_H
#define KARBRE_H

#include "cube.h"

#define K 8
#define N 11
#define PROFMAX 9
#define VIDE 0
#define PLEIN 1
#define COMPLEXE 2

typedef int element;

typedef struct noeud{
	element donnee;
	cube c;
	struct noeud *fils[K];
}noeud;
typedef noeud *karbre;

karbre kArbreVide();
karbre kArbrePlein();
karbre kFils(int ieme, karbre A);
element kRacine(karbre A);
int kEstVide(karbre A);
void kAfficher(karbre A);
void afficherKarbreProf(karbre A, int profondeur);
int kEstPlein(karbre A);
karbre copie(karbre A);
karbre kArbreNull();
karbre kConsArbre(element e, ...);
karbre boule2arbre(int x, int y, int z, int r);
karbre boule2arbre_bis(int x, int y, int z, int r, cube c, int prof);
karbre intersection(karbre V1, karbre V2);
karbre paral2arbre(cube c);
karbre paral2arbre_bis(cube cc, cube c, int prof);


#endif