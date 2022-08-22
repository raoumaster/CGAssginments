/* fptr 1 :
 * Program to compare 2 strings and return the longer string
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

void min(int p, int q)
{
	printf("%d",p<q?p:q);
}

void max(int p, int q)
{
	printf("%d",p>q?p:q);
}

void getLongstring(char *str1, char *str2)
{
	printf("Longest String : %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
}

int main()
{ 
	char str1[MAX];
	char str2[MAX];
	void (*fp)(char*, char*);

	printf("Enter first string : ");
	fgets(str1, MAX, stdin);
	printf("Enter second string : ");
	fgets(str2, MAX, stdin);
	str1[strcspn(str1, "\n")] = 0;
	str2[strcspn(str2, "\n")] = 0;

	fp = getLongstring;
	fp(str1, str2);
	return 0;
}
