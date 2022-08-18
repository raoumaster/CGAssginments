/*
 * Program with function readchoice() to display a menu with 3 choices.
 * Read user choice and perform the chosen function.
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

	Function getlongstring() to compare 2 strings and return the longest string. 
-------------------------------------------------------------------------------- */
void getlongstring(char *str1, char *str2)
{
	printf("The longer string is: %s\n", strlen(str1) > strlen(str2) ? str1 : str2);
}

/*----------------------------------------------------------------------------
	REQUIREMENT TAG: FPTR/04

	Function getfunc() (to be used with choices 1 or 2 only) and should return
	the corresponding function address as below.
	1- address of min()
	2- address of max() 
------------------------------------------------------------------------------ */
void getFunc(void (*fp)(int, int), int choice)
{
	if(choice == 1)
	{
		printf("Address of min(): %p\n", &fp);
	}
	else
	{
		printf("Address of max(): %p\n", &fp);
	}
}

/*---------------------------------------------------------------------------------------
	REQUIREMENT TAG: FPTR/05

	Function process_numbers() which calls getfunc() (for choice 1 or 2) and then invokes
	the returned function (i.e min() or max()) with given data and returns result.
-----------------------------------------------------------------------------------------*/
void process_numbers(void (*fp)(int, int), int choice)
{
	getFunc(fp, choice);
	int num1
	int num2;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	fp(num1, num2);

}

/*------------------------------------------------------------------------
	REQUIREMENT TAG: FPTR/02

	Function readchoice() to display a menu with 3 choices as shown below.
	Read user choice and return it.
	1.	Get min number
	2.	Get maximum number
	3.	Get longest string
-------------------------------------------------------------------------- */
void readChoice(void (*fp)(int, int), void (*fptr)(char*, char*))
{
	int choice;
	printf("1) Get minimum number\n2) Get maximum number\n3) Get longest string\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	printf("\n");

	switch(choice)
	{
		case 1:
			{
				fp = min;
				process_numbers(fp, choice);
			}
			break;
		case 2:
			{
				fp = max;
				process_numbers(fp, choice);
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
	void (*fp)(int, int);

/* 	------------------------------------------
	REQUIREMENT TAG: FPTR/03
	Function pointer to invoke getlongstring()
	------------------------------------------ */
	void (*fptr)(char*, char*);

	readChoice(fp, fptr);   // Calling the function
	return 0;
}
