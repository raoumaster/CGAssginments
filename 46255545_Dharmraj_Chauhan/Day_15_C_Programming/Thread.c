/* 
    Problem statment:   Q1: Main thread to read a line of text and pass it as parameter to 2 new threads created.
                        Q2: Thread1 should count words and return to caller.	
                        Q3: Thread 2 to count characters and return to caller.
                        Q4: Main thread on every child thread exit to retrieve the returned count and display.	
*/

// Importing important input/output library 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#define MAX 100

// funcation for call the 
void* startRoutine1(void* str);
void* startRoutine2(void* str);

int main(){
    char string[MAX];
    
    int *word_count;
    int *character_count;
    
    printf("Enter the String:-");
    fgets(string, MAX, stdin);
    
    pthread_t thread[2];
    
    // Calling startRoutine1 funcation
    pthread_create(&thread[0], NULL, &startRoutine1, string);
    
    // Calling startRoutine2 funcation
    pthread_create(&thread[1], NULL, &startRoutine2, string);
    
    // Thread joining startRoutine1 funcation
    pthread_join(thread[0], (void *)&word_count);
    printf("%d\n",word_count);
    
    // Thread joining startRoutine2 funcation
    pthread_join(thread[1], (void *)&character_count);
    printf("%d\n",character_count);
}


// Function for count the words in string
void* startRoutine1(void* str){
    int totalWords = 0, i = 0;
    char* charArray = (char *)str;
    
    while(i < strlen(charArray)){
        if(charArray[i] == ' ' || charArray[i] == '\n' || charArray[i] == '\0' || charArray[i] == '\t')  
            totalWords++;
        i++;
    }
    
    // thread reaturning as total value
    pthread_exit((void*) totalWords);    
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
