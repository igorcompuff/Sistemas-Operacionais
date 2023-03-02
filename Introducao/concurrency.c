#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

volatile int counter = 0;
int loops;

void *worker();

int main(int argc, char *argv[])
{
    pthread_t thread1_tid;
    pthread_t thread2_tid;
    pthread_attr_t attr;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: concurrency <value>\n");
        return 1;
    }

    loops = atoi(argv[1]);
    printf("Valor Inicial: %d\n", counter);

    pthread_attr_init(&attr);

    pthread_create(&thread1_tid, &attr, worker, NULL);
    pthread_create(&thread2_tid, &attr, worker, NULL);

    pthread_join(thread1_tid, NULL);
    pthread_join(thread2_tid, NULL);

    printf("Valor Final: %d\n", counter);

    return 0;
}

void *worker()
{
    int i;

    for (int i = 0; i < loops; i++)
    {
        counter++;
    }

    pthread_exit(0);
}