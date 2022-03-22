est_un_arbre(nil).
est_un_arbre(t(_,L,R)) :-
    est_un_arbre(L),
    est_un_arbre(R).

est_un_arbre_arbre(nil).
est_un_arbre_arbre(t(V,L,R)) :-
    est_un_arbre(V),
    est_un_arbre_arbre(L),
    est_un_arbre_arbre(R).

est_un_arbre_int(nil).
est_un_arbre_int(t(V,L,R)) :-
    int(V),
    est_un_arbre_int(L),
    est_un_arbre_itn(R).

est_un_arbre_float(nil).
est_un_arbre_flaot(t(V,L,R)) :-
    float(V),
    est_un_arbre_float(L),
    est_un_arbre_float(R).


est_un_arbre_atom(nil).
est_un_arbre_atom(t(V,L,R)) :-
    atom(V),
    est_un_arbre_atom(L),
    est_un_arbre_atom(R).


est_un_arbre_compund(t(V,L,R)) :-
    compund(V),
    est_un_arbre_compund(L),            
    est_un_arbre_compund(R).



compte_feuilles(t,(_,nil,nil),1).
compte_feuilles(nil,0).
compte_feuilles(t(_,L,nil),N) :-
    L = t(_,_,_),
    compte_feuilles(R,N).
compte_feuilles(t(_,nil,R),N) :-
    R = t(_,_,_),
    compte_feuilles(R,N).
compte_feuilles(t(_,L,R),M) :-
    L = t(_,_,_),
    R = t(_,_,_),
    compte_feuilles(L,N),
    compte_feuilles(R,P),
    M is N+P.


collecte_feuilles(nil, []).
collecte_feuilles(t(V, nil, nil), [V]) :-
    !. % CUT
collecte_feuilles(t(_, Gauche, Droite), L) :-
    collecte_feuilles(Gauche, LGauche),
    collecte_feuilles(Droite, LDroite),
    append(LGauche, LDroite, L).


collecte_noeud_interne(nil, []).
collecte_noeud_interne(t(_, nil, nil), []) :-
    !. % CUT
collecte_noeud_interne(t(V, Gauche, Droite), [V|L]) :-
    collecte_noeud_interne(Gauche, LGauche),
    collecte_noeud_interne(Droite, LDroite),
    append(LGauche, LDroite, L).


collecte_noeud_niveau(nil, [], _).
collecte_noeud_niveau(t(V, Gauche, Droite), L, N) :-
    N > 1,
    N2 is N - 1,
    collecte_noeud_niveau(Gauche, LGauche, N2),
    collecte_noeud_niveau(Droite, LDroite, N2),
    append(LGauche, LDroite, L).