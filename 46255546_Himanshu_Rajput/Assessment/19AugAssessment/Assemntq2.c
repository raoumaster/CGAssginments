/* 2. Write a program to accept a string and character and do the following operations in separate threads
    1. without using the string library function search for the character in the string
    2. if the character is vowel, replace the vowel with uppercase character in the string aeiou should be AEIOU
------------------------------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



#define STR_SIZE 100
    
char *strinp; // string entered hello world
char charinp; // character entered l
pthread_mutex_t mt = PTHREAD_MUTEX_INITIALIZER;


void* charsearch(){
    int flag = 0;
    for (int i = 0; i < strlen(strinp); i++) {
        pthread_mutex_lock(&mt);
        if(*(strinp + i) == charinp){
            flag = i+1;
        }
        pthread_mutex_unlock(&mt);
    }
    
    if (flag == 0){
        printf("\nDoesn't find the char in string");
    } else {
        printf("\nFind the %c at %d", charinp, flag);
    }
    pthread_exit(0);
}



void* vowelreplace() {
    for (int i = 0; i < strlen(strinp); i++) {
        pthread_mutex_lock(&mt);
        char ch = *(strinp + i);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            *(strinp + i) -= 32;
        }
    pthread_mutex_unlock(&mt);
    }
    printf("\nAfter updating the string:- %s", strinp);
    pthread_exit(0);
}

int main(int argc, char* argv[]) {
    
    pthread_t th1; // search the char in string
    pthread_t th2; // change lower case vowel into uppercase
    pthread_t th3; // reverse the string and add at the the end of the string
    

   // Taking input "string" and "character" from the user
    // strinput = "hello world"
    // charinput = "l"
    
    strinp = malloc(STR_SIZE*sizeof(char));
    printf("Please enter the string:- ");
    fgets(strinp, STR_SIZE, stdin);
    printf("Enterd name:- %s", strinp);
    fflush(stdin);

    printf("Please enter the char:- ");
    scanf("%c", &charinp);
    printf("Enterd char:- %c", charinp);
    
    if (pthread_create(&th1, NULL, &charsearch, NULL) != 0) {
        perror("Failed to create thread");
    }
    

   if (pthread_create(&th2, NULL, &vowelreplace, NULL) != 0) {
        perror("Failed to create thread");
    }
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    pthread_mutex_destroy(&mt);
    return 0;
}
