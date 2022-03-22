
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
is_list([]).
is_list([_|_]).

est_un_arbre(t(V, LArbres)) :-
	% Ici on rajoute ce qu'on veux que l'arbre contienne
	% Par exemple : is_list(V) Si on veux que la donnée
	% Soit une liste
	% Ou Integer(V) si on veut que ce soit un entier
	% Dans le cas présent, il n'y a rien donc l'arbre
	% Contient ce qu'il veut
	est_une_liste_arbres(LArbres).

est_une_liste_arbres([]).
est_une_liste_arbres([Arbre|LArbres]) :-
	est_un_arbre(Arbre),
	est_une_liste_arbres(LArbres).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
compte_noeuds(t(_, LArbres), N) :-
	compte_noeuds_liste_arbres(LArbres, NLA),
	N is NLA + 1.
compte_noeuds_liste_arbres([], 0).
compte_noeuds_liste_arbres([Arbre|LArbres], N) :-
	compte_noeuds(Arbre, N1),
	compte_noeuds_liste_arbres(LArbres, N2),
	N is N1 + N2.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


