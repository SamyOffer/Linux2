#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        write(STDOUT_FILENO, "partez !\n", strlen("partez !\n")); 
    } else {
        write(STDOUT_FILENO, "trois .. deux .. un .. \n", strlen("trois .. deux .. un .. ")); 
    }
    return 0;
}
