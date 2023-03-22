#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("4 5 6\n");
        exit(123); // quitter le processus enfant avec un exit code de 123
    } else {
        sleep(1); // retarder l'exécution du processus parent d'une seconde
        printf("1 2 3\n");
        int status;
        waitpid(pid, &status, 0); // attendre la fin de l'exécution de l'enfant
        printf("Exit code du processus enfant : %d\n", WEXITSTATUS(status)); // afficher l'exit code du processus enfant
    }
    return 0;
}
