#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "k-arbre.h"

karbre kArbreVide(){
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
	return A == NULL;
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
