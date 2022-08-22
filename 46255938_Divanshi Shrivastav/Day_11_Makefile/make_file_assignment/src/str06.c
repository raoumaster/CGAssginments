/* Program to get string input from the user using fgets,
 * replace whitespaces with '!' in the string and return string.
 */
#include<stdio.h>
#include<string.h>
#define MAX 50

int replacews(char *mystr, char myreplacement){
	int i=0, count = 0;
	while (mystr[i]){
		if (mystr[i] == ' '){
			mystr[i] = myreplacement;
			count++;
		}
		i++;
	}
	printf("%s\n",mystr);
	return count;
}
void six(){
	char myreplacement = '!';
	char mystr[MAX];
	printf("Enter string: ");
	fgets(mystr, MAX, stdin);
	fgets(mystr, MAX, stdin);
	mystr[strcspn(mystr, "\n")] = 0;

	printf("Total replacements = %d\n", replacews(mystr, myreplacement));
}
