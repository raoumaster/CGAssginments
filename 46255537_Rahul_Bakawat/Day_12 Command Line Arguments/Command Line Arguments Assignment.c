/*
 * Code to take 3 or more command line arguments, check for valid
 * servername and portnumber, allocate memory, print concatenated string
 * of server names and free all alocated memory.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 80

/*----------------------------------------------
	REQUIREMENT TAG: CARG/05
	Function to release all the allocated memory
------------------------------------------------*/
void freeAll(char *serverName)
{
	free(serverName);
}

/*-----------------------------------------------------------
	REQUIREMENT TAG: CARG/04
	Function to receive an array of pointers to server names,
	concatenate names and return the concatenated string.
------------------------------------------------------------*/
void concatenate(char *serverName, char *token)
{
		strcat(serverName, token);
		strcat(serverName, "_");
}

/*--------------------------------------------------------------------
	REQUIREMENT TAG: CARG/03
	Function to receive a word, to extract and display server name 
	and port number. Should store and a return pointer to server name.
----------------------------------------------------------------------*/
void extractAndDisplay(int argc, char *argv[], char *serverName)
{
	for(int i=1; i<argc; i++)
	{
		//printf("%s\t\t", argv[i]);
		argv[i][strcspn(argv[i], "\n")] = 0;
		char *token = strtok(argv[i],":");
		printf("%s\t\t\t", token);

		concatenate(serverName, token);

		/*---------------------------------------------------------------------------------------------
		REQUIREMENT TAG: CARG/02
		Validate every word received. It should contain a Server name and a port number in range 0-1023
		-----------------------------------------------------------------------------------------------*/
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isalpha(token[j]))
			{
				printf("\nINVALID SERVER NAME\n");
				return;
			}
		}

		token = strtok(NULL, " ");
		int portnum;
		portnum = atoi(token);
		printf("%d\n",portnum);

		/*---------------------------------------------------------------------------------------------
		REQUIREMENT TAG: CARG/02
		Validate every word received. It should contain a Server name and a port number in range 0-1023
		-----------------------------------------------------------------------------------------------*/
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isdigit(token[j]))
			{
				printf("\nINVALID PORT NUMBER\n");
				return;
			}
		}

		/*---------------------------------------------------------------------------------------------
		REQUIREMENT TAG: CARG/02
		Validate every word received. It should contain a Server name and a port number in range 0-1023
		-----------------------------------------------------------------------------------------------*/
		if(!(0 < portnum && portnum < 1023))
		{
			printf("\nPORT NUMBER OUT OF RANGE\n");
			return;
		}
	}
}

int main(int argc, char *argv[])
{
	/*-------------------------------------------------------------------------------------------------
		REQUIREMENT TAG: CARG/01
		Validate every word received. It should contain a Server name and a port number in range 0-1023
	---------------------------------------------------------------------------------------------------*/
	if(argc < 4)
	{
		printf("Enter atleast 3 servername:portnumber\n");
		return 1;
	}
	printf("VALID no.of arguments\n\n");

    char * ptr;
	char *serverName;
	serverName = (char *)calloc(MAX, sizeof(char));

	printf("SERVER_NAME\t\tPORT_NUMBER\n\n");
	
	extractAndDisplay(argc, argv, serverName);	
	serverName[strlen(serverName)-1] = '\0';
	
	printf("\nConcatenated server name: %s\n", serverName);
	freeAll(serverName);

	return 0;
}