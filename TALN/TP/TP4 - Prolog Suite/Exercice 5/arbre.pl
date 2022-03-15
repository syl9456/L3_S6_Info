compte_feuilles(t(_, nil, nil), 1).
compte_feuilles(nil, 0).
compte_feuilles(t(_, L, nil), N) :-
	L = t(_, _, _),
	compte_feuilles(L, N).
compte_feuilles(t(_, nil, R), N) :-
	R = t(_, _, _),
	compte_feuilles(R, N).
compte_feuilles(t(_, L, R), M) :-
	L = t(_, _, _),
	R = t(_, _, _),
	compte_feuilles(L, N),
	compte_feuilles(R, P),
	M is N + P.
