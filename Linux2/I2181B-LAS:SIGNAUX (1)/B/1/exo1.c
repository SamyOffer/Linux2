#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

int end = 0;

void sigusr1_handler() {
    char* msg = "\nsignal SIGUSR1 reçu !\n";
    write(1, msg, strlen(msg));
    end = 1;
}

int main() {

    //création du handler et armement avant la création du fils 
    ssigaction(SIGUSR1, sigusr1_handler);

    pid_t childId = fork();
    if (childId == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(EXIT_FAILURE);
    } 
    if(childId == 0){
        while( end == 0 ){
            sleep(1);
        }
    }
    else{
        system("ps\n");
        // skill lance la fonction sigusr1_handler()
        skill(childId, SIGUSR1);
        printf("fini\n");
    }
}
