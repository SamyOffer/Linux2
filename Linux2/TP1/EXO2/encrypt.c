#include <stdio.h>
#include <stdlib.h>
#include "crypt.h"
#include "utils_v1.h"

/* main.c */
int main(int argc, char *argv[]) {
    char* lineRead = readLine();
    char* result = encrypt(lineRead);
    printf("%s", result);
}