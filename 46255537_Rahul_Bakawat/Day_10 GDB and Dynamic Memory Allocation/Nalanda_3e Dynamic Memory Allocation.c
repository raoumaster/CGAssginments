/*
   Q1. Write a function to count and display words in input string
   Q2. Write a function to extract and store words in heap. Should allocate memory for each word as per its length.
   Q3. Write a function to prompt, read a search word and replace word, traverse stored words and perform search-replace on first word.
   Q4. Write a function to traverse and display all words stored
   Q5. Write a function to free all the allocated memory.
   Q6. Write a function to perform replace of all occurrences of the given word in input.(optional)
   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

//Q1: count words in string
int wordCount(char string[]){
	int count = 0;
	char *word = strtok(string, " ");

	while(word != NULL) {
		printf("%s\n", word);
		word = strtok(NULL, " ");
		count++;
	}

	return count;
}

//Q2: store words in heap using calloc
char** storeWords(char inputString[], int count){
	char **word_strings;
	word_strings = calloc(count, sizeof(char *));   //allocating memory to array of strings

	int i = 0;
	char *word = strtok(inputString, " ");

	while(word != NULL) {
		word_strings[i] = calloc(strlen(word), sizeof(char));   //allocating memory to strings
		strcpy(word_strings[i], word);
		i++;
		word = strtok(NULL, " ");
	}
	return word_strings;
}

//Q3: replace first occurrence of search word in array of strings
int searchReplace(char** word_strings, int count) {
	char search[20], replace[20];

	printf("\nEnter the word you want to be search:");
	scanf("%s", search);

	printf("\nEnter the word you want to be replace:");
	scanf("%s", replace);

	for(int  i = 0; i < count; i++) {
		if(strcmp(word_strings[i], search) == 0){
			strcpy(word_strings[i], replace);
			return EXIT_SUCCESS;
		}
	}
	return EXIT_FAILURE;
}

//Q4: display all words store in heap.
void displayWordStrings(char** word_strings, int count){
	for(int  i = 0; i < count; i++)
		printf("%s\n", word_strings[i]);
}

//Q5: free all allocated memory
void freeMemory(char** word_strings, int count){
	for(int  i = 0; i < count; i++)
		free(word_strings[i]);
	free(word_strings);
}

//Q6: replace all occurrences of search word in array of strings
int replaceALL(char** word_strings, int count) {
	char search[20], replace[20];
	int flag = 0;

	printf("\nEnter the word you want to be search for replacing all occurrences:");
	scanf("%s", search);

	printf("\nEnter the word you want to be replace for replacing all occurrences:");
	scanf("%s", replace);

	for(int  i = 0; i < count; i++) {
		if(strcmp(word_strings[i], search) == 0){
			strcpy(word_strings[i], replace);
			flag = 1;
		}
	}
	if(flag == 1)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}

int main()
{
	char inputString[MAX], string[MAX];
	char **word_strings;
	int count;

	printf("Enter the text:");
	fgets(inputString, MAX, stdin); //take input string
	strcpy(string, inputString);

	count = wordCount(string);  //count words in string
	printf("Numbers of words in text: %d\n", count);

	printf("\nWords are storing into heap...\n");
	word_strings = storeWords(inputString, count);  //store words into heap
	printf("\nStoring into heap done!\n");

	//searching & replacing only first occurrence
	if(searchReplace(word_strings, count) == 0) 
		printf("\nSearch word is found and replace first occurrence only!\n");
	else
		printf("\nSearch word not found in text.\n");

	printf("\nArray of strings after replacing first occurrence:\n");
	displayWordStrings(word_strings, count);    //display array of strings

	//searching & replacing all occurrences
	if(replaceALL(word_strings, count) == 0) 
		printf("\nSearch word is found and replace all occurrences!\n");
	else
		printf("\nSearch word not found in text.\n");

	printf("\nArray of strings after replacing all occurrences:\n");
	displayWordStrings(word_strings, count);    //display array of strings

	//free all allocated memory
	freeMemory(word_strings, count);
	printf("\nMemory freed.\n");

	return 0;
}
