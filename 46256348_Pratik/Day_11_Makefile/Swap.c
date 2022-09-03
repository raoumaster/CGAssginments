#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char **x,char **y)
{
    char *temp=NULL;
    temp=*x;
    *x=*y;
    *y=temp;
}