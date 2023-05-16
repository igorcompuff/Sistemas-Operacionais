#include <stdio.h>
#include <pthread.h>
#include <assert.h>

static volatile int counter = 0;

void *myThread(void *arg)
{
    printf("%s: inicio\n", (char *)arg);
    for(int i = 0; i < 1e7; i++)
    {
        counter = counter + 1;
    }
    printf("%s: fim\n", (char *)arg);

    return NULL;
}
int main (int argc, char *argv[])
{
    pthread_t t1, t2;
    //int rc;
    printf("main: inicio (counter = %d)\n", counter);
    
    assert(pthread_create(&t1, NULL, myThread, "A") == 0);
    assert(pthread_create(&t2, NULL, myThread, "B") == 0);

    assert(pthread_join(t1, NULL) == 0);
    assert(pthread_join(t2, NULL) == 0);

    printf("main: fim (counter = %d)\n", counter);

    return 0;
}