/* fptr 4 :
 * Program with function readchoice() to display a menu with 3 choices.
 * Read user choice. Prompt and should return the corresponding function
 * address if choice is either 1 or 2.
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
	printf("The longer string is: %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
}

void getFunc(void (*fp)(int, int), int choice)
{
	if(choice == 1)
	{
		fp = min;
		printf("Address of min(): %p\n", &fp);	
	}
	else
	{
		fp = max;
		printf("Address of max(): %p\n", &fp);
	}
}

void readChoice(void (*fp)(int, int), void (*fptr)(char*, char*))
{
	int choice;
	printf("1) Get minimum number\n2) Get maximum number\n3) Get longest string\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			{
				getFunc(fp, choice);
			}
			break;
		case 2:
			{
				getFunc(fp, choice);
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
			}
			break;
		default:
			printf("INVALID CHOICE\n");
			break;
	}
}

int main()
{
	void (*fp)(int, int);
	void (*fptr)(char*, char*);
	readChoice(fp, fptr);
	return 0;
}
