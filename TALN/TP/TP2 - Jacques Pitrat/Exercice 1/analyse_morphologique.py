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
                    maListe.append([verbe, conjug, j-2])
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
    while len(LT) != 0:             # tant que LT n’est pas vide faire
        NomTRg = LT.pop()
        LR = foncRacine(racine)
        if len(LR) == 0:
            break
        else:
            while len(LR) != 0:
                MotCNRac = LR.pop()
                LC = foncConjugaison(MotCNRac[1])
                k = 0
                for donnee in LC:
                    if donnee == NomTRg[0]:
                        if int(MotCNRac[2]) == int(LC[k + NomTRg[1]]): # On a trouvé une analyse
                            if LC[k-1] == "ip":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Présent, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Présent, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Présent, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Présent, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Présent, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Présent, 3eme Personne du Pluriel")
                            elif LC[k-1] == "ii":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Imparfait, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Imparfait, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Imparfait, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Imparfait, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Imparfait, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Imparfait, 3eme Personne du Pluriel")
                            elif LC[k-1] == "ps":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Passé Simple, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Passé Simple, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Passé Simple, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Passé Simple, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Passé Simple, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Passé Simple, 3eme Personne du Pluriel")
                            elif LC[k-1] == "if":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Futur, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Futur, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Futur, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Futur, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Futur, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Indicatif Futur, 3eme Personne du Pluriel")
                            elif LC[k-1] == "cd":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Conditionnel, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Conditionnel, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Conditionnel, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Conditionnel, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Conditionnel, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Conditionnel, 3eme Personne du Pluriel")
                            elif LC[k-1] == "sp":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Présent, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Présent, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Présent, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Présent, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Présent, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Présent, 3eme Personne du Pluriel")
                            elif LC[k-1] == "si":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Imparfait, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Imparfait, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Imparfait, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Imparfait, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Imparfait, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Subjonctif Imparfait, 3eme Personne du Pluriel")
                            elif LC[k-1] == "imp":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Impératif, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Impératif, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Impératif, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Impératif, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Impératif, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Impératif, 3eme Personne du Pluriel")
                            elif LC[k-1] == "pi":
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Participes Présent et Passé, Infinitif, 1ere Personne du Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Participes Présent et Passé, Infinitif, 2eme Personne du Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Participes Présent et Passé, Infinitif, 3eme Personne du Singulier")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Participes Présent et Passé, Infinitif, 1ere Personne du Pluriel")
                                elif NomTRg[1] == 5:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Participes Présent et Passé, Infinitif, 2eme Personne du Pluriel")
                                elif NomTRg[1] == 6:
                                    print(mot + " ==> " + MotCNRac[0] + ", Verbe, Participes Présent et Passé, Infinitif, 3eme Personne du Pluriel")
                            else:
                                if NomTRg[1] == 1:
                                    print(mot + " ==> " + MotCNRac[0] + ", Nom, Masculin, Singulier")
                                elif NomTRg[1] == 2:
                                    print(mot + " ==> " + MotCNRac[0] + ", Nom, Féminin, Singulier")
                                elif NomTRg[1] == 3:
                                    print(mot + " ==> " + MotCNRac[0] + ", Nom, Masculin, Pluriel")
                                elif NomTRg[1] == 4:
                                    print(mot + " ==> " + MotCNRac[0] + ", Nom, Féminin, Pluriel")
                    k = k + 1
    i = i - 1


    
                            
                    

               
            
        

        



        









    
    



