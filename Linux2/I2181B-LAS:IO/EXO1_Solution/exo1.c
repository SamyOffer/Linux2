#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Inclure la bibliothèque time.h

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SYSCALLS 1

static const char* FNAME = "output.bin";
static const int   NB_MAX= 5000000;

/* 
Performance test
write syscall vs fwrite (bufferisation)

Change #DEFINE SYCALLS 
#define SYSCALLS 0 -> write used
#define SYSCALLS 1 -> fwrite used

*/

int main(int argc, char** argv) {
    clock_t start_time, end_time; // Déclarer les variables pour stocker le temps de début et de fin

#if SYSCALLS
printf("sys");
    int out = open(FNAME, O_WRONLY | O_TRUNC | O_CREAT);
    if (out < 0) 
#else 
    FILE* out = fopen(FNAME, "w");
    if (!out)
#endif
    {
        perror("houston on a un probleme");
        exit(42);
    }

    start_time = clock(); // Enregistrer le temps de début

    for (int i = 0; i < NB_MAX; i++) {
#if SYSCALLS    
        int written = write(out, &i, sizeof(int));
        if (written != sizeof(int))
#else
        int written = fwrite(&i, sizeof(int), 1, out);
        if (written != 1)    
#endif
        {
            perror("houston on a un autre probleme");
            exit(24);
        }
    
    }

    end_time = clock(); // Enregistrer le temps de fin

#if SYSCALLS
    close(out);
#else
    fclose(out);
#endif

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculer le temps écoulé

    printf("Temps pris : %lf secondes\n", elapsed_time); // Afficher le temps pris
}
