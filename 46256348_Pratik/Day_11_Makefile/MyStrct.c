#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *mystrcat(char *s1, char *s2)
{
    int i, j;
    // s1=(char*)calloc(sizeof(s2), sizeof(int));
    for(i=0; s1[i]!='\0'; ++i);
    for(j=0; s2[j]!='\0'; ++j, ++i)
    {
        s1[i]=s2[j];
    }
    s1[i]='\0';
    printf("\n The final concatenated string generated:- %s", s1);
    return strdup(s1);

}
