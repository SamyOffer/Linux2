#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "biblio.h"
#include "utils_v1.h"

#define BUF_SIZE  MAX_TITRE+2

// Définition de variable globale pour fonctions str2genre et genre2str

static char* lesGenres[] = {"Bande dessinée", "Poésie", "Théâtre",
                            "Roman", "Roman historique", "Littérature française",
                            "Littérature étrangère", "Sciences", "Informatique",
                            "Science-fiction", "Santé", "Histoire", NULL};


// Implémentation des fonctions

bool lireLivre (struct Livre* livre){
    // A FAIRE 
}

enum Genre str2genre (char* s){
    if (strcmp(s,"Bande dessinée")) return BD;
	if (strcmp(s,"Poésie")) return PO;
	if (strcmp(s,"Poésie")) return PO;
	if (strcmp(s,"Théâtre")) return TH;
	if (strcmp(s,"Roman")) return RO;
	if (strcmp(s,"Roman historique")) return RH;
	if (strcmp(s,"Littérature française")) return LF;
	if (strcmp(s,"Littérature étrangère")) return LE;
	if (strcmp(s,"Sciences")) return SC;
	if (strcmp(s,"Informatique")) return IN;
	if (strcmp(s,"Science-fiction")) return SF;
	if (strcmp(s,"Santé")) return SA;
	if (strcmp(s,"Histoire")) return HI;
	return -1;
}

char* genre2str (enum Genre g) {
	switch (g) {
		case BD: return "Bande dessinée";
		case PO: return "Poésie";
		case TH: return "Théâtre";
		case RO: return "Roman";
		case RH: return "Roman historique";
		case LF: return "Littérature française";
		case LE: return "Littérature étrangère";
		case SC: return "Sciences";
		case IN: return "Informatique";
		case SF: return "Science-fiction";
		case SA: return "Santé";
		case HI: return "Histoire";
		default: return NULL;
	}
}

char* livre2str (char* s, struct Livre l){
    
    sprintf(buffer, "Sum of %d and %d is %d", a, b, c);

}