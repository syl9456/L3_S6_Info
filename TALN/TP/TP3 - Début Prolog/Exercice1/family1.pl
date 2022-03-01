father(mike,mary).
father(mike,jane).
father(franz,camilla).
father(franz,agatha).
father(john,andy).

mother(abby,mary).
mother(abby,jane).
mother(mary,camilla).
mother(mary,agatha).
mother(jane,andy).

grand_father(X,Y) :- father(X,Z),father(Z,Y).
grand_father(X,Y) :- father(X,Z),mother(Z,Y).