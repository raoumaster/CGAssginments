/* Program to compare 2 strings and return the longer string */

#include<stdio.h>
#include<string.h>
#define MAX 80

void min(int m, int n)
{
	printf("%d",m<n?m:n);
}

void max(int m, int n)
{
	printf("%d",m>n?m:n);
}

void getlongstring(char *str1, char *str2)
{
	printf("The longer string is: %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
}

int main()
{ 
	char str1[MAX];
	char str2[MAX];
	void (*fp)(char*, char*);

	printf("first string: ");
	fgets(str1, MAX, stdin);
	printf("second string: ");
	fgets(str2, MAX, stdin);
	str1[strcspn(str1, "\n")] = 0;
	str2[strcspn(str2, "\n")] = 0;

	fp = getlongstring;
	fp(str1, str2);
	return 0;
}
