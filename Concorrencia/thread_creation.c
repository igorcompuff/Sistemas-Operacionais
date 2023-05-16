#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void *myThread(void *arg)
{
    printf("%s\n", (char *)arg);
    return NULL;
}

int main (int argc, char *argv[])
{
    pthread_t t1, t2;
    //int rc;
    puts("main: inicio\n");
    assert(pthread_create(&t1, NULL, myThread, "A") == 0);
    assert(pthread_create(&t2, NULL, myThread, "B") == 0);

    assert(pthread_join(t1, NULL) == 0);
    assert(pthread_join(t2, NULL) == 0);

    puts("main: fim\n");

    return 0;
}
