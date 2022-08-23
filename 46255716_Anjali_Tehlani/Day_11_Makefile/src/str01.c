/* Program to enter a string from user using fgets */
#include<stdio.h>
#include<string.h>
#define MAX 100

void first(){
	char sentence[MAX];
	//int ch, i=0;
	printf("Enter a sentence: ");
	fgets(sentence, MAX, stdin);
	fgets(sentence, MAX, stdin);
/*	do
	{
		ch = getchar();
		sentence[i] = ch;
		i++;
	}
	while(ch != '\n');
*/
	sentence[strcspn(sentence, "\n")] = 0;
	printf("%s\n", sentence);
}
