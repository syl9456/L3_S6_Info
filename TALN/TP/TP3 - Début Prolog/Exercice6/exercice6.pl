
young('Mary').
own('Mary', 'Guitar').
learn('Mary', 'Guitar').
love('Mary', 'Paul').

old('John').
know('John', 'Dance').

build('Lindsey', 'Violin').

chord('Guitar').
chord('Violin').

genius('George').


happy(X) :- young(X), play(X, 'Guitar');
			old(X), play(X, 'Violin');
			play(X, 'Drums').

play(X, Y) :- own(X, Y), learn(X, Y);
			  genius(X), chord(Y);
			  build(X, Y).

happyLover(P1, P2) :- happy(P1), love(P1, P2).

happyDanser(P1, P2) :- know(P1, 'Dance'), happy(P2).

dance(P1, P2) :- happyDanser(P1, P2);
				 happyLover(P1, P2);
				 build(P1, P2).

