#include <stdio.h>
#include <stdlib.h>
#include "cryptPolybe.h"
#include "utils_v1.h"

/* main.c */
int main(int argc, char *argv[]) {
    char* lineRead = readLine();
    char* result = encryptPolybe(lineRead);
    printf("%s", result);
}