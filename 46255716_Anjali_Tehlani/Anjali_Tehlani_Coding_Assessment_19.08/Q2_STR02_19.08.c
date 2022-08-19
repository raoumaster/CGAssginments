/*Q 2:
  * Write a program to accept a string and character and do the following operations in separate threads
  * 1. without using the string library function search for the character in the string
  * 2. if the character is vowel, replace the vowel with uppercase character in the string aeiou should be AEIOU
  * 3. reverse the string and add the character to the end of the string (optional), if you have time try this
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 100

struct User
{
        char str[MAX];
        char ch;
};

void *findChar(void *args)
{
        int i;
        int j;
        int c=0;
        char *str1 = ((struct User*)args)->str;
        char ch1 = ((struct User*)args)->ch;

        i=0;
        j=0;
        while(str1[i]!='\0')
        {
                if(str1[i] != ch1)
                        i++;
                else if(str1[i] == ch1)
                {
                        while(ch1 != '\0')
                        {
                                if(str1[i] == ch1)
                                {
                                        i++;
                                        j++;
                                        c++;
                                }
                                else
                                {
                                        //c=0;
                                        break;
                                }
                        }
                }
        }
        if(c!=0)
                printf("\nCharacter is present in the string.\n");
        else
                printf("\nCharacter is absent in the string.\n ");
}

void *convertVowelToUpper(void *args)
{
        char *str1 = ((struct User*)args)->str;
        char ch1 = ((struct User*)args)->ch;
        int n = 0;
        while(str1[n] != '\0')
                n++;

        for (int i = 0; i < n; i++) {
                if(str1[i] == ch1){
                        if (str1[i] == 'a' || str1[i] == 'e'
                                        || str1[i] == 'i' || str1[i] == 'o'
                                        || str1[i] == 'u') {
                                str1[i] = str1[i] - 'a' + 'A';
                        }
                }
        }
        printf("%s", str1);
}

int main()
{
        struct User *s1 = (struct User*)calloc(1, sizeof(struct User));
        printf("Enter a string: ");
        fgets(s1->str, MAX, stdin);
        //printf("\n");
        printf("Enter a character: ");
        scanf("%c", &s1->ch);
        printf("\n");

        pthread_t thread1;
        pthread_t thread2;
        pthread_create(&thread1, NULL, findChar, (void*)s1);
        pthread_join(thread1, NULL);
        pthread_create(&thread2, NULL,convertVowelToUpper, (void*)s1);
        pthread_join(thread2, NULL);
        return 0;
}