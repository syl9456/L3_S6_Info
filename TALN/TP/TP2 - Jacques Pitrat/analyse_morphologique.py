
#
#   Fonction pour test si maTerminaison est dans l'arbre des terminaisons, si oui renvois la liste associé
#
def foncTerminaison(maTerminaison):
    with open("terminaisons.txt", "r") as fichTerm:     # On ouvre le fichier des terminaisons
        for ligne in fichTerm:                          # pour chaque ligne
            listeTerm = ligne.split(",")                # on créer une liste des mot séparé par une virgule
            listeTerm[len(listeTerm)-1] = listeTerm[len(listeTerm)-1].strip('\n')     # On enlève les "\n"
            for motTerm in listeTerm:                   # Pour chaque mot dans la liste
                if motTerm == maTerminaison:            # On test si elle est dans l'arbre des terminaisons
                    fichTerm.close()
                    return listeTerm
    fichTerm.close()
    return 0

#
#   Fonction qui renvoie la liste des couples (MotBase,Conjugaison,NumeroRacine) associée à maRacine
#
def foncRacine(maRacine):
    with open("mots.txt", "r") as fichRacine:           # On ouvre le fichier des racines
        for ligne in fichRacine:                        # pour chaque ligne
            listeRacine = ligne.split(",")              # on créer une liste des mot séparé par une virgule
            listeRacine[len(listeRacine)-1] = listeRacine[len(listeRacine)-1].strip('\n')   # On enlève les "\n"
            for motRacine in listeRacine:                 # Pour chaque mot dans la liste
                if motRacine == maRacine:                 # On test si la racine y est
                    fichRacine.close()
                    return listeRacine
    fichRacine.close()
    return []



#
#   MAIN
#


mot = input("Rentrez un mot :")         # Mot a analyser
i = len(mot)                            # Nb de lettre
n = len(mot)                            # Nb de lettre

ip = 0
ii = 0
ps = 0
iif = 0
cd = 0
sp = 0
si = 0
imp = 0
pi = 0
nomadj = 0

while i > 1:                            # Tant que nbLettre > 1
    racine = mot[0:i-1]                     # racine = mot de 0 a i-1
    terminaison = mot[i:n]                  # terminaison = mot de i a n
    i = i - 1
    ListT = foncTerminaison(terminaison)    # ListeTerminaison de la terminaison associé
    if ListT != 0:                          # Si Terminaison ∈ Arbre des terminaisons
        NomT = ListT.pop(0)                     # Nom des terminaison
        rang = 0                                # On setup le rang des terminaisons
        LT = []                                 # Liste des couple teminaison/rang vide
        for term in ListT:                      # Pour chaque terminaison associé a la temrinaison de notre mot
            LT.append([NomT, rang])              # On rajoute a LT [temrinaison, rang]
            rang = rang + 1
        LT.reverse()                            # On inverse l'ordre pour faire une pile
        while len(LT) > 0:                      # Tant que LR est pas vide
            coupleTerm = LT.pop()                   # (NomT,Rg) ← tête(LT)
            ListR = foncRacine(racine)              # ListR est la ligne qui contient la racine
            if len(ListR) != 0:
                motDeBase = ListR.pop(0)                # Mot de Base
                conjugaison = ListR.pop(0)              # Conjugaison
            numeroRacine = 1
            LR = []                                 # on initialise les couples (MotBase,Conjugaison,NumeroRacine) associée à Racine
            for raci in ListR:
                LR.append([motDeBase, conjugaison, numeroRacine])   # On rajoute a LR [MotBase, Conjugaison, NumeroRacine]
                numeroRacine = numeroRacine + 1
            LR.reverse()                                            # On reverse la liste pour faire une pile
            while len(LR) > 0:                                      # tant que LR n’est pas vide
                coupleRacine = LR.pop()                             # (Mot,C,NRac) ← tête(LR)
                with open("conjugaisons.txt", "r") as fichConjug:   # On ouvre le fichier des conjugaisons
                    for ligne in fichConjug:                        # On regarde les ligne du fichier
                        if coupleRacine[1] in ligne:                # Si on est dans le groupe de conjugaison C
                            listeConjug = ligne.split(",")          # On split les term en liste
                            listeConjug[len(listeConjug)-1] = listeConjug[len(listeConjug)-1].strip('\n')     # On enlève les "\n"
                            listeConjug.pop(0)                      # On enleve le conj2, conj1,....
                            deplace = 0
                            for donnee in listeConjug:
                                if donnee == coupleTerm[0]:
                                    if int(listeConjug[deplace + coupleTerm[1] + 1]) == int(coupleRacine[2]):
                                        if listeConjug[deplace-1] == "ip":
                                            if ip == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Indicatif présent")
                                                ip = 1
                                        elif listeConjug[deplace-1] == "ii":
                                            if ii == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Indicatif Imparfait")
                                                ii = 1
                                        elif listeConjug[deplace-1] == "ps":
                                            if ps == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Passé Simple")
                                                ps = 1
                                        elif listeConjug[deplace-1] == "if":
                                            if iif == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Indicatif Futur")
                                                iif = 1
                                        elif listeConjug[deplace-1] == "cd":
                                            if cd == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Conditionnel")
                                                cd = 1
                                        elif listeConjug[deplace-1] == "sp":
                                            if sp == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Subjonctif Présent")
                                                sp = 1
                                        elif listeConjug[deplace-1] == "si":
                                            if si == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Subjonctif imparfait")
                                                si = 1
                                        elif listeConjug[deplace-1] == "imp":
                                            if imp == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Impératif")
                                                imp = 1
                                        elif listeConjug[deplace-1] == "pi":
                                            if pi == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Verbe, Participes Présent et Passé, Infinitif")
                                                pi = 1
                                        elif listeConjug[deplace-1] == "nomadj":
                                            if nomadj == 0:
                                                print(mot, " ==> ", coupleRacine[0], ", Noms et Adjectifs")
                                                nomadj = 1
                                deplace = deplace + 1
        
                            
                    

               
            
        

        



        









    
    



