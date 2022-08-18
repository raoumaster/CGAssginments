// C PROGRAM to check whether 3 or more command line arguments are entered.

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Enter at least 3 servername:portnumber\n");
		return 1;
	}
	else
	{
		printf("valid entry\n");
		return 0;
	}

}
