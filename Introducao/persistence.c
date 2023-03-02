#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
 #include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

    if (fd <= 0)
    {
        fprintf(stderr, "Erro ao criar/abrir o arquivo.\n");
        return 1;
    }

    int bytesWritten = write(fd, "Hello World\n", 13);

    if (bytesWritten == 13)
    {
        printf("Arquivo escrito com sucesso\n");

        return 0;
    }

    fprintf(stderr, "Os dados não foram escritos corretamente no arquivo.\n");

    return 1;
    
}