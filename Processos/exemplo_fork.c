#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char *argv[])
{
    pid_t pid_filho  = fork();

    if (pid_filho < 0)
    {
        fprintf(stderr, "Não foi possível criar o processo!\n");
        return 1;
    }

    if (pid_filho == 0)
    {
        printf("Eu sou o processo filho (PID: %d)\n", (int) getpid());
    }
    else
    {
        printf("Eu sou o processo pai (PID %d).\nMeu processo filho tem PID %d.\n", getpid(), pid_filho);
    }

    return 0;
}