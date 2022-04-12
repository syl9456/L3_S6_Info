% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here
nombre(N) --> nombre_a_un_chiffre(N).
nombre(N) --> nombre_a_deux_chiffres(N).
nombre(N) --> nombre_a_trois_chiffres(N).
nombre(N) --> nombre_a_quatre_chiffres(N).

nombre_a_un_chiffre(0) --> [zero].
nombre_a_un_chiffre(1) --> [un].
nombre_a_un_chiffre(N) --> chiffre_2_a_9(N).
chiffre_2_a_9(2) --> [deux].
chiffre_2_a_9(3) --> [trois].
chiffre_2_a_9(4)--> [quatre].
chiffre_2_a_9(5) --> [cinq].
chiffre_2_a_9(6) --> [six].
chiffre_2_a_9(7) --> [sept].
chiffre_2_a_9(8) --> [huit].
chiffre_2_a_9(9) --> [neuf].

nombre_a_deux_chiffres(11) --> [onze].
nombre_a_deux_chiffres(12) --> [douze].
nombre_a_deux_chiffres(13) --> [treize].
nombre_a_deux_chiffres(14) --> [quatorze].
nombre_a_deux_chiffres(15) --> [quinze].
nombre_a_deux_chiffres(16) --> [seize].
nombre_a_deux_chiffres(17) --> [dix,sept].
nombre_a_deux_chiffres(18) --> [dix,huit].
nombre_a_deux_chiffres(19) --> [dix,neuf].

nombre_a_deux_chiffres(N) --> dizaine(D),{N is D}.
nombre_a_deux_chiffres(N) --> dizaine(D),et_un,{N is D+1}.
nombre_a_deux_chiffres(N) --> dizaine(D),chiffre_2_a_9(M), {N is D+M}.

et_un --> [et,un].
dizaine(20) --> [vingt].
dizaine(30) --> [trente].
dizaine(40) --> [quarente].
dizaine(50) --> [cinquante].
dizaine(60) --> [soixante].
dizaine(70) --> [soixante,dix].
dizaine(80) --> [quatre,vingt].
dizaine(90) --> [quatre,vingt,dix].

cent(100) --> [cent].
centaine(N) --> cent(N).
centaine(N) --> chiffre_2_a_9(M), cent(C), {N is M*C}.

nombre_a_trois_chiffres(N) --> centaine(M), suite_3(N2), {N is M+N2}.

suite_3(N) --> [].
suite_3(N) --> nombre_a_un_chiffre(D).

nombre_a_quatre_chiffres(N) --> milliers(N).
nombre_a_quatre_chiffres(N) --> milliers(M), nombre_a_un_chiffre(D), {N is M+D}.
nombre_a_quatre_chiffres(N) --> milliers(M), nombre_a_deux_chiffres(D), {N is M+D}.
nombre_a_quatre_chiffres(N) --> milliers(M), nombre_a_trois_chiffres(D), {N is M+D}.


mille(1000) --> [mille].
milliers(N) --> mille(N).
milliers(N) --> chiffre_2_a_9(M), mille(D), {N is M*D}.



/** <examples> Your example queries go here, e.g.
?- member(X, [cat, mouse]).
*/