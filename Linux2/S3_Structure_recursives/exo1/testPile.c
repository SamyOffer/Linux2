#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

int main(int argc, char **argv){
    Pile p = initPile();
    int value;
    printf("Value : ");
    int lineRead = scanf(%d, &value);
    push(&p, lineRead);
    afficherPile(p);
}