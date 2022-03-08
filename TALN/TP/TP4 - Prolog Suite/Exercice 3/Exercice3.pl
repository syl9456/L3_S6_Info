animal(alligator).
animal(tortue).
animal(caribou).
animal(ours).
animal(cheval).
animal(vache).
animal(lapin).
animal(bouc).
animal(pintade).

mutant(M) :- 
    animal(A1),
    animal(A2),
    name(A1, LA1),
    name(A2, LA2),
    append(LDebut1, LFin1, LA1),
    LFin1 \== [],
    append(LDebut2, LFin2, LA2),
    LFin2 \== [],
    LFin1 == LDebut2,
    append(LA1, LFin2, LM),
	name(M, LM).

	