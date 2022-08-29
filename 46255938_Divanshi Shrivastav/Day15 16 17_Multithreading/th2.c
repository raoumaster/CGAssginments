#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAX 50

int counter=0;
pthread_mutex_t mutex;

void* pd(void* str){
        char *stp1 = (char *) str;
        int length = strlen(stp1);

        int flag=0;

        printf("%s\t",stp1);

        for(int i=0;i<length;i++){
                if(stp1[i] != stp1[length-i-1]){
                        flag=1;
                        break;
                }
        }

        if(flag){
                printf("not plaindrome\n");
        }
        else{
                printf("is a plaindrome\n");
                pthread_mutex_lock(&mutex);
                counter++;
                pthread_mutex_unlock(&mutex);
        }

        return NULL;
}

int main(int argc, char* argv[]){
        if(argc>2){
                int th=argc-1;
                pthread_t thread[th];
                for(int i=1;i<argc;i++){
                        //printf("%s\n",argv[i]);
                        pthread_create(&thread[i],NULL,&pd,argv[i]);
                        pthread_join(thread[i],NULL);
                }
                printf("Global counter: %d\n",counter);

        }
        else{
                printf("Enter arguments greater than or equal to 2");
        }
}