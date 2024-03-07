#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int value;

int soma(int a, int b);

int main (int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: mem <value>\n");
        exit(1);
    }
    
    //int *p = malloc(sizeof(int));
    int *p = &value;
    
    printf("(pid %d) endereço de p: %llx\n", (int) getpid(), (unsigned long long) &p);
    printf("(pid %d) endereço armazenado em p: %llx\n", (int) getpid(), (unsigned long long) p);

    *p = atoi(argv[1]);

    while(1)
    {
        usleep(500* 1000);
        *p = *p + 1;

        printf("(pid %d) Valor de p: %d\n", getpid(), *p);
    }

    return 0;
}

