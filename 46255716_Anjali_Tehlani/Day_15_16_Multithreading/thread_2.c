#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX 50

int counter = 0;
pthread_mutex_t mutex;

void* palindrome(void* str)
{
        char *st1 = (char *) str;
        int length = strlen(st1);

        int flag = 0;

        printf("%s\t",st1);

        for(int i=0;i<length;i++)
	{
                if(st1[i] != st1[length-i-1])
		{
                        flag=1;
                        break;
                }
        }

        if(flag)
	{
                printf("not palindrome\n");
        }
        else
	{
                printf("is a palindrome\n");
                pthread_mutex_lock(&mutex);
                counter++;
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}

int main(int argc, char* argv[])
{
        if(argc>2)
	{
                int th1 = argc-1;
                pthread_t thread[th1];
                for(int i=1;i<argc;i++)
		{
                        //printf("%s\n",argv[i]);
                        pthread_create(&thread[i],NULL,&palindrome,argv[i]);
                        pthread_join(thread[i],NULL);
                }
                printf("Global counter: %d\n",counter);

        }
        else
	{
                printf("Enter arguments greater than or equal to 2");
        }
}