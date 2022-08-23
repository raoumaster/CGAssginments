/* Code to check whether 3 or more command line arguments are entered. */

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Enter atleast 3 servername:portnumber\n");
		return 1;
	}
	else
	{
		printf("VALID\n");
		return 0;
	}

}
