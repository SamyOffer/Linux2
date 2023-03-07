#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pile.h"

typedef struct  {
    int val;
    struct Noeud* suivant;
} Noeud;

typedef Noeud* Pile;

Pile initPile (){
    return null;
}

bool pileVide(Pile p){
    if( p != NULL){
        printf("La pile n'est pas vide");
        return false;
    }
    return true;
}

bool push (Pile* p, int value){
    // todo
}

int pop(Pile* p) {
   // todo 
}