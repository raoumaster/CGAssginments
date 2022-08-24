#include <stdio.h>
#include <stdlib.h>
#include "OUTPUT.h"

void* write_file(char **ptr, char *filename, int count_1)		// writing data into the File
{
	FILE *fptr1;
	int i=count_1;
	
	fptr1=fopen(filename,"w");

	while(i<count_1)
	{
		fputs(ptr[i],fptr1);
		fputs("\0",fptr1);
		fputs("\n",fptr1);
	}
	
	fclose(fptr1);
	return 0;
}
