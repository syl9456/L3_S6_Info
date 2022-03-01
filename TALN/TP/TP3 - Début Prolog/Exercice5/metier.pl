metier('Chopin', 'Compositeur de Musique Classique').
metier('Liszt', 'Compositeur de Musique Classique').
metier('Rachmaninov', 'Compositeur de Musique Classique').

metier('Jagger', 'Chanteur de Rock').
metier('Presley', 'Chanteur de Rock').

metier('Sartre', 'Philosophe').

metier('Levy', 'Écrivain').
metier('Sartre', 'Écrivain').

domaine(X, 'Musique') :- metier(X, 'Compositeur de Musique Classique');
						 metier(X, 'Chanteur de Rock').

domaine(X, 'Écriture') :- metier(X, 'Philosophe');
						 metier(X, 'Écrivain').

artiste(X) :- domaine(X, 'Musique');
			  domaine(X, 'Écriture').

