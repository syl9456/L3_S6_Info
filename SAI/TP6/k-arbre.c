#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"

karbre kArbreVide(){
	karbre monArbre;
    monArbre = (karbre)malloc(sizeof(noeud));
    monArbre->donnee = VIDE;
    return monArbre;
}

karbre kArbrePlein(){
    karbre monArbre;
    monArbre = (karbre)malloc(sizeof(noeud));
    monArbre->donnee = PLEIN;
    return monArbre;
}

karbre kArbreNull(){
    return NULL;
}

karbre kFils(int ieme, karbre A){
	if(A->fils[ieme] != NULL){
		return A->fils[ieme];
	}
	else{
		return NULL;
	}
}

element kRacine(karbre A){
	return A->donnee;
}

int kEstVide(karbre A){
	return A->donnee == VIDE;
}

int kEstPlein(karbre A){
    return A->donnee == PLEIN;
}

void kAfficher(karbre A){
	/* On commence avec 0 espace c.a.d une profondeur de 0 */
   afficherKarbreProf(A, 0);
}

void afficherKarbreProf(karbre A, int profondeur){

	int i;

    /* arbre vide ? */
    if (A == NULL){
        return;
    }
    
    /* Affiche le noeuds avec avec les espaces */
    /* On compte */
    for (i = 0; i < profondeur; i++){
        printf(" ");
    }
    switch (A->donnee)
    {
        case VIDE : printf("VIDE\n") ; break ;
        case PLEIN : printf("PLEIN\n") ; break ;
        case COMPLEXE : printf("COMPLEXE\n") ; break ;
        default : printf("Je suis la et c'est pas normal\n"); break ;
    }
  
    /* Affichage des fils*/
    for(int y = 0; y < K; y++){
    	afficherKarbreProf(A->fils[y], profondeur+3);
    }
}


karbre kConsArbre(element e, ...){
	karbre monArbre;
	monArbre = (karbre)malloc(sizeof(noeud));
	monArbre->donnee = e;

	va_list listeArgument;
	va_start(listeArgument, e);

	for (int i = 0 ; i < K ; i++) {
        // récupérer le paramètre suivant de la liste:
        karbre arbre_suiv = va_arg(listeArgument, karbre); 
        monArbre->fils[i] = arbre_suiv;
    }
    va_end(listeArgument); // fermeture de la liste
    return monArbre;
}

