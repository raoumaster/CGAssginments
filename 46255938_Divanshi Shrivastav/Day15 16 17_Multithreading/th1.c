#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#define MAX 100

/* In thread1 it will count words and return to caller.
here startRt1() will receive a line of text and count words. */

void* startRt1(void* str){
        int count=1;
        char *sp1 = (char *) str;
        for(int i=0;sp1[i] != '\0'; i++){
                if(sp1[i] == ' ' && sp1[i+1] != ' '){
                        count++;
                }
        }
        printf("Words present in the line:  %d\n",count);
}
/* In thread2 it will count characters and return to caller */

void* startRt2(void* str){
        int count = 0;
        char *sp1 = (char *) str;
        for(int i=0; sp1[i] != '\0'; i++){
                count++;
        }
        printf("Characters present in the line:  %d\n",count);
}

int main(){
        char str[MAX];
        fgets(str,MAX,stdin);
        pthread_t thread1,thread2;
        pthread_create(&thread1,NULL,&startRt1,str);
        pthread_create(&thread2,NULL,&startRt2,str);
        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
}