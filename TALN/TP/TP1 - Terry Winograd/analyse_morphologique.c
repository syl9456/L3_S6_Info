#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*	Affiche le mot trouvé
*/

void recherche(char *mot, char *arg){
	fprintf(stdout, "\n%s ==> recherche du mot [%s] dans le dictionnaire\n\n", arg, mot);
}

void usage(){
	fprintf(stdout, "\n./analyse_morphologique [MOT]\n\n");
	exit(0);
}

/* 
*	Retourne la lettre a la position i en partant de la fin 
*/

char lettre(char *mot, int position){
	return mot[strlen(mot)-position];
}

void testFinAnalyse(char *mot, char *argv){
	if(mot[strlen(mot)-1] == 'a' || mot[strlen(mot)-1] == 'e' || mot[strlen(mot)-1] == 'i' || mot[strlen(mot)-1] == 'o' 
								 || mot[strlen(mot)-1] == 'u' || mot[strlen(mot)-1] == 'y'){ /* 1st = voyelle ? */
		if(lettre(mot, 1) == 'i'){ /* 1st = i ? */
			mot[strlen(mot)-1] = 'y'; /* cutoff i et add y */
			recherche(mot, argv);
			exit(1);
		}
		else if(lettre(mot, 1) == 'y'){ /* 1st = y ? */
			recherche(mot, argv);
			exit(1);
		}
		else if(lettre(mot, 1) == 'e'){ /* 1st = e ? */
			if(lettre(mot, 2) == 'e'){
				recherche(mot, argv);
				exit(1);
			}
			else{
				recherche(mot, argv); /* ON DOIT TEST SI IL EST DANS LE DICO, SI NON ALORS LA SUITE */
				mot[strlen(mot)+1] = '\0'; /* add E */
				mot[strlen(mot)] = 'e';
				recherche(mot, argv);
				exit(1);
			}
		}
		else{
			mot[strlen(mot)+1] = '\0'; /* add E */
			mot[strlen(mot)] = 'e';
			recherche(mot, argv);
			exit(1);
		}
	}
	else if(lettre(mot, 1) == 'h'){ /* 1st = h ? */
		if(lettre(mot, 2) == 't'){ /* 2nd = t ? */
			recherche(mot, argv); /* ON DOIT TEST SI IL EST DANS LE DICO, SI NON ALORS LA SUITE */
			mot[strlen(mot)+1] = '\0'; /* add E */
			mot[strlen(mot)] = 'e';
			recherche(mot, argv);
			exit(1);
		}
		else{
			recherche(mot, argv);
			exit(1);
		}
	}
	else if(lettre(mot, 1) == lettre(mot, 2)){ /* 1st = 2nd ? */
		if(mot[strlen(mot)-1] == 'l' || mot[strlen(mot)-1] == 'r' || mot[strlen(mot)-1] == 's' || mot[strlen(mot)-1] == 'v' || mot[strlen(mot)-1] == 'z'){ /* 1st = liquid ? */
			recherche(mot, argv); /* ON DOIT TEST SI IL EST DANS LE DICO, SI NON ALORS LA SUITE */
			mot[strlen(mot)-1] = '\0'; /* cutoff 1st */
			recherche(mot, argv);
			exit(1);
		}
		else{
			mot[strlen(mot)-1] = '\0'; /* cutoff 1st */
			recherche(mot, argv);
			exit(1);
		}
	}
	else if(mot[strlen(mot)-2] == 'a' || mot[strlen(mot)-2] == 'e' || mot[strlen(mot)-2] == 'i' || mot[strlen(mot)-2] == 'o' 
								      || mot[strlen(mot)-2] == 'u' || mot[strlen(mot)-2] == 'y'){ /* 2nd = voyelle ? */
		if(mot[strlen(mot)-3] == 'a' || mot[strlen(mot)-3] == 'e' || mot[strlen(mot)-3] == 'i' || mot[strlen(mot)-3] == 'o' 
								     || mot[strlen(mot)-3] == 'u' || mot[strlen(mot)-3] == 'y'){ /* 3rd = voyelle ? */
			if(lettre(mot, 1) == 'c' || lettre(mot, 1) == 'g' || lettre(mot, 1) == 's' 
									 || lettre(mot, 1) == 'v' || lettre(mot, 1) == 'z'){ /* 1st = noend ? */
				mot[strlen(mot)+1] = '\0'; /* add E */
				mot[strlen(mot)] = 'e';
				recherche(mot, argv);
				exit(1);
			}
			else{
				recherche(mot, argv);
				exit(1);
			}
		}
		else{
			mot[strlen(mot)+1] = '\0'; /* add E */
			mot[strlen(mot)] = 'e';
			recherche(mot, argv);
			exit(1);
		}
	}
	else if(mot[strlen(mot)-1] == 'l' || mot[strlen(mot)-1] == 'r' || mot[strlen(mot)-1] == 's' || mot[strlen(mot)-1] == 'v' || mot[strlen(mot)-1] == 'z'){ /* 1st = liquid ? */
		if(lettre(mot, 1) == 'l' && lettre(mot, 2) == 'r'){ /* end = RL ? */
			recherche(mot, argv);
			exit(1);
		}
		else{
			mot[strlen(mot)+1] = '\0'; /* add E */
			mot[strlen(mot)] = 'e';
			recherche(mot, argv);
			exit(1);
		}
	}
}

