
herbivorous('Antelope', 'Emma').
ferocious('Lion', 'Harry').

carnivorous(X, Y) :- ferocious(X, Y).

eat(X, Y, 'Meat') :- carnivorous(X, Y).
eat(X, Y, 'Grass') :- herbivorous(X, Y).

drink(X, Y, 'Water') :- carnivorous(X, Y);
						herbivorous(X, Y).

