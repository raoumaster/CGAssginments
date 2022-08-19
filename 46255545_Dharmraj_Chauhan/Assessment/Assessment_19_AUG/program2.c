/*
2. Write a program to accept a string and character and do the following operations in separate threads
    1. without using the string library function search for the character in the string
    2. if the character is vowel, replace the vowel with uppercase character in the string aeiou should be AEIOU
    3. reverse the string and add the character to the end of the string (optional), if you have time try this
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define STR_SIZE 100
    
char *strinput; // hello world
char charinput; // e
pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;

/*
charsearch takes an input string and input char and found the char in the string
*/

void* charsearch(){
    int flag = 0;
    pthread_mutex_lock(&mx);
    for (int i = 0; i < strlen(strinput); i++) {
        if(*(strinput + i) == charinput){
            flag = i+1;
            break;
        }
    }
    pthread_mutex_unlock(&mx);
    
    if (flag == 0){
        printf("\nDoesn't find the char in string");
    } else {
        printf("\nFind the %c at %d", charinput, flag);
    }
    pthread_exit(0);
}

/*
charsearch takes an input string and input char and found the char in the string
*/

void* vowelreplace() {
    for (int i = 0; i < strlen(strinput); i++) {
        pthread_mutex_lock(&mx);
        char ch = *(strinput + i);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            *(strinput + i) -= 32;
        }
        pthread_mutex_unlock(&mx);
    }
    printf("\nAfter updating the string:- %s", strinput);
    pthread_exit(0);
}

/*
strrep takes an input string and input char and replace the string in the string
*/

void* strrep() {
    int len = strlen(strinput);
    for (int i = 0; i < len/2; i++) {
        pthread_mutex_lock(&mx);
        char temp = *(strinput+i);
        *(strinput+i) = *(strinput+len-1-i);
        *(strinput+len-1-i) = temp;
        pthread_mutex_unlock(&mx);
    }
    
    // to add the char at last position
    *(strinput+len) = charinput;
    
    printf("\nAfter updating the string:- %s", strinput);
    pthread_exit(0);
}

int main(int argc, char* argv[]) {
    
    pthread_t th1; // for search the char in string 
    pthread_t th2; // for replace small letter vowel with upper letter
    pthread_t th3; // reverse the string and add new character at the end of the string
    
    /*  
    Taking input "string" and "character" from the user 
    strinput = "hello world"
    charinput = "h" 
    */
    
	strinput = malloc(STR_SIZE*sizeof(char));
    
    // 	printf("Please enter the string:- ");
	fgets(strinput, STR_SIZE, stdin);
	printf("Enterd name:- %s", strinput);
    fflush(stdin);
    
    // printf("Please enter the char:- ");
    scanf("%c", &charinput);
    printf("Enterd char:- %c", charinput);
    
    if (pthread_create(&th1, NULL, &charsearch, NULL) != 0)
        perror("Failed to create thread");
    sleep(1);

    if (pthread_create(&th2, NULL, &vowelreplace, NULL) != 0)
        perror("Failed to create thread");
    sleep(1);

    if (pthread_create(&th3, NULL, &strrep, NULL) != 0)
        perror("Failed to create thread");
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    
    pthread_mutex_destroy(&mx);
    return 0;
}
