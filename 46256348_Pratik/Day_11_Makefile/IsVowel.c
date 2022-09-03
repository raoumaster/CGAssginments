#include <stdio.h>
#include<stdlib.h>
#include<string.h>


int isVowel(char p)
{
    while(p!='\0') {
        if(p=='A' ||p=='E' ||p=='I' ||p=='O' ||p=='U'
                ||p=='a' ||p=='e' || p=='i' || p=='o' || p=='u')
            return EXIT_FAILURE;
        else
            return EXIT_SUCCESS;
        p++;

    }

}