/*
*	PROGRAMME
*/

int main(int argc, char *argv[]){

	char *mot;

	/* Test des arguments */

	if(argc != 2){
		usage();
	}

	/* Début du programme */

	mot = strdup(argv[1]);

	/* end = N'T ? */
	if(mot[strlen(mot)-1] == 't' && mot[strlen(mot)-2] == '\'' && mot[strlen(mot)-3] == 'n'){
		mot[strlen(mot)-3] = '\0'; /* cutoff N'T */
		recherche(mot, argv[1]);
		exit(1);
	}
	/* end = 'S ? */
	else if(mot[strlen(mot)-1] == 's' && mot[strlen(mot)-2] == '\''){
		mot[strlen(mot)-2] = '\0'; /* cutoff 'S */
		recherche(mot, argv[1]);
		exit(1);
	}
	/* end = ' ? */
	else if(mot[strlen(mot)-1] == '\''){
		mot[strlen(mot)-1] = '\0'; /* cutoff ' */
		mot[strlen(mot)-1] = '\0'; /* cutoff S */
		if(lettre(mot, 1) != 'e'){ /* 1st = 'E' ? */
			recherche(mot, argv[1]);
			exit(1);
		}
		else if(lettre(mot, 2) == 'i'){ /* 2nd = 'I' ? */
			mot[strlen(mot)-2] = '\0'; /* cutoff IE */
			mot[strlen(mot)+1] = '\0';
			mot[strlen(mot)] = 'y'; /* add 'Y' */
			recherche(mot, argv[1]);
			exit(1);
		}
		else if(lettre(mot, 2) == 'h'){ /* 2nd = 'H' ? */
			if(lettre(mot,3) == 't'){ /* 3rd = 'T' ? */
				recherche(mot, argv[1]);
				exit(0);
			}
			else{
				mot[strlen(mot)-1] = '\0'; /* cutoff E */
				recherche(mot, argv[1]);
				exit(1);
			}
		}
		else if(lettre(mot, 2) == 'x'){ /* 2nd = 'X' ? */
			mot[strlen(mot)-1] = '\0'; /* cutoff E */
			recherche(mot, argv[1]);
			exit(1);
		}
		else if(lettre(mot, 2) == 's' || lettre(mot, 2) == 'z'){ /* 2nd = 'S' ou 'Z' ? */
			if(lettre(mot, 3) == 's' || lettre(mot, 3) == 'z'){ /* 3rd = 'S' ou 'Z' ? */
				mot[strlen(mot)-1] = '\0'; /* cutoff E */
				recherche(mot, argv[1]);
				exit(1);
			}
			else{
				recherche(mot, argv[1]);
				exit(1);
			}
		}
		else if(lettre(mot, 2) == 'v'){ /* 2nd = 'V' ? */
			recherche(mot, argv[1]); /* ON DOIT TEST SI IL EST DANS LE DICO, SI NON ALORS LA SUITE */
			mot[strlen(mot)-2] = 'f'; /* cutoff VE && add FE */
			mot[strlen(mot)-1] = 'e';
			recherche(mot, argv[1]);
			exit(1);
		}
		else{
			recherche(mot, argv[1]);
			exit(1);
		}
	}
	else if(mot[strlen(mot)-1] == 's'){ /* end = 'S' ? */
		mot[strlen(mot)-1] = '\0'; /* cutoff S */
		if(lettre(mot, 1) != 'e'){ /* 1st = 'E' ? */
			recherche(mot, argv[1]);
			exit(1);
		}
		else if(lettre(mot, 2) == 'i'){ /* 2nd = 'I' ? */
			mot[strlen(mot)-2] = '\0'; /* cutoff IE */
			mot[strlen(mot)+1] = '\0';
			mot[strlen(mot)] = 'y'; /* add 'Y' */
			recherche(mot, argv[1]);
			exit(1);
		}
		else if(lettre(mot, 2) == 'h'){ /* 2nd = 'H' ? */
			if(lettre(mot,3) == 't'){ /* 3rd = 'T' ? */
				recherche(mot, argv[1]);
				exit(0);
			}
			else{
				mot[strlen(mot)-1] = '\0'; /* cutoff E */
				recherche(mot, argv[1]);
				exit(1);
			}
		}
		else if(lettre(mot, 2) == 'x'){ /* 2nd = 'X' ? */
			mot[strlen(mot)-1] = '\0'; /* cutoff E */
			recherche(mot, argv[1]);
			exit(1);
		}
		else if(lettre(mot, 2) == 's' || lettre(mot, 2) == 'z'){ /* 2nd = 'S' ou 'Z' ? */
			if(lettre(mot, 3) == 's' || lettre(mot, 3) == 'z'){ /* 3rd = 'S' ou 'Z' ? */
				mot[strlen(mot)-1] = '\0'; /* cutoff E */
				recherche(mot, argv[1]);
				exit(1);
			}
			else{
				recherche(mot, argv[1]);
				exit(1);
			}
		}
		else if(lettre(mot, 2) == 'v'){ /* 2nd = 'V' ? */
			recherche(mot, argv[1]); /* ON DOIT TEST SI IL EST DANS LE DICO, SI NON ALORS LA SUITE */
			mot[strlen(mot)-2] = 'f'; /* cutoff VE && add FE */
			mot[strlen(mot)-1] = 'e';
			recherche(mot, argv[1]);
			exit(1);
		}
		else{
			recherche(mot, argv[1]);
			exit(1);
		}
	}
	else if(mot[strlen(mot)-1] == 'y' && mot[strlen(mot)-2] == 'l'){ /* end = LY ? */
		mot[strlen(mot)-2] = '\0'; /* cutoff LY */
		if(lettre(mot, 1) == 'i'){ /* 1st = i ? */
			mot[strlen(mot)-1] = 'y'; /* cutoff i puis add y */
			recherche(mot, argv[1]);
			exit(1);
		}
		else{
			recherche(mot, argv[1]);
			mot[strlen(mot)+2] = '\0'; /* add LE */
			mot[strlen(mot)+1] = 'e';
			mot[strlen(mot)] = 'l';
			recherche(mot, argv[1]);
			exit(1);
		}
	}
	else if(mot[strlen(mot)-1] == 'g' && mot[strlen(mot)-2] == 'n' && mot[strlen(mot)-3] == 'i'){ /* end = ING ? */
		mot[strlen(mot)-3] = '\0'; /* cutoff ING */
		testFinAnalyse(mot, argv[1]);
	}
	else if(mot[strlen(mot)-1] == 'd' && mot[strlen(mot)-2] == 'e'){ /* end = ED ? */
		mot[strlen(mot)-2] = '\0'; /* cutoff ED */
		testFinAnalyse(mot, argv[1]);
	}
	else if(mot[strlen(mot)-1] == 'n' && mot[strlen(mot)-2] == 'e'){ /* end = EN? */
		mot[strlen(mot)-2] = '\0'; /* cutoff EN */
		testFinAnalyse(mot, argv[1]);
	}
	else if(mot[strlen(mot)-1] == 'r' && mot[strlen(mot)-2] == 'e'){ /* end = ER ? */
		mot[strlen(mot)-2] = '\0'; /* cutoff ER */
		testFinAnalyse(mot, argv[1]);
	}
	else if(mot[strlen(mot)-1] == 't' && mot[strlen(mot)-2] == 's' && mot[strlen(mot)-3] == 'e'){ /* end = EST ? */
		mot[strlen(mot)-3] = '\0'; /* cutoff EST */
		testFinAnalyse(mot, argv[1]);
	}

	exit(0);

}