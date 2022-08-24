#include <stdio.h>
#include "CHECK.h"
#include <stdlib.h>
#include <string.h>
#include "OUTPUT.h"

#define MAX_LENGTH 100		// MICROS

char* check_dup(char **ptr,int count, char *filename)		// Defining function
{	
	int count_1=0;  // to count occurrences of duplicates
	int c=0;
	int i=0;
	int j=i+1;
	char **str= NULL;

	while(i<count) //0
	{
		while(j<count)  //1
		{
			if( 0== strcmp(ptr[i],ptr[j]) )	// comparing strings
			{
				str[c]=ptr[j];
				memset(ptr[j],'\0',sizeof(char)*strlen(ptr[j]));

				count_1++;
				c++;
				j++;

			}
			else
			{

				continue;

			}
		}
		i++;
	}
	
	i=0;
	
	printf("Duplicate line count: %d",count_1);
	
	while(i<count)
	{
		printf("Duplicate lines: %s",str[i]);		
	}
	
	write_file(**ptr, filename, count_1);

return NULL;
	
}
