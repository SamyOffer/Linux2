#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "utils_v1.c"

#define SCRIPT_NAME_MAX_LEN 20
#define SCRIPT_RIGHTS (S_IRWXU)
#define BUF_SIZE 256

int main() {
    char script_name[SCRIPT_NAME_MAX_LEN];
    char script_content[BUF_SIZE];
    int script_fd;
    pid_t pid;
    int status;

    printf("Nom du fichier script : ");
    readLimitedLine(script_name, SCRIPT_NAME_MAX_LEN);
    
    // Ouvre le fichier script en créant un nouveau fichier s'il n'existe pas
    script_fd = open(script_name, O_WRONLY | O_CREAT | O_TRUNC, SCRIPT_RIGHTS);
    if (script_fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    
    // Exécute ls -l sur le fichier script
    pid = fork();
    if (pid == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execl("/bin/ls", "ls", "-l", script_name, NULL);
        perror("Erreur lors de l'exécution de la commande ls");
        exit(EXIT_FAILURE);
    }
    else {
        wait(&status);
    }
    
    // Écrit le shebang dans le fichier script
    if (write(script_fd, "#!/bin/bash\n", 12) == -1) {
        perror("Erreur lors de l'écriture du shebang");
        exit(EXIT_FAILURE);
    }
    
    // Saisit le contenu du script et l'écrit dans le fichier
    printf("Contenu du script :\n");
    while (readLimitedLine(script_content, BUF_SIZE) != -1) {
        if (write(script_fd, script_content, strlen(script_content)) == -1) {
            perror("Erreur lors de l'écriture dans le fichier");
            exit(EXIT_FAILURE);
        }
        if (write(script_fd, "\n", 1) == -1) {
            perror("Erreur lors de l'écriture dans le fichier");
            exit(EXIT_FAILURE);
        }
    }
    
    // Exécute cat sur le fichier script
    pid = fork();
    if (pid == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execl("/bin/cat", "cat", script_name, NULL);
        perror("Erreur lors de l'exécution de la commande cat");
        exit(EXIT_FAILURE);
    }
    else {
        wait(&status);
    }
    
    // Exécute le fichier script
    pid = fork();
    if (pid == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execl("/bin/bash", "bash", script_name, NULL);
        perror("Erreur lors de l'exécution du script");
        exit(EXIT_FAILURE);
    }
    else {
        wait(&status);
    }
    
    // Ferme le fichier script
    if (close(script_fd) == -1){
        perror("Erreur lors de la fermeture du fichier");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
