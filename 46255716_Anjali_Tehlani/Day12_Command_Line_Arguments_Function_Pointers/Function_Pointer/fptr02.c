/* fptr 2 :
 * Program with function readchoice() to display a menu with 3 choices below.
   Read user choice and return it.
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

void min(int p, int q)
{
	printf("%d\n", p < q ? p : q);
}
void max(int p, int q)
{
	printf("%d\n", p > q ? p : q);
}
void getLongstring(char *str1, char *str2)
{
	printf("The Longest string is: %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
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

	printf("You chose option %d\n", readChoice());

	return 0;
}
