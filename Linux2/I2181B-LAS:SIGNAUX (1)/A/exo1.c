#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

int main() {
    pid_t childId = fork();
    if (childId == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(EXIT_FAILURE);
    } 
    if(childId == 0){
        while( 1 ){
            sleep(1);
        }
    }
    system("ps");
    kill(childId, SIGUSR1);
}