karbre boule2arbre_bis(int x, int y, int z, int r, cube c, int prof){
    /* On déclare les 8 petit cube */
    cube c1;
    cube c2;
    cube c3;
    cube c4;
    cube c5;
    cube c6;
    cube c7;
    cube c8;

    if(cubeContenueDansBoule(c, x, y, z, r)){
        return kArbrePlein();
    }
    if(cubePasContientBoule(c, x, y, z, r)){
        return kArbreVide();
    }
    if(prof == PROFMAX){
        return kArbreVide();
    }

    /* On créer les 8 petit cube */

    /* CUBE 1 */
    c1.s1.x = c.s1.x; 
    c1.s1.y = (c.s1.y + c.s2.y) / 2;
    c1.s1.z = c.s1.z;
    c1.s2.x = (c.s1.x + c.s2.x) / 2;
    c1.s2.y = c.s2.y;
    c1.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 2 */
    c2.s1.x = (c.s1.x + c.s2.x) / 2;
    c2.s1.y = (c.s1.y + c.s2.y) / 2;
    c2.s1.z = c.s1.z;
    c2.s2.x = c.s2.x;
    c2.s2.y = c.s2.y;
    c2.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 3 */
    c3.s1.x = (c.s1.x + c.s2.x) / 2;
    c3.s1.y = c.s1.y;
    c3.s1.z = c.s1.z;
    c3.s2.x = c.s2.x;
    c3.s2.y = (c.s1.y + c.s2.y) / 2;
    c3.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 4 */
    c4.s1.x = c.s1.x;
    c4.s1.y = c.s1.y;
    c4.s1.z = c.s1.z;
    c4.s2.x = (c.s1.x + c.s2.x) / 2;
    c4.s2.y = (c.s1.y + c.s2.y) / 2;
    c4.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 5 */
    c5.s1.x = c.s1.x;
    c5.s1.y = (c.s1.y + c.s2.y) / 2;
    c5.s1.z = (c.s1.z + c.s2.z) / 2;
    c5.s2.x = (c.s1.x + c.s2.x) / 2;
    c5.s2.y = c.s2.y;
    c5.s2.z = c.s2.z;
    /* CUBE 6 */
    c6.s1.x = (c.s1.x + c.s2.x) / 2;
    c6.s1.y = (c.s1.y + c.s2.y) / 2;
    c6.s1.z = (c.s1.z + c.s2.z) / 2;
    c6.s2.x = c.s2.x;
    c6.s2.y = c.s2.y;
    c6.s2.z = c.s2.z;
    /* CUBE 7 */
    c7.s1.x = (c.s1.x + c.s2.x) / 2;
    c7.s1.y = c.s1.y;
    c7.s1.z = (c.s1.z + c.s2.z) / 2;
    c7.s2.x = c.s2.x;
    c7.s2.y = (c.s1.y + c.s2.y) / 2;
    c7.s2.z = c.s2.z;
    /* CUBE 8 */
    c8.s1.x = c.s1.x;
    c8.s1.y = c.s1.y;
    c8.s1.z = (c.s1.z + c.s2.z) / 2;
    c8.s2.x = (c.s1.x + c.s2.x) / 2;
    c8.s2.y = (c.s1.y + c.s2.y) / 2;
    c8.s2.z = c.s2.z;

    /* On construit l'arbre récursivement : */

    return kConsArbre(COMPLEXE, boule2arbre_bis(x, y, z, r, c1, prof+1),
                      boule2arbre_bis(x, y, z, r, c2, prof+1),
                      boule2arbre_bis(x, y, z, r, c3, prof+1),
                      boule2arbre_bis(x, y, z, r, c4, prof+1),
                      boule2arbre_bis(x, y, z, r, c5, prof+1),
                      boule2arbre_bis(x, y, z, r, c6, prof+1),
                      boule2arbre_bis(x, y, z, r, c7, prof+1),
                      boule2arbre_bis(x, y, z, r, c8, prof+1));
}

