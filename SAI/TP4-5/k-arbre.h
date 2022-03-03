
#define K 8
#define N 1024

typedef int element;

typedef struct noeud{
	element donnee;
	struct noeud *fils[K];
}noeud;
typedef noeud *karbre;

karbre kArbreVide();
karbre kFils(int ieme, karbre A);
element kRacine(karbre A);
int kEstVide(karbre A);
void kAfficher(karbre A);
void afficherKarbreProf(karbre A, int profondeur);
karbre kConsArbre(element e, ...);