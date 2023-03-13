typedef struct  {
    int val;
    struct Noeud* suivant;
} Noeud;

typedef Noeud* Pile;

Pile initPile (); // qui renvoie une pile vide
bool pileVide (Pile); // qui teste si la pile est vide
bool push (Pile*, int); // qui renvoie vrai si l’entier a été placé sur la pile
int pop (Pile*); // qui retire l’entier du sommet de la pile et le renvoie
void viderPile (Pile*); // qui vide entièrement une pile
void afficherPile (Pile); // qui affiche le contenu de la pile