karbre boule2arbre(int x, int y, int z, int r){
    int prof = 1;
    /* On déclare les 8 petit cube */
    cube c1;
    cube c2;
    cube c3;
    cube c4;
    cube c5;
    cube c6;
    cube c7;
    cube c8;
    /* Définition du Cube */
    cube c;
    c.s1.x = 0;
    c.s1.y = 0;
    c.s1.z = 0;
    c.s2.x = 2048;
    c.s2.y = 2048;
    c.s2.z = 2048;


    if(cubeContenueDansBoule(c, x, y, z, r)){
        return kArbrePlein();
    }
    if(cubePasContientBoule(c, x, y, z, r)){
        return kArbreVide();
    }

    /* On créer les 8 petit cube */

    /* CUBE 1 */
    c1.s1.x = c.s1.x; 
    c1.s1.y = (c.s1.y + c.s2.y) / 2;
    c1.s1.z = c.s1.z;
    c1.s2.x = (c.s1.x + c.s2.x) / 2;
    c1.s2.y = c.s2.y;
    c1.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 2 */
    c2.s1.x = (c.s1.x + c.s2.x) / 2;
    c2.s1.y = (c.s1.y + c.s2.y) / 2;
    c2.s1.z = c.s1.z;
    c2.s2.x = c.s2.x;
    c2.s2.y = c.s2.y;
    c2.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 3 */
    c3.s1.x = (c.s1.x + c.s2.x) / 2;
    c3.s1.y = c.s1.y;
    c3.s1.z = c.s1.z;
    c3.s2.x = c.s2.x;
    c3.s2.y = (c.s1.y + c.s2.y) / 2;
    c3.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 4 */
    c4.s1.x = c.s1.x;
    c4.s1.y = c.s1.y;
    c4.s1.z = c.s1.z;
    c4.s2.x = (c.s1.x + c.s2.x) / 2;
    c4.s2.y = (c.s1.y + c.s2.y) / 2;
    c4.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 5 */
    c5.s1.x = c.s1.x;
    c5.s1.y = (c.s1.y + c.s2.y) / 2;
    c5.s1.z = (c.s1.z + c.s2.z) / 2;
    c5.s2.x = (c.s1.x + c.s2.x) / 2;
    c5.s2.y = c.s2.y;
    c5.s2.z = c.s2.z;
    /* CUBE 6 */
    c6.s1.x = (c.s1.x + c.s2.x) / 2;
    c6.s1.y = (c.s1.y + c.s2.y) / 2;
    c6.s1.z = (c.s1.z + c.s2.z) / 2;
    c6.s2.x = c.s2.x;
    c6.s2.y = c.s2.y;
    c6.s2.z = c.s2.z;
    /* CUBE 7 */
    c7.s1.x = (c.s1.x + c.s2.x) / 2;
    c7.s1.y = c.s1.y;
    c7.s1.z = (c.s1.z + c.s2.z) / 2;
    c7.s2.x = c.s2.x;
    c7.s2.y = (c.s1.y + c.s2.y) / 2;
    c7.s2.z = c.s2.z;
    /* CUBE 8 */
    c8.s1.x = c.s1.x;
    c8.s1.y = c.s1.y;
    c8.s1.z = (c.s1.z + c.s2.z) / 2;
    c8.s2.x = (c.s1.x + c.s2.x) / 2;
    c8.s2.y = (c.s1.y + c.s2.y) / 2;
    c8.s2.z = c.s2.z;

    /* On construit l'arbre récursivement : */

    return kConsArbre(COMPLEXE, boule2arbre_bis(x, y, z, r, c1, prof+1),
                      boule2arbre_bis(x, y, z, r, c2, prof+1),
                      boule2arbre_bis(x, y, z, r, c3, prof+1),
                      boule2arbre_bis(x, y, z, r, c4, prof+1),
                      boule2arbre_bis(x, y, z, r, c5, prof+1),
                      boule2arbre_bis(x, y, z, r, c6, prof+1),
                      boule2arbre_bis(x, y, z, r, c7, prof+1),
                      boule2arbre_bis(x, y, z, r, c8, prof+1));
}


karbre copie(karbre A){

    if(A->donnee == VIDE){
        return kArbreVide();
    }
    if(A->donnee == PLEIN){
        return kArbrePlein();
    }

    return kConsArbre(COMPLEXE, copie(A->fils[0]), 
                                copie(A->fils[1]),
                                copie(A->fils[2]),
                                copie(A->fils[3]),
                                copie(A->fils[4]),
                                copie(A->fils[5]),
                                copie(A->fils[6]),
                                copie(A->fils[7]));
}


karbre intersection(karbre V1, karbre V2){

    if(kEstVide(V1) || kEstVide(V2)){
        return kConsArbre(VIDE, kArbreNull(),
                                kArbreNull(),
                                kArbreNull(),
                                kArbreNull(),
                                kArbreNull(),
                                kArbreNull(),
                                kArbreNull(),
                                kArbreNull());
    }
    if(kEstPlein(V1)){
        return copie(V2);
    }
    if(kEstPlein(V2)){
        return copie(V1);
    }
    return kConsArbre(COMPLEXE, intersection(V1->fils[0], V2->fils[0]),
                                  intersection(V1->fils[1], V2->fils[1]),
                                  intersection(V1->fils[2], V2->fils[2]),
                                  intersection(V1->fils[3], V2->fils[3]),
                                  intersection(V1->fils[4], V2->fils[4]),
                                  intersection(V1->fils[5], V2->fils[5]),
                                  intersection(V1->fils[6], V2->fils[6]),
                                  intersection(V1->fils[7], V2->fils[7]));
}


