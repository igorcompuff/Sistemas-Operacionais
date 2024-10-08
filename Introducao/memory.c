#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{   
    int *p = malloc(sizeof(int));
    
    if (p == NULL) {
        fprintf(stderr, "Erro ao alocar memoria.");
        return 1;
    }
    
    
    printf("(pid %d) endereço de p: %p\n", (int) getpid(), &p);
    printf("(pid %d) endereço armazenado em p: %p\n", (int) getpid(), p);

    *p = 0;

    while(1)
    {
        usleep(500* 1000);
        *p = *p + 1;

        printf("(pid %d) Valor apontado por p: %d\n", getpid(), *p);
    }

    return 0;
}