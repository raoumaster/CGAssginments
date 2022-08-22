/* fptr 3 :
 * Program with function readchoice() to display a menu with 3 choices.
 * Read user choice. Prompt and read data after reading choice.
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

void readChoice()
{
	int choice;

	void (*fp)(int, int);
	void (*fptr)(char*, char*);

	printf("1) Get minimum number\n2) Get maximum number\n3) Get longest string\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{ 
		case 1:
			{
				int num1, num2;
				printf("Enter first number: ");
				scanf("%d", &num1);
				printf("Enter second number: ");
				scanf("%d", &num2);
			}
			break;
		case 2:
			{
				int num1, num2;
				printf("Enter first number: ");
				scanf("%d", &num1);
				printf("Enter second number: ");
				scanf("%d", &num2);
			}
			break;
		case 3:
			{
				char str1[MAX];
				char str2[MAX];
				printf("Enter first string: ");
				fgets(str1, MAX, stdin);
				fgets(str1, MAX, stdin);
				printf("Enter second string: ");
				fgets(str2, MAX, stdin);
				str1[strcspn(str1, "\n")] = 0;
				str2[strcspn(str2, "\n")] = 0;

				fptr = getLongstring;
				fptr(str1, str2);
			}
			break;
		default:
			printf("INVALID CHOICE\n");
			break;
	}
}

int main()
{
	readChoice();

	return 0;
}
