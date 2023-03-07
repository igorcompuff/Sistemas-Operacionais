#include <stdlib.h>
#include <stdio.h>

int soma(int, int);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: soma <valor 1> <valor 2>\n");
        return 1;
    }

    int val1 = atoi(argv[1]);
    int val2 = atoi(argv[2]);

    int resultado = soma(val1, val2);

    printf("\n\nO resultado é %d\n\n", resultado);

    return 0;
}

