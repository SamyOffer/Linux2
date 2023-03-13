#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "pile.h"
#include "utils_v1.h"

Pile initPile (){
    return NULL;
}

bool pileVide(Pile p){
    if( p != NULL){
        printf("La pile n'est pas vide");
        return false;
    }
    return true;
}

bool push (Pile* p, int value){
    Noeud* nv_noeud = malloc(sizeof(Noeud));
    if (nv_noeud == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire pour le nouveau nœud\n");
        return false;
    }
    (*nv_noeud).val = value;
    (*nv_noeud).suivant = *p;

    *p = nv_noeud; 
    return true;
}

int pop(Pile* p) {
    if(pileVide(*p) == true){
        return -1;
    }
    if((*(*p)).suivant == NULL){
        return -1;
    }
    Noeud* temp = *p;
    int old_value = (*(*p)).val;
    *p = (*(*p)).suivant;
    free(temp);
    return old_value;
}

void afficherPile (Pile p){
    while((*p).suivant != NULL){
        printf("%d", (*p).val);
        (*p) = (*p).suivant;
    }

}