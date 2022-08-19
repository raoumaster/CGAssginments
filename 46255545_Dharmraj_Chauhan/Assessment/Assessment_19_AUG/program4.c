/* 
Quest(4)  write a program which opens a file given as command line argument and does the following operations in separate functions, with thread synchronization.
          1. count the number of characters
          2. count the number of words
          3. count the number of lines 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // init mutex lock

/*
countChar takes an input file and count the char of the file
*/

void* countChar(void* source){
    int totalCharacters = 0;
    char ch;
    
    FILE* src = fopen(source, "r");
    while((ch = fgetc(src)) != EOF){
        pthread_mutex_lock(&lock);
        totalCharacters++;
        pthread_mutex_unlock(&lock);
    }
    
    fclose(src);
    printf("Total Characters of the file: %d \n", totalCharacters);
    pthread_exit(0);
}

/*
countWord takes an input file and count the word of the file
*/

void* countWord(void* input){
    int tWord = 0;
    char word;
    FILE* src = fopen(input, "r");
    
    while((word = fgetc(src)) != EOF){
        pthread_mutex_lock(&lock);
        if(word == ' ' || word == '\n' || word == '\0' || word == '\t')  
            tWord++;
        pthread_mutex_unlock(&lock);
    }  
    
    fclose(src);
    printf("Total Words of the file: %d \n", tWord);
    pthread_exit(0);
}

/*
countChar takes an input file and count the line of the file
*/

void* countLine(void* source){
    int tLines = 0;
    char line;
    FILE* src = fopen(source, "r");
    
    while((line = fgetc(src)) != EOF){
        pthread_mutex_lock(&lock);
        if(line =='\n' || line == '\0')  
            tLines++;
        pthread_mutex_unlock(&lock);
    }  
    fclose(src);
    printf("Total Lines of the file: %d \n", tLines);
    pthread_exit(0);
}

/*
Main creates three threads and waits for them to exit
All of thread are work individial
*/

int main(int argc, char* argv[]) {
    pthread_t th1; // for count line 
    pthread_t th2; // for count the words in the file
    pthread_t th3; // for count the lines in the file
    
    // Running the threads and give 1 sec to run in sync manner
    if (pthread_create(&th1, NULL, &countChar, argv[1]) != 0)
        printf("Failed to create thread");
    sleep(1);
    
    if (pthread_create(&th2, NULL, &countWord, argv[1]) != 0)
        printf("Failed to create thread");
    sleep(1);
    
    if (pthread_create(&th3, NULL, &countLine, argv[1]) != 0)
        printf("Failed to create thread");
    
    // terminate the all threads
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    
    // destory the mutex
    pthread_mutex_destroy(&lock);
    return 0;
}
