/* Program to get string input from the user using fgets,
 * tokenize the words and return the count of total words.
 */
#include<stdio.h>
#include<string.h>
#define MAX 70

void second(){
	int count=0;
	char sentence[MAX];
	printf("Enter sentence: ");
	fgets(sentence,MAX,stdin);
	fgets(sentence,MAX,stdin);

	char *arr = strtok(sentence, " ");

	while (arr != NULL) {
		printf("%s\n", arr);
		arr = strtok(NULL, " ");
		count++;
	}

	printf("%d\n", count);
}
