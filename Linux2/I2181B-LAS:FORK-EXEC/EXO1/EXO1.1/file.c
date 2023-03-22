#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int a = 5;
    int idFork = fork();
    if(idFork == 0){
        int b = a *2;
        printf("Dans le fork contenue de a et b :  %d et %d", a,b);
        printf("\nDans le fork value of fork : %d\n", idFork);

    }
    else{
        int b = a * 5;
       
        printf("Pas dans le fork contenue de a et b :  %d et %d", a,b);
        printf("\nPas dans le fork value of fork : %d\n", idFork);

    }
}