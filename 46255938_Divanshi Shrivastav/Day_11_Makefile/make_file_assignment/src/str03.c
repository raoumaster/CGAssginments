/* Program to get string input from the user using fgets,
 * tokenize the words and return the longest word and, count of its characters.
 */
#include<stdio.h>
#include<string.h>
#define MAX 50

void longestWord(char *arr){
	int max_size=0;
	char max_word[MAX];

	while (arr != NULL) {
		if(strlen(arr) > max_size){
			strcpy(max_word, arr);
			max_size = strlen(arr);
		}

		arr = strtok(NULL, " ");
	}
	printf("Longest word is: %s\n", max_word);
	printf("Longest word's size is: %d\n", max_size);
}

void third(){
	char sentence[MAX];
        printf("Enter sentence: ");
        fgets(sentence, MAX, stdin);
        fgets(sentence, MAX, stdin);
        sentence[strcspn(sentence, "\n")] = 0;

        char *arr = strtok(sentence, " ");

        longestWord(arr);
}
