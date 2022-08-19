/*
 Program with function readchoice() to display a menu with 3 choices.
 Read user choice and perform the chosen function.
 */

#include<stdio.h>
#include<string.h>
#define MAX 80

void min(int a, int b)
{
	printf("Minimum number: %d\n", a < b ? a : b);
}
void max(int a, int b)
{
	printf("Maximum number: %d\n", a > b ? a : b);
}

/*------------------------------------------------------------------------------
	REQUIREMENT TAG: FPTR/01
	Function getlongstring() to compare 2 strings and return the longest string.  */
void getlongstring(char *str1, char *str2)
{
	printf("The longer string is: %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
}




	// REQUIREMENT TAG: FPTR/02

void readChoice(void (*fptr)(int, int), void (*fptr)(char*, char*))
{
	int choice;
	printf("1) Get minimum number\n2) Get maximum number\n3) Get longest string\n");
	printf("Enter your choice: ");
	scanf("%d", &sel);
	printf("\n");

	switch(sel)
	{
		case 1:
			{
				fptr = min;
				process_numbers(fptr, sel);
			}
			break;
		case 2:
			{
				fptr = max;
				process_numbers(fptr, sel);
			}
			break;
		case 3:
			{
				char str1[MAX];
				char str2[MAX];

				printf("Enter first string: ");
				fgets(str1, MAX, stdin);
				fgets(str1, MAX, stdin);
				str1[strcspn(str1, "\n")] = 0;

				printf("Enter second string: ");
				fgets(str2, MAX, stdin);
				str2[strcspn(str2, "\n")] = 0;

				fptr = getlongstring;
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
	void (*fpt)(int, int);

/* 	------------------------------------------
	REQUIREMENT TAG: FPTR/03 Function pointer to invoke getlongstring() */

	void (*fptr)(char*, char*);

	readChoice(fpt, fptr);   // Calling the function
	return 0;
}

/*-------------------------------------------------
 requirement: FPTR/04 */
	

void getFun(void (*fptr)(int, int), int sel)
{
	if(sel == 1)
	{
		printf("Address of min(): %p\n", &fptr);
	}
	else
	{
		printf("Address of max(): %p\n", &fptr);
	}
}

/*------------------------------------------------
	REQUIREMENT TAG: FPTR/05 */
	

void process_numbers(void (*fptr)(int, int), int sel)
{
	getFunc(fptr, sel);
	int num1
	int num2;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	fp(num1, num2);

}