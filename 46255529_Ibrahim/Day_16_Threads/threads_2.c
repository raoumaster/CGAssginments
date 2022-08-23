/*Program to
--Validate the number of received arguments
--Create as many threads as input words, pass each thread with a word
--Write a function isPalindrome() to receive a word, check for palindrome*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int counter = 0;
pthread_mutex_t mutex;

void *isPalindrome(void *str)
{
    char *pstr = (char *)str;
    int length = strlen(pstr); //Lentgh of the given String
    //Flag = 0 --> Palindrome | Flag = 1 --> Not a Palindrome
    int flag = 0; //Flag to Check if it is a Palindrome
    printf("%s ",pstr);
    for(int i = 0; i < length; i++)
    {
        if(pstr[i] != pstr[length-i-1])
        {
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        printf("Not a Palindrome\n");
    }
    else
    {
        printf("is a Palindrome\n");
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        int size = argc - 1;
        pthread_t thread[size];
        for(int i = 0; i < argc; i++)
        {
            //printf("%s",argv[i]);
            pthread_create(&thread[i], NULL, *isPalindrome, argv[i]);
            pthread_join(thread[i], NULL);
        }
        printf("Global Counter: %d\n", counter);
    }
    else
    {
        printf("Invalid Number of Arguments");
    }
    
}
