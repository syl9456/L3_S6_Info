#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"
#include "cube.h"

karbre kArbreVide(){
	karbre monArbre;
    monArbre = (karbre)malloc(sizeof(noeud));
    monArbre->donnee = 0;
    return monArbre;
}

karbre kArbrePlein(){
    karbre monArbre;
    monArbre = (karbre)malloc(sizeof(noeud));
    monArbre->donnee = 1;
    return monArbre;
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
	return A->donnee == 0;
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
        case 0 : printf("VIDE\n") ; break ;
        case 1 : printf("PLEIN\n") ; break ;
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

    return kConsArbre(0, boule2arbre_bis(x, y, z, r, c1, prof+1),
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

    return kConsArbre(0, boule2arbre_bis(x, y, z, r, c1, prof+1),
                      boule2arbre_bis(x, y, z, r, c2, prof+1),
                      boule2arbre_bis(x, y, z, r, c3, prof+1),
                      boule2arbre_bis(x, y, z, r, c4, prof+1),
                      boule2arbre_bis(x, y, z, r, c5, prof+1),
                      boule2arbre_bis(x, y, z, r, c6, prof+1),
                      boule2arbre_bis(x, y, z, r, c7, prof+1),
                      boule2arbre_bis(x, y, z, r, c8, prof+1));
}
