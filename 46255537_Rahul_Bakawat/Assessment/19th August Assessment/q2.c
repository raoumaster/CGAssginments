// Q2.Write a program to accept a string and character and do the following operations in separate threads
//      1. without using the string library function search for the character in the string
//      2. if the character is vowel, replace the vowel with uppercase character in the string aeiou should be AEIOU
//      3. reverse the string and add the character to the end of the string (optional), if you have time try this




#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


#define STR_SIZE 100
    
char *strinput; // For entering the string
char charinput; // The character to be found
pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;



// pthread_mutex_t mx; // pthread mutex



void* charSearch(){
    int flag = 0;
    for (int i = 0; i < strlen(strinput); i++) {
        pthread_mutex_lock(&mx);
        if(*(strinput + i) == charinput){
            flag = i+1;
        }
        pthread_mutex_unlock(&mx);
    }
    
    if (flag == 0){
        printf("\nDoesn't find the char in string");
    } else {
        printf("\n%c was found at position number %d", charinput, flag);
    }
    pthread_exit(0);
}



void* vowelReplace() {
    for (int i = 0; i < strlen(strinput); i++) {
        pthread_mutex_lock(&mx);
        char ch = *(strinput + i);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            *(strinput + i) -= 32;
        }
    pthread_mutex_unlock(&mx);
    }
    printf("\nAfter updating the string - %s", strinput);
    pthread_exit(0);
}




int main(int argc, char* argv[]) {
    
    pthread_t th1; // for searching the character in a string
    pthread_t th2; // for replacing the vowel in lowercase to uppercase
    pthread_t th3; // reversing the string and adding new character at the end of the string
    
    // pthread_mutex_init(&mx, NULL); // mutex which lock/unlock the thread



    // Taking input "string" and "character" from the user
    // strinput = "hello world"
    // charinput = "h"
    
    strinput = malloc(STR_SIZE*sizeof(char));
    printf("Please enter the string - ");
    fgets(strinput, STR_SIZE, stdin);
    printf("The entered string is %s", strinput);
    fflush(stdin);
    
    printf("Please enter the character to be found - ");
    scanf("%c", &charinput);
    printf("The entered character is %c", charinput);
    
    if (pthread_create(&th1, NULL, &charSearch, NULL) != 0) {
        perror("Failed to create the thread");
    }
    

    if (pthread_create(&th2, NULL, &vowelReplace, NULL) != 0) {
        perror("Failed to create thread");
    }
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    pthread_mutex_destroy(&mx);
    return 0;
}
