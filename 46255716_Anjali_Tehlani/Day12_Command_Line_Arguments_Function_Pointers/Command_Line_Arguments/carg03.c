/*
 * Code to take 3 or more command line arguments
 * and check for valid servername and portnumber.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void *display(int argc, char *argv[])
{
	for(int i=1; i<argc; i++)
	{
		printf("%s\t", argv[i]);
		argv[i][strcspn(argv[i], "\n")] = 0;
		char *token = strtok(argv[i],":");
		printf("%s\t\t", token);
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isalpha(token[j]))
			{
				printf("False\n");
				return 1;
			}
		}
		printf("True\t\t");
		token = strtok(NULL, " ");
		int portnum;
		portnum = atoi(token);
		printf("%d\t\t",portnum);
		for(int j = 0; j < strlen(token); j++)
		{
			if(!isdigit(token[j]))
			{
				printf("False\n");
				return 1;
			}
		}
		printf("True\t\t");

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
}

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Enter atleast 3 servername:portnumber\n");
		return 1;
	}
	printf("VALID no.of arguments\n\n");
	printf("SERVER_NAME\t\tPORT_NUMBER\n\n");

	display(argc, argv);

	return 0;
}
