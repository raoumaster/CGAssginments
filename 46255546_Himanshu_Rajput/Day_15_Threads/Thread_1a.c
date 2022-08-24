/* 
    Q1: Main thread to read a line of text and pass it as parameter to 2 new threads created.
    Q2: Thread1 should count words and return to caller.	
    Q3: Thread 2 to count characters and return to caller.
    Q4: Main thread on every child thread exit to retrieve the returned count and display.	
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define MAX 100

//function for count words
void* startRoutine1(void* str){
    int totalWords = 0, i = 0;
    char* charArray = (char *)str;
    
    while(i < strlen(charArray)){
        if(charArray[i] == ' ' || charArray[i] == '\n' || charArray[i] == '\0' || charArray[i] == '\t')  
            totalWords++;
        i++;
    }
    
    pthread_exit((void*) totalWords);    //thread exit with total words
}

//function for count characters
void* startRoutine2(void* str){
    int totalCharacters = 0, i = 0;
    char* charArray = (char *)str;
    
    while(i < strlen(charArray)){
        if(charArray[i] != ' ')  
            totalCharacters++;
        i++;
    }
    totalCharacters = totalCharacters - 1;
    
    pthread_exit((void*) totalCharacters);    //thread exit with total characters
}

int main()
{
    char string[MAX];
    
    int *word_count;
    int *character_count;
    
    printf("Enter your String: ");
    fgets(string, MAX, stdin);
    
    pthread_t thread[2];
    
    pthread_create(&thread[0], NULL, &startRoutine1, string);
    pthread_create(&thread[1], NULL, &startRoutine2, string);
    
    pthread_join(thread[0], (void *)&word_count); 
    printf("%d\n",word_count);
    pthread_join(thread[1], (void *)&character_count);
    printf("%d\n",character_count);
}
