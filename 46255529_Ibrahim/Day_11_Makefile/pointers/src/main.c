#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX_LEN 100


int main()
{
    char a[][25] = {"user1", "user2", "user3", "user4"};
    char (*ptr) [25] = a;
    
    // swapping
    int n;
    printf("\n Enter postion you want to replace");
    scanf("%d",&n);
    ptr = ptr+n;
    char *x=a;
    char *y=ptr;
    printf("x=%s y=%s\n",x,y);
    swap(&x,&y);
    printf("x=%s y=%s\n",x,y);
    
    // vowel indentifier
    char vowel;
    printf("\n Enter postion of char you want to identify");
    scanf(" %c",&vowel);
    printf("\n Enter char %c", vowel);
    printf("\n Vowel(s) is:- %d", isVowel(vowel));
    
    // indexing vowel checking
    char vc[MAX_LEN];
    printf("\n Enter the string to identify");
    scanf("%s",vc);
    printf("\n Enter string from user : %s", vc);
    printf("Vowels removed:- %s", remove_vowel(vowel, 1));
    
    //concatenation of 2 strings
    char strc1[MAX_LEN];
    char strc2[MAX_LEN];
    printf("\n\n Enter the string you want to concat");
    scanf("%s",strc1);
    scanf("%s",strc2);
    printf("\n Entered string is %s\t %s", strc1, strc2);
    printf("\Concatenated string is:- %s", mystrcat(strc1, strc2));
    return 0;
}
