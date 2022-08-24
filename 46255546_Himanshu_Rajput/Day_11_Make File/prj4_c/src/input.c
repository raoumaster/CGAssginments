/*
*****************************************************************************************************************************************************************************************************************************************************************************************
WAP program to read a  input file name  as  command line argument.

Consider the following requirements to be implemented

a. Input file will have fixed number of lines. Each line  will have two or more space separated strings 
consisting of alpha numeric characters. Consider a maximum line length of 50 characters.

b. Process all lines and remove the duplicate lines. Display duplicate line and count on console

c. Then  again in file, process every word in line, remove all the non alphabetical characters in the word,
  store the updated line words in a data structure

d. Traverse and display  the updated lines in console

e. Finally  log the final list of lines in output file named "out.txt".
      

f. You need to choose appropriate data structure/algorithm, which enhances the efficiency of your solution. 

g. Exit the program (Make sure to free all user memory, if allocated)

*****************************************************************************************************************************************************************************************************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CHECK.h"
#define MAX_LENGTH 1000

void main(int argc, char* argv[])  // taking arguments in RUNTIME
{
	char **str=NULL;
	char **ptr=NULL;
	char *filename=NULL;
	char a=' ';
	int i=0;
	int j=0;
	int count=0;
	int length=0;
	FILE *fptr;			

	if( argc > 3 || argc <= 2) 	// checking for Errors on Command Line Arguments
	{

     		 printf("Too many arguments supplied.\n");

  	}

  	else 
	{

	fptr=fopen(argv[1],"r");		// opening File using FILE pointer

	filename=argv[2];		

	while((a=getc(fptr))!= EOF)			
	{
		if('\0' == fptr)
		{
			printf("File Is Empty");
		}
		else if('\0' == a)
		{
			i++;
		}
		else
		{
			continue;
		}
	}

	count=i;

	for(i=0;i<count;i++)
	{
		fgets(str[i],MAX_LENGTH,fptr);

		ptr[i]=(char*)malloc(sizeof(char)*strlen(str[i])+1);		// allocating Runtime Memory 
		memset(ptr[i],'\0',sizeof(char)*strlen(str[i])+1);

		ptr[i]=str[i];
	}
	
	check_dup(ptr,count,filename);  // calling funtion of CHECK.c file
	}

	fclose(fptr);
	free(ptr);
return 0;
}
