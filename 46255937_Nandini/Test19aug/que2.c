#include <stdio.h>

#include <string.h>

#include <unistd.h>

#include <pthread.h>

#include <string.h>

#define MAX 20



void *search(void *str){

        char *arr1 = (char*)str;

        char c;

        printf("Enter the character ");

        scanf("%c",&c);



        for(int i=0;arr1[i] !='\0';i++)

        {

                if(c==arr1[i])

                {

                        printf("Character is matched at %d position \n", i+1);

                }

        }

}



void *vowel(void *str){

        char *arr2 = (char*)str;



        for(int i=0;arr2[i] !='\0';i++)

        {

                if(arr2[i]=='a' || arr2[i]=='e' || arr2[i]=='i' || arr2[i]=='o' || arr2[i]=='u')

                {

                        int a=arr2[i];

                        a=a-32;

                        char x=(char)a;

                        arr2[i]=x;

                }

        }

        printf("%s",arr2);

}



int main()

{

        char str[MAX];

        printf("Enter the String: ");

        fgets(str, MAX, stdin);

        pthread_t t1;

        pthread_create(&t1, NULL, &search, str);

        pthread_join(t1,NULL);

        pthread_t t2;

        pthread_create(&t2,NULL,&vowel,str);

        pthread_join(t2,NULL);

}