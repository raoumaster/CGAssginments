#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define MAX 100

void* startRoutine1(void* str)
{
        int count = 1;
        char *st1 = (char *) str;
        for(int i=0;st1[i] != '\0'; i++)
	{
                if(st1[i] == ' ' && st1[i+1] != ' ')
		{
                        count++;
                }
        }
        printf("The number of words in line : %d\n",count);
}

void* startRoutine2(void* str)
{
        int count = 0;
        char *st1 = (char *) str;
        for(int i=0; st1[i] != '\0'; i++)
	{
                count++;
        }
        printf("The number of characters in line : %d\n",count);
}

int main(){
        char str[MAX];
        fgets(str,MAX,stdin);
        pthread_t thread1,thread2;
        pthread_create(&thread1,NULL,&startRoutine1,str);
        pthread_create(&thread2,NULL,&startRoutine2,str);
        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
}