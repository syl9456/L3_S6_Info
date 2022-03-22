
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Découpe le mot donnée en toute les racine et terminaison possible
decoupe(Mot, Racine, Terminaison) :-
    name(Mot, ListeMot),
    append(L1, R1, ListeMot),
    name(Racine, L1),
    name(Terminaison, R1).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% mot(tenir,verbe,conj1,[tien,ten,tienn,tin,tîn]).
mot(tenir, verbe, conj1, tien, 1).
mot(tenir, verbe, conj1, ten, 2).
mot(tenir, verbe, conj1, tienn, 3).
mot(tenir, verbe, conj1, tin, 4).
mot(tenir, verbe, conj1, tîn, 5).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% terminaison(vip1,[s,s,t,ons,ez,ent]).
terminaison(vip1, s, 1).
terminaison(vip1, s, 2).
terminaison(vip1, t, 3).
terminaison(vip1, ons, 4).
terminaison(vip1, ez, 5).
terminaison(vip1, ent, 6).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% conjugaison(conj1,[[ip,vip1,[1,1,1,2,2,3]],[ii,vii1,[2,2,2,2,2,2]],[ps,vps1,[4,4,4,5,5,4]],[if,vf1,[1,1,1,1,1,1]],[cd,vc1,[1,1,1,1,1,1]],[sp,vsp1,[3,3,3,2,2,3]],[si,vsi1,[4,4,5,4,4,4]],[imp,vip1,[0,1,0,2,2,0]],[pi,vpt1,[2,2,2,2,2,2]]]).
conjugaison(conj1, ip, vip1, 1, 1).
conjugaison(conj1, ip, vip1, 1, 2).
conjugaison(conj1, ip, vip1, 1, 3).
conjugaison(conj1, ip, vip1, 2, 4).
conjugaison(conj1, ip, vip1, 2, 5).
conjugaison(conj1, ip, vip1, 3, 6).

conjugaison(conj1, ii, vii1, 2, 1).
conjugaison(conj1, ip, vip1, 2, 2).
conjugaison(conj1, ip, vip1, 2, 3).
conjugaison(conj1, ip, vip1, 2, 4).
conjugaison(conj1, ip, vip1, 2, 5).
conjugaison(conj1, ip, vip1, 2, 6).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
analyse(Mot, MotCanonique, Category, Groupe, Personne) :-
	decoupe(Mot, Racine, Terminaison),
	mot(MotCanonique, Categorie, NomConjugaison, Racine, NumeroRacine),
	terminaison(NomTerminaison, Terminaison, Personne),
	conjugaison(NomConjugaison, Groupe, NomTerminaison, NumeroRacine, Personne).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%