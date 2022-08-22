/* Program to get string input from the user using fgets,
 * remove whitespaces from the string and return string without whitespace.
 */
#include<stdio.h>
#include<string.h>
#define MAX 50

void removeWhitespace(char *arr){

	while (arr != NULL) {
		printf("%s", arr);
		arr = strtok(NULL, " ");
	}
	printf("\n");
}

void five()
{
	char sentence[MAX];

	printf("Enter sentence: ");
	fgets(sentence, MAX, stdin);
	fgets(sentence, MAX, stdin);
	sentence[strcspn(sentence, "\n")] = 0;
	char *arr = strtok(sentence, " ");

	removeWhitespace(arr);
}

