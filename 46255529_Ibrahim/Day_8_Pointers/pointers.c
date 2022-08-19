#include <stdio.h> 
#include<stdlib.h>
#include<string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX_LEN 100

 /* Swap function to swap two elements that is storing given element to first and storing first to that index*/
void swap(char **x,char **y){
    char *temp=NULL;
    temp=*x;
    *x=*y;
    *y=temp;
}

/* To check whether the particular character is a vowel or not*/
int isVowel(char ch)
{
    char str[] = "aeiouAEIOU";
    int x = (strchr(str, ch) != NULL);
    if(x == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

/* Function to remove the vowel at the given index*/ 
char *remove_vowel(char s[],int index){
    char t[100];
    int c, d = 0;
    for (c = index; s[c] != '\0'; c++) {
        if (isVowel(s[c]) == 1) {     // If not a vowel
            t[d] = s[c];
            d++;
            }
        }
    t[d] = '\0';
    strcpy(s, t);  // Changing the starting of the string
    printf("\nString after deleting vowels: %s\n", t);
    return strdup(&t);
}


char *mystrcat(char *s1, char *s2){
    int i, j;
    for(i=0; s1[i]!='\0'; ++i); 
    for(j=0; s2[j]!='\0'; ++j, ++i)
    {
        s1[i]=s2[j];
    }
    s1[i]='\0';
    printf("\nThe final ans:- %s", s1);
    return strdup(s1);
}

/* Calling all the functions in the main function*/
int main()
{
    char a[][25] = {"user1", "user2", "user3", "user4"};
    char (*ptr) [25] = a;
    
    // Swapping the particular index
    int n;
    printf("Enter postion u want to replace");
    scanf("%d",&n);
    ptr = ptr+n; 
    char *x=a;
    char *y=ptr;
    printf("x=%s y=%s\n",x,y);
    swap(&x,&y);
    printf("x=%s y=%s\n",x,y);
    
    // Checking for the vowel
    char vw;
    printf("\nEnter postion char want to identify");
    scanf(" %c",&vw);
    printf("\nEnter char is %c", vw);
    printf("\nAns:- %d", isVowel(vw));
    
    // Particular index for the vowel
    char vc[MAX_LEN];
    printf("\nEnter the string want to identify");
    scanf("%s",vc);
    printf("\nEntered string is %s", vc);
    printf("Ans:- %s", remove_vowel(vc, 1));
    
    //Taking two inputs from user
    char strc1[MAX_LEN];
    char strc2[MAX_LEN];
    printf("\n\nEnter the string want to concat");
    scanf("%s",strc1);
    scanf("%s",strc2);
    printf("\nEntered string is %s\t %s", strc1, strc2);
    printf("\nAns:- %s", mystrcat(strc1, strc2));
    return 0;
}