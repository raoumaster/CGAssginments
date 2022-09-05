/*
    Quest:-
    char arr[][MAX]={“user1”, “user2”, “user3”, “user4”};
        Q1: char *swap_elements(<i/p array>, <index>) should swap the content of first element with contents of element at  given index.
        Q2: int isVowel(<char to test>) should return EXIT_SUCCESS for vowel character and EXIT_FAILURE for non-vowel character
        Q3: char *remove_vowel(<i/p array>, <index>) should process the string at given index in array, remove all vowel characters, shift the remaining non-vowel characters.
        Q4: char *mystrcat(char *s1, char *s2 ) should concat s2 with s1 and return the address of s1 without using strcat()
        Q5: Should implement display() to traverse and display the contents of array.
*/

#include <stdio.h> 
#include<stdlib.h>
#include<string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX 100

//swapping first element with element at given index
void swap_elements(char (*ptr)[MAX], int postion){
    char *first = *ptr;
    char *sec = *(ptr+ postion);
    char *temp = NULL;
    
    temp = first;
    first = sec;
    sec = temp;
    
    printf("\nAnswer:");
    printf("First = %s, Second = %s\n", first, sec);
}

// checking for vowel or non-vowel
int isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
		ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	    return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

// remove all vowel characters and shift the remaining non-vowel characters
char* remove_vowel(char (*ptr)[MAX], int index){
    ptr = ptr + index;
    char str[MAX] = "";
    strcpy(str, *ptr);
    
    char new_str[MAX];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isVowel(str[i]) == 1) {             
                new_str[j] = str[i];
                j++;
        }
    }
    
    new_str[j] = '\0';
    strcpy(*ptr, new_str);
    
    return *ptr;
}

//concating two strings
char *mystrcat(char *s1, char *s2){
    for(int i = 0; s1[i] != '\0'; i++); 
    for(int j = 0; s2[j] != '\0'; j++, i++)
    {
        s1[i] = s2[j];
    	}
    s1[i] = '\0';
    
    return s1;
}

//display the contents of array
void display(char (*ptr)[MAX]){
    for(int i = 0; i < 4; i++)
        printf("%s\n", *(ptr + i));
}

int main()
{
    char arr[][MAX] = {"perosn1", "perosn2", "perosn3", "perosn4"};
    char (*ptr)[MAX] = arr;

    //	for swapping elements
    int postion;
    printf("Enter Postion you want to be replace: ");
    scanf("%d", &postion);
    swap_elements(ptr, postion);
    
    //	for vowel checking
    char ch;
    printf("\nEnter character you want to be check for vowel: ");
    scanf(" %c", &ch);
    printf("\nEntered character is: %c\n\n", ch);
    if(isVowel(ch) == 0)
        printf(" %c is a vowel.", ch);
    else
        printf(" %c is not a vowel.", ch);
    
    //	remove all vowels
    int index;
    printf("\n\nEnter index of string which all vowels want to be remove: ");
    scanf("%d", &index);
    printf("\nString before deleting vowels: %s\n", *(ptr + index));
    printf("\nString after deleting vowels: %s\n", remove_vowel(ptr, index));
    
    //	For join the two strings
    char s1[MAX];
    char s2[MAX];
    printf("\nEnter the strings you want to be join.\n");
    printf("Enter the 1st string: ");
    scanf("%s",s1);
    printf("Enter the 2nd string: ");
    scanf("%s",s2);
    printf("\nAfter the join the string: %s\n\n", mystrcat(s1, s2));
    
    printf("Contents of array: \n");
    display(ptr);
    
    return 0;
}
