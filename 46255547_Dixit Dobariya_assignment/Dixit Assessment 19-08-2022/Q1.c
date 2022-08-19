/* 1. write a program that accepts a number to a global variable and do the following operations based on the user input. use synchronization to block the other threads accessing the global variable
 
    1. Factorial : the function should calculate and return the factorial of the given number (do not use recursion)
    2. Palindrome : check if the number is palindrome or not and return true or false
    3. if the given number is a single digit number, print a triangle of * from 1 to the number
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int number=0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void *factorial()
{
        int f=1,num;
        pthread_mutex_lock( &mutex1 );
        num = number;
        printf("Entering factorial...\n");
        for(int i=1;i<=num;i++)
        {
                f = f*i;
        }
        printf("factorial of the %d is : %d ",num,f );

        pthread_exit(NULL);
        pthread_mutex_unlock( &mutex1 );
        number=0;
}


void *pallindrome()
{
        int num;
        pthread_mutex_lock( &mutex1 );
        num = number;
        int reminder, reversed;
        int original = number;
        while (num != 0) {
                reminder = num % 10;
                reversed = reversed * 10 + reminder;
                num /= 10;
        }
        if (original == reversed)
                printf("TRUE\n");
        else
                printf("FALSE\n");

        pthread_exit(NULL);
        pthread_mutex_unlock( &mutex1 );
        number=0;
}


void* pattern()
{
                pthread_mutex_lock( &mutex1 );
                printf("\n");
                printf("single Digit Input...\n");
                int m,n;
                n=number;
                m=n;
                for(int i=1;i<=n;i++)
                {
                        for(int j=1;j<=m-1;j++)
                        {
                                printf(" ");
                        }
                        for(int k=1;k<=2*i-1;k++)
                        {
                                printf("*");
                        }
                        m--;

                        printf("\n");
                }
                return 0;
                pthread_mutex_unlock( &mutex1 );
                number = 0;
}


int main()
{
        int ch;
        printf("Enter the number:");
        scanf("%d",&number);
        if(number >9){
                printf("Enter the choice:");
                scanf("%d",&ch);

                        switch(ch){
                        case 1:
                                if(number > 9)
                                {
                                        pthread_t thread;

                                        {
                                                pthread_create(&thread, NULL,&pallindrome, NULL);
                                                pthread_join(thread, NULL);
                                        }

                                }
                                break;

                                case 2:
                                if(number > 9)
                                {

                                        pthread_t thread;

                                        {
                                                pthread_create(&thread, NULL,&factorial, NULL);
                                                pthread_join(thread, NULL);
                                        }

                                }
                                break;

                                default:
                                printf("Invalid input..");

                }
        }
        else{
                        pthread_t thread;

                                        {
                                                pthread_create(&thread, NULL,&pattern, NULL);
                                                pthread_join(thread, NULL);
                                        }


        }
}