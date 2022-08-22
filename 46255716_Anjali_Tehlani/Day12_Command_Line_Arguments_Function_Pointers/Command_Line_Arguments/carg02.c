/*
 * Code to take 3 or more command line arguments
 * and check for valid servername and portnumber.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Enter atleast 3 servername:portnumber\n");
		return 1;
	}
	printf("VALID no.of arguments\n");
	printf("\n");
	printf("ARGUMENT\t\tisAlpha(Server_Name)\tisDigit(Port_Number)\tinRange(0-1023)\n\n");
	for(int i=1; i<argc; i++)
	{
		printf("%s\t\t", argv[i]);
		argv[i][strcspn(argv[i], "\n")] = 0;
		char *token = strtok(argv[i],":");
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isalpha(token[j]))
			{
				printf("False\n");
				return 1;
			}
		}
		printf("True\t\t\t");
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
		printf("True\t\t\t");

		if(0 < portnum && portnum < 1023)
		{
			printf("True\n");
		}
		else
		{
			printf("PORT NUMBER OUT OF RANGE\n");
			return 1;
		}
	}
	return 0;
}
