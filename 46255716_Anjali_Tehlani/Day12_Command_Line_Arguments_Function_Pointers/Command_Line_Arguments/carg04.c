/*
 * Code to take 3 or more command line arguments, check
 * for valid servername and portnumber, allocate memory using calloc() 
 * and print concatenated string.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 80

void extractAndConcatenate(int argc, char *argv[], char *serverName)
{
	for(int i=1; i<argc; i++)
	{
		//printf("%s\n", argv[i]);
		argv[i][strcspn(argv[i], "\n")] = 0;
		char *token = strtok(argv[i],":");
		//printf("%c\n", *(token+1));

		strcat(serverName, token);
		strcat(serverName,"_");
		
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isalpha(token[j]))
			{
				printf("False\n");
				return 1;
			}
		}
		token = strtok(NULL, " ");
		int portnum;
		portnum = atoi(token);
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isdigit(token[j]))
			{
				printf("False\n");
				return 1;
			}
		}

		if(!(0 < portnum && portnum < 1023))
		{
			printf("OUT OF RANGE\n");
			return 1;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Enter atleast 3 servername:portnumber\n");
		return 1;
	}

	char *serverName = (char *)calloc(MAX, sizeof(char));
	
	extractAndConcatenate(argc, argv, serverName);
	serverName[strlen(serverName)-1]= '\0';
	printf("Concatenated server name: %s\n", serverName);
	return 0;
}
