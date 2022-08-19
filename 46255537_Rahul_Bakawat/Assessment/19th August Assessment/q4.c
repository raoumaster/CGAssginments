/*
    Q4: Write a program which opens a file given as command line argument and does the following operations in separate functions, with thread synchronization.
        1 count the number of characters
        2 count the number of words
        3 count the number of lines 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;   //initializing mutex

//for counting the total characters in a file
void* countCharacters(void* source){
    int totalCharacters = 0;
    char ch;
    
    FILE* src = fopen(source, "r");
    
    // while((ch = fgetc(src)) != EOF){
    for (ch = getc(src); ch != EOF; ch = getc(src)){
        pthread_mutex_lock(&lock);
        totalCharacters++;
        pthread_mutex_unlock(&lock);
    }
    
    fclose(src);
    printf("Total Characters: %d \n", totalCharacters);
    
    pthread_exit(0);    //thread exit
}

//for counting total words in a file
void* countWords(void* source){
    int totalWords = 0;
    char word;
    
    FILE* src = fopen(source, "r");
    
    for (word = getc(src); word != EOF; word = getc(src)){
        pthread_mutex_lock(&lock);
        if(word == ' ' || word == '\n' || word == '\0' || word == '\t')  
            totalWords++;
        pthread_mutex_unlock(&lock);
    }  
    
    fclose(src);
    printf("Total Words: %d \n", totalWords);
    
    pthread_exit(0);    //thread exit
}

//for counting total lines in a file
void* countLines(void* source){
    int totalLines = 0;
    char line;
    
    FILE* src = fopen(source, "r");
    
    for (line = getc(src); line != EOF; line = getc(src)){
        pthread_mutex_lock(&lock);
        if(line =='\n' || line == '\0')  
            totalLines++;  
        pthread_mutex_unlock(&lock);
    }  
    
    fclose(src);
    printf("Total Lines: %d \n", totalLines);
    
    pthread_exit(0);  //thread exit
}

/*
    Main function creates 3 threads.
    All of the threads are working individially
*/
int main(int argc, char* argv[]) {
    pthread_t thread[3];     //thread array
    
    //thread1 for counting the characters
    if (pthread_create(&thread[0], NULL, &countCharacters, argv[1]) != 0) {
        printf("Failed to create the thread for counting the characters.");
    }
    sleep(1);
    
    //thread1 for counting the words
    if (pthread_create(&thread[1], NULL, &countWords, argv[1]) != 0) {
        printf("Failed to create the thread for counting the words.");
    }
    sleep(1);
    
    //thread1 for counting the lines
    if (pthread_create(&thread[2], NULL, &countLines, argv[1]) != 0) {
        printf("Failed to create the thread for counting the lines");
    }

    //terminates threads
    for (int i = 0; i < 3; i++) {
        if (pthread_join(thread[i], NULL) != 0) {
            printf("Failed to terminate thread");
        }
    }
    
    //destroy mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}
