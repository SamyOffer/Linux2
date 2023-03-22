#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "utils_v2.c"

void run(void *argv)
{
  // On est dans l'enfant
  int *pipefd = argv;

  // 3/ Cloture du descripteur d'écriture
  int ret = close(pipefd[1]);
  checkNeg(ret, "close error");

  // 4/ Lecture des caractères dans le pipe, conversion en majuscules et affichage
  char c;
  while (read(pipefd[0], &c, sizeof(char)) > 0) {
    putchar(toupper(c));
  }

  // 5/ On clôture le côté lecture du pipe
  ret = close(pipefd[0]);
  checkNeg(ret, "close error");
}

int main(int argc, char **argv)
{
  // 1/ Création du pipe
  int pipefd[2];
  int ret = pipe(pipefd);
  checkNeg(ret, "pipe error");

  // 2/ Création de l'enfant
  int child_pid = fork_and_run1(run, pipefd);
  printf("pid fils = %d\n", child_pid);

  // On est dans le parent (voir code fork_and_run)
  // 3/ Cloture du descripteur pour l'écriture
  ret = close(pipefd[0]);
  checkNeg(ret, "close error");

  // 4/ Lecture des caractères depuis l'entrée standard (clavier), écriture dans le pipe
  char c;
  while (scanf("%c", &c) == 1) {
    ret = write(pipefd[1], &c, sizeof(char));
    checkCond(ret != sizeof(char), "write error");
  }

  // 5/ On envoie un caractère nul pour indiquer la fin de fichier
  ret = write(pipefd[1], "\0", sizeof(char));
  checkCond(ret != sizeof(char), "write error");

  // On attend la mort du fils
  int status;
  swaitpid(child_pid, &status, 0);
  
  printf("Le fils est mort\n");

  // 6/ On clôture le côté lecture du pipe
  ret = close(pipefd[1]);
  checkNeg(ret, "close error");
}
