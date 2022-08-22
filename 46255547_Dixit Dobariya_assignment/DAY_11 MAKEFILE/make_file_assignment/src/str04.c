/* Program to get string and substring from the user using fgets,
 * remove the word containing the substring and return the string without that word.
 */
#include<stdio.h>
#include<string.h>
#define MAX 50

void removeSubstringWord(char *arr, char *substring){
	int flag = 1;
	char *word;

	while (arr != NULL) {
		if(flag){
			word = strstr(arr, substring);
			if(word){
				flag = 0;
				arr = strtok(NULL, " ");
				continue;
			}
		}
		printf("%s ", arr);
		arr = strtok(NULL, " ");
	}
	printf("\n");
}
void fourth(){
	char sentence[MAX];
	char substring[MAX];

	printf("Enter sentence: ");
	fgets(sentence, MAX, stdin);
	fgets(sentence, MAX, stdin);
	sentence[strcspn(sentence, "\n")] = 0;
	printf("Enter substring: ");
	fgets(substring, MAX, stdin);
	substring[strcspn(substring, "\n")] = 0;

	char *arr = strtok(sentence, " ");

	removeSubstringWord(arr, substring);
}