/*
* CREATION D'UN PARALLEPIPEDE
*/


karbre paral2arbre_bis(cube cc, cube c, int prof){

    /* On déclare les 8 petit cube */
    cube c1;
    cube c2;
    cube c3;
    cube c4;
    cube c5;
    cube c6;
    cube c7;
    cube c8;


    if(cubeContenueDansParal(cc, c)){
        return kArbrePlein();
    }
    if(cubePasContientParal(cc, c)){
        return kArbreVide();
    }
    if(prof == PROFMAX){
        return kArbreVide();
    }

    /* On créer les 8 petit cube */

    /* CUBE 1 */
    c1.s1.x = c.s1.x; 
    c1.s1.y = (c.s1.y + c.s2.y) / 2;
    c1.s1.z = c.s1.z;
    c1.s2.x = (c.s1.x + c.s2.x) / 2;
    c1.s2.y = c.s2.y;
    c1.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 2 */
    c2.s1.x = (c.s1.x + c.s2.x) / 2;
    c2.s1.y = (c.s1.y + c.s2.y) / 2;
    c2.s1.z = c.s1.z;
    c2.s2.x = c.s2.x;
    c2.s2.y = c.s2.y;
    c2.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 3 */
    c3.s1.x = (c.s1.x + c.s2.x) / 2;
    c3.s1.y = c.s1.y;
    c3.s1.z = c.s1.z;
    c3.s2.x = c.s2.x;
    c3.s2.y = (c.s1.y + c.s2.y) / 2;
    c3.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 4 */
    c4.s1.x = c.s1.x;
    c4.s1.y = c.s1.y;
    c4.s1.z = c.s1.z;
    c4.s2.x = (c.s1.x + c.s2.x) / 2;
    c4.s2.y = (c.s1.y + c.s2.y) / 2;
    c4.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 5 */
    c5.s1.x = c.s1.x;
    c5.s1.y = (c.s1.y + c.s2.y) / 2;
    c5.s1.z = (c.s1.z + c.s2.z) / 2;
    c5.s2.x = (c.s1.x + c.s2.x) / 2;
    c5.s2.y = c.s2.y;
    c5.s2.z = c.s2.z;
    /* CUBE 6 */
    c6.s1.x = (c.s1.x + c.s2.x) / 2;
    c6.s1.y = (c.s1.y + c.s2.y) / 2;
    c6.s1.z = (c.s1.z + c.s2.z) / 2;
    c6.s2.x = c.s2.x;
    c6.s2.y = c.s2.y;
    c6.s2.z = c.s2.z;
    /* CUBE 7 */
    c7.s1.x = (c.s1.x + c.s2.x) / 2;
    c7.s1.y = c.s1.y;
    c7.s1.z = (c.s1.z + c.s2.z) / 2;
    c7.s2.x = c.s2.x;
    c7.s2.y = (c.s1.y + c.s2.y) / 2;
    c7.s2.z = c.s2.z;
    /* CUBE 8 */
    c8.s1.x = c.s1.x;
    c8.s1.y = c.s1.y;
    c8.s1.z = (c.s1.z + c.s2.z) / 2;
    c8.s2.x = (c.s1.x + c.s2.x) / 2;
    c8.s2.y = (c.s1.y + c.s2.y) / 2;
    c8.s2.z = c.s2.z;

    /* On construit l'arbre récursivement : */

    return kConsArbre(COMPLEXE, paral2arbre_bis(cc, c1, prof+1),
                      paral2arbre_bis(cc, c2, prof+1),
                      paral2arbre_bis(cc, c3, prof+1),
                      paral2arbre_bis(cc, c4, prof+1),
                      paral2arbre_bis(cc, c5, prof+1),
                      paral2arbre_bis(cc, c6, prof+1),
                      paral2arbre_bis(cc, c7, prof+1),
                      paral2arbre_bis(cc, c8, prof+1));
}


