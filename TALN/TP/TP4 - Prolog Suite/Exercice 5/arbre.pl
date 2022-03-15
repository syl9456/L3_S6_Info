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
