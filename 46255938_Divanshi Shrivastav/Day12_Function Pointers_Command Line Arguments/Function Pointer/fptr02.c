/* Program with function readchoice() to display a menu with 3 choices below.
   Read user choice and return it. */

#include<stdio.h>
#include<string.h>
#define MAX 80

void min(int m, int n)
{
	printf("%d\n", m < n ? m : n);
}
void max(int m, int n)
{
	printf("%d\n", m > n ? m : n);
}
void getlongstring(char *str1, char *str2)
{
	printf("The longer string is: %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
}

int readChoice()
{
	int choice;
	printf("1) Get minimum number\n2) Get maximum number\n3) Get longest string\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		default:
			printf("INVALID CHOICE\n");
			return 0;
	}
}

int main()
{
	int num1, num2;
	char str1[MAX];
	char str2[MAX];
	void (*fptr)(char*, char*);
	void (*fp)(int, int);

	printf("Your option %d\n", readChoice());

	return 0;
}
