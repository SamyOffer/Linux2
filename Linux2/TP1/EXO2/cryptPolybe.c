#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cryptPolybe.h"

static char square[8][8] =
// 1    2    3    4    5    6    7    8
{{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
 {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
 {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
 {'Y', 'Z', '0', '1', '2', '3', '4', '5'},
 {'6', '7', '8', '9', ' ', '!', '"', '#'},
 {'$', '%', '&', '\'', '(', ')', '*', '+'},
 {',', '-', '.', '/', ':', ';', '<', '='},
 {'>', '?', '@', '[', '\\', ']', '^', '_'}};

char* encryptPolybe(char* msg){

    int n = strlen(msg);
    char* word = malloc( (2*n+1) * sizeof(char) );
     if (word == NULL) {
      perror("word is null");
      exit(0);
   }

    memset(word, '\0', n+1);
    // parcours chaque lettres du mots 
    int a = 0;
    while (a < strlen(msg)){
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0; j < 8 ; j++){
                if(square[i][j] == msg[a]){
                    word[a++] = 'A' + i; 
                    word[a++] = 'A' + j;
                }
            }
        }
    }
    return word;
}
/*
char* decryptPolybe(char* msg){

}
*/