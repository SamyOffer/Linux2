#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Inclure la bibliothèque time.h

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int SYSCALLS = 0;
    clock_t start_time, end_time; // Déclarer les variables pour stocker le temps de début et de fin

    if(SYSCALLS == 0){
        printf("sys");
        int fd = open("outpu1t.txt",O_CREAT | O_RDWR | O_TRUNC , 0777);
        if(fd == -1){
            perror("Error dans open syscalls");
            exit(1);
        }

        start_time = clock(); // Enregistrer le temps de début
        for(int i = 0; i < 5000000; i++){
            write(fd, &i, sizeof(int));
        }
        end_time = clock(); // Enregistrer le temps de fin
        close(fd);
    }
    else{
        FILE* fd = fopen("outpu1t.txt", "wb");
        if (fd == NULL) {
            perror("Problème"); // message lié à errno
            exit(1);
        }

        start_time = clock(); // Enregistrer le temps de début
        for(int i = 0; i < 5000000; i++){
            fwrite(&i,sizeof(int),1,fd);
        }
        end_time = clock(); // Enregistrer le temps de fin
        fclose(fd);
        
    }
    
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculer le temps écoulé

    printf("Temps pris : %lf secondes\n", elapsed_time); // Afficher le temps pris


}