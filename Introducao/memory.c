#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int soma(int a, int b);

int main (int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    if (p == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória!");
        return 1;
    }
    
    printf("(Processo %d) Endereço apontado por p: %p\n", getpid(), p);

    *p = 0;

    while(1)
    {
        usleep(500* 1000);
        *p = *p + 1;

        printf("(Processo %d) Endereço %p (variável p) contém o valor %d\n", getpid(), p, *p);
    }

    return 0;
}