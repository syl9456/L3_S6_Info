etudiant('John').
etudiant('Mary').
etudiant('Jack').

homme('John').
homme('Jack').

femme('Mary').

amoureux(X, Y) :- etudiant(X), etudiant(Y), homme(X), femme(Y);
				  etudiant(X), etudiant(Y), homme(Y), femme(X).