karbre paral2arbre(cube cc){
    int prof = 1;
    /* On déclare les 8 petit cube */
    cube c1;
    cube c2;
    cube c3;
    cube c4;
    cube c5;
    cube c6;
    cube c7;
    cube c8;
    /* Définition du Cube */
    cube c;
    c.s1.x = 0;
    c.s1.y = 0;
    c.s1.z = 0;
    c.s2.x = 2048;
    c.s2.y = 2048;
    c.s2.z = 2048;


    if(cubeContenueDansParal(cc, c)){
        return kArbrePlein();
    }
    if(cubePasContientParal(cc, c)){
        return kArbreVide();
    }

    /* On créer les 8 petit cube */

    /* CUBE 1 */
    c1.s1.x = c.s1.x; 
    c1.s1.y = (c.s1.y + c.s2.y) / 2;
    c1.s1.z = c.s1.z;
    c1.s2.x = (c.s1.x + c.s2.x) / 2;
    c1.s2.y = c.s2.y;
    c1.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 2 */
    c2.s1.x = (c.s1.x + c.s2.x) / 2;
    c2.s1.y = (c.s1.y + c.s2.y) / 2;
    c2.s1.z = c.s1.z;
    c2.s2.x = c.s2.x;
    c2.s2.y = c.s2.y;
    c2.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 3 */
    c3.s1.x = (c.s1.x + c.s2.x) / 2;
    c3.s1.y = c.s1.y;
    c3.s1.z = c.s1.z;
    c3.s2.x = c.s2.x;
    c3.s2.y = (c.s1.y + c.s2.y) / 2;
    c3.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 4 */
    c4.s1.x = c.s1.x;
    c4.s1.y = c.s1.y;
    c4.s1.z = c.s1.z;
    c4.s2.x = (c.s1.x + c.s2.x) / 2;
    c4.s2.y = (c.s1.y + c.s2.y) / 2;
    c4.s2.z = (c.s1.z + c.s2.z) / 2;
    /* CUBE 5 */
    c5.s1.x = c.s1.x;
    c5.s1.y = (c.s1.y + c.s2.y) / 2;
    c5.s1.z = (c.s1.z + c.s2.z) / 2;
    c5.s2.x = (c.s1.x + c.s2.x) / 2;
    c5.s2.y = c.s2.y;
    c5.s2.z = c.s2.z;
    /* CUBE 6 */
    c6.s1.x = (c.s1.x + c.s2.x) / 2;
    c6.s1.y = (c.s1.y + c.s2.y) / 2;
    c6.s1.z = (c.s1.z + c.s2.z) / 2;
    c6.s2.x = c.s2.x;
    c6.s2.y = c.s2.y;
    c6.s2.z = c.s2.z;
    /* CUBE 7 */
    c7.s1.x = (c.s1.x + c.s2.x) / 2;
    c7.s1.y = c.s1.y;
    c7.s1.z = (c.s1.z + c.s2.z) / 2;
    c7.s2.x = c.s2.x;
    c7.s2.y = (c.s1.y + c.s2.y) / 2;
    c7.s2.z = c.s2.z;
    /* CUBE 8 */
    c8.s1.x = c.s1.x;
    c8.s1.y = c.s1.y;
    c8.s1.z = (c.s1.z + c.s2.z) / 2;
    c8.s2.x = (c.s1.x + c.s2.x) / 2;
    c8.s2.y = (c.s1.y + c.s2.y) / 2;
    c8.s2.z = c.s2.z;

    /* On construit l'arbre récursivement : */

    return kConsArbre(COMPLEXE, paral2arbre_bis(cc, c1, prof+1),
                      paral2arbre_bis(cc, c2, prof+1),
                      paral2arbre_bis(cc, c3, prof+1),
                      paral2arbre_bis(cc, c4, prof+1),
                      paral2arbre_bis(cc, c5, prof+1),
                      paral2arbre_bis(cc, c6, prof+1),
                      paral2arbre_bis(cc, c7, prof+1),
                      paral2arbre_bis(cc, c8, prof+1));
}

