/*Program to
--Read a line of text and pass it as parameter to 2 new threads created.
--Count words and return to caller.
--Count characters and return to caller*/

#include <stdio.h>
#include<unistd.h>
#include<pthread.h> 

//including pthread header file to use the subsequent commands.
int count=0;
int wcount=1;


//creating display function to run the thread
void * disp(void * a){
    char * arr=(char*)a;
    printf("The entered string is:%s",arr);
}



//creating word count function to display number of words.
void * wc(void * wc){
    char * arr=(char*)wc;
    int count=1;
     for(int i=0;arr[i]!='\0';i++){
        if(arr[i]==' '){
            wcount ++;
        }
    }
   pthread_exit(NULL);
}



//creating character count function to display number of chracter.

void * cc(void * cc){
    char * arr=(char*)cc;
    
     for(int i=0;arr[i]!='\0';i++){
            count ++;
    }
 pthread_exit(NULL);   
}


int main() {
    char arr[100];    
    pthread_t t0;
    pthread_t t1;
    pthread_t t2;
 
     printf("enter the str:\n");   
   //readind input from the user
     fgets(arr,100,stdin);

   //creating the thread and passing it to resp function.
    pthread_create(&t0,NULL,disp,arr);
    pthread_create(&t1,NULL,wc,arr);
    pthread_create(&t2,NULL,cc,arr);
    pthread_join(t0,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("The word count is : %d \n",wcount);
    printf("The chracter count is : %d \n",count-1); //printing the variables.

}