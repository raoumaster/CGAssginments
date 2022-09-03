#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *remove_vowel(char s[],int index)
{
    char t[100];
    int c, d = 0;
    for (c = index; s[c] != '\0'; c++) {
        if (isVowel(s[c]) == 1) {     // If not a vowel
            t[d] = s[c];
            d++;
            }

        }
    t[d] = '\0';
    strcpy(s, t);  
    printf("\nString after deleting vowels: %s\n", t);
    return strdup(&t);

}
