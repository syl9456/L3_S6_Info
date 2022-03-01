localisation('Dijon', 'Bourgogne').
localisation('Nice', 'Provence').
localisation('Paris', 'Ile de France').
localisation('Londre', 'Greater London').
localisation('Newcastle', 'Avon').

region(X, Y) :- localisation(X, Y).

pays(X, 'France') :- region(X, 'Bourgogne');
					 region(X, 'Provence');
					 region(X, 'Ile de France').

pays(X, 'Grande Bretagne') :- region(X, 'Greater London');
							  region(X, 'Avon').

continent(X, 'Europe') :- pays(X, 'France');
					      pays(X, 'Grande Bretagne').

