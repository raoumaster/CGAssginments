/*
  write a program which opens a file given as command line argument and does the following operations in separate functions, with thread synchronization.
 
    1. count the number of characters
    2. count the number of words
    3. count the number of lines
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;



void *countChar(void *argv)
{
        pthread_mutex_lock( &mutex );



        FILE *fp;
        int count = 0;
        char chr;
        fp = fopen((char *)argv, "r");
        chr = fgetc(fp);



        while (chr != EOF){
                count++;

                if (chr == '\n'){
                        count--;
                        count--;
                }
                chr = fgetc(fp);
        }



        fclose(fp);
        printf("There are %d characters.\n", count);



        pthread_mutex_unlock( &mutex );
}



void *countWords(void *argv)
{
        pthread_mutex_lock( &mutex );



        FILE *fp;
        int count = 0;
        char chr;
        fp = fopen((char *)argv, "r");
        chr = fgetc(fp);
        while (chr != EOF){

                if (chr == '\n' || chr == ' '){
                        count++;
                }
                chr = fgetc(fp);
        }
        fclose(fp);
        printf("There are %d words.\n", count+1);



        pthread_mutex_unlock( &mutex );
}



void *countLines(void *argv)
{
        pthread_mutex_lock( &mutex );



        FILE *fp;
        int count = 0;
        char chr;
        fp = fopen((char *)argv, "r");
        chr = fgetc(fp);



        while (chr != EOF){
                if (chr == '\n'){
                        count++;
                }
                chr = fgetc(fp);
        }
        fclose(fp);
        printf("There are %d lines.\n", count+1);



        pthread_mutex_unlock( &mutex );
}



int main(int argc, char *argv[])
{
        int rc1;
        int rc2;
        int rc3;

        pthread_t thread1;
        pthread_t thread2;
        pthread_t thread3;


        if( (rc1=pthread_create( &thread1, NULL, &countChar, argv[1])) )
        {
                printf("Thread creation failed: %d\n", rc1);
        }


        if( (rc2=pthread_create( &thread2, NULL, &countWords, argv[1])) )
        {
                printf("Thread creation failed: %d\n", rc2);
        }



        if( (rc3=pthread_create( &thread3, NULL, &countLines, argv[1])) )
        {
                printf("Thread creation failed: %d\n", rc3);
        }

        pthread_join( thread1, NULL);
        pthread_join( thread2, NULL);
        pthread_join( thread3, NULL);



        exit(0);
}