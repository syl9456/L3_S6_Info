import sys

#
#   Fonction pour test si maTerminaison est dans l'arbre des terminaisons, si oui renvois la liste associé
#
def foncTerminaison(maTerminaison):
    maListe = []
    with open("terminaisons.txt", "r") as fichTerm:     # On ouvre le fichier des terminaisons
        for ligne in fichTerm:                          # pour chaque ligne
            j = 0
            listeTerm = ligne.split(",")                # on créer une liste des mot séparé par une virgule
            listeTerm[len(listeTerm)-1] = listeTerm[len(listeTerm)-1].strip('\n')     # On enlève les "\n"
            grammaire = listeTerm[0]                    # On sauvegarde la regle de grammaire
            for term in listeTerm:                      # pour chaque terminaison
                if(term == maTerminaison):
                    maListe.append([grammaire, j])
                j = j + 1
    fichTerm.close()
    return maListe

#
#   Fonction qui renvoie la liste des couples (MotBase,Conjugaison,NumeroRacine) associée à maRacine
#
def foncRacine(maRacine):
    maListe = []
    with open("mots.txt", "r") as fichRacine:           # On ouvre le fichier des racines
        for ligne in fichRacine:                        # pour chaque ligne
            j = 0
            listeRacine = ligne.split(",")                # on créer une liste des mot séparé par une virgule
            listeRacine[len(listeRacine)-1] = listeRacine[len(listeRacine)-1].strip('\n')     # On enlève les "\n"
            verbe = listeRacine[0]
            conjug = listeRacine[1]
            for rac in listeRacine:
                if(rac == maRacine):
                    maListe.append([verbe, conjug, j])
                j = j + 1
    fichRacine.close()
    return maListe


#
#   Fonction qui renvoie les groupes G de la conjugaison C
#
def foncConjugaison(maConjug):
    maListe = []
    with open("conjugaisons.txt", "r") as fichConjug:           # On ouvre le fichier des racines
        for ligne in fichConjug:                        # pour chaque ligne
            j = 0
            listeConjug = ligne.split(",")                # on créer une liste des mot séparé par une virgule
            listeConjug[len(listeConjug)-1] = listeConjug[len(listeConjug)-1].strip('\n')     # On enlève les "\n"
            if listeConjug[0] == maConjug:
                maListe = listeConjug
                return maListe
    return maListe
    fichConjug.close()



#
#   MAIN
#


mot = input("Rentrez un mot :")         # Mot a analyser
i = len(mot)                            # Nb de lettre
n = len(mot)                            # Nb de lettre


while i > 1:                            # Tant que nbLettre > 1
    racine = mot[0:i-1]                     # racine = mot de 0 a i-1
    terminaison = mot[i-1:n]                  # terminaison = mot de i a n
    LT = foncTerminaison(terminaison)    # ListeTerminaison de la terminaison associé
    if len(LT) == 0:                    # si Terminaison !∈ Arbre des terminaisons alors Fin
        sys.exit()
    else:
        while len(LT) != 0:             # tant que LT n’est pas vide faire
            NomTRg = LT.pop()
            LR = foncRacine(racine)
            print(LR)
            if len(LR) == 0:
                i = i - 1
            else:
                while len(LR) != 0:
                    MotCNRac = LR.pop()
                    LC = foncConjugaison(MotCNRac[1])
                    k = 0
                    for mot in LC:
                        if mot == NomTRg[0]:
                            if MotCNRac[2] == LC[k + NomTRg[1]]:
                                print("MOT TROUVER")
                        k = k + 1


    
                            
                    

               
            
        

        



        









    
    



