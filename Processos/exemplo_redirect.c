#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
    printf("Exibindo prompt do shell\n");
    pid_t pid_filho  = fork();

    if (pid_filho < 0)
    {
        fprintf(stderr, "Não foi possível criar o processo!\n");
        return 1;
    }

    if (pid_filho == 0)
    {
        close(STDOUT_FILENO);
        open("./lsfile", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

        char *childArgs[3] = {"ls", "-la", NULL};

        execvp(childArgs[0], childArgs);
    }
    else
    {
        pid_filho = wait(NULL);
        printf("Execução do shell encerrada\n");
    }

    return 0;
}


