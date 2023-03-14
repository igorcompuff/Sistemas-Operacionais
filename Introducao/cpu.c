#include <stdio.h>
#include <unistd.h>

int soma(int a, int b);

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu <string>\n");
    }

    char *str = argv[1];
    
    while (1)
    {
        usleep(500* 1000);
        printf("%s\n", str);
    }

    return 0;
}

