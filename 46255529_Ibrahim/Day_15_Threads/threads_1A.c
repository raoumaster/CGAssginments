/*Program to
--Read a line of text and pass it as parameter to 2 new threads created.
--Count words and return to caller.
--Count characters and return to caller*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t t1;
pthread_t t2;

void *thread3(void *args)
{
    int count3 = 0;
    while (count3 < 1000)
    {
        sleep(10);
        printf("\nThread 3: %d", count3);
    }
    return NULL;    
}

void *thread2(void *args)
{
    int count2 = 0;
    while (count2 < 1000)
    {
        printf("\nThread 2: %d", count2);
    }
    return NULL;    
}

int main()
{
    pthread_create(&t1,NULL,thread2,NULL);
    pthread_create(&t2,NULL,thread3,NULL);
    int count1 = 0;
    while (count1 < 1000)
    {
        printf("\nThread 1: %d",count1);
    }
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
}
