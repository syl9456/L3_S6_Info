
concatenation([], L, L).
concatenation([X|L1], L2, [X|L3]) :-
    concatenation(L1, L2, L3).

est_dans(X, [X|_]) :- !.  % Le ! signifie "cut" ça sert a rrêter le programme et ne pas regarder les tests en dessous
est_dans(X, [_|L]) :- est_dans(X, L).

premier(X, [X|_]).

dernier(X, [X]) :- !.  % Le ! signifie "cut" ça sert a rrêter le programme et ne pas regarder les tests en dessous
dernier(X, [_|L]) :-
    dernier(X, L).

longueur([], 0).
longueur([V|L], N) :-
    longueur(L, P),
    N is P+1.          % 'is' permet d'éffectuer un calcul

element_k(Valeur,[Valeur|_],1).
element_k(Valeur,[_|Reste],K) :-
    K > 1,
    K2 is K - 1,       % 'is' permet d'éffectuer un calcul
    element_k(Valeur, Reste, K2).

retourne([], []).
retourne([X|L1], L2) :-
    retourne(L1, L3),
    append(L3, [X], L2).

retourne2(L1, L2) :-
    retourne3(L1, L2, []). % [] est un accumulateur
retourne3([], Accumulateur, Accumulateur).
retourne3([X|L1], L2, L3) :-
    retourne3(L1, L2, [X|L3]).

est_palindrome(L) :-
    reverse(L,L).

duplique([], []).
duplique([X|L1], [X, X | L2]) :-
    duplique(L1, L2).

duplique(L1, N, L2) :-
    duplique(L1, N, N, L2).

duplique([], _, _, []).
duplique([_|L1], N, 0, L2) :-
    duplique(L1, N, N, L2).
duplique([X|L1], N, K, [X|L2]) :-
    K > 0,
    K1 is K-1,
    duplique([X|L1], N, K1, L2).

