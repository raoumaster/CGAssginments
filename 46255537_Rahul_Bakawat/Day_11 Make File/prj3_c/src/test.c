/**************************************************************************************
*
*  FILE NAME	: test.c.
*
*  DESCRIPTION: General description of the file contents and purpose. 
*
*  DATE : 26/12/2019	NAME : Tejaswini Prabhu
*
*************************************************************************************/

#include "../inc/remove_duplicates.h"

int main(int argc, char*argv[])
{
        FILE *input_ptr,*out_ptr;
        input_ptr=fopen(argv[1],"r");
        char str[MAX];
        int i=0,
	    j=0;
        char *array = NULL;
	char *array_lines[MAX];
        
	//Open the input and output files
	input_ptr=fopen(argv[1],"r");
        out_ptr=fopen(argv[2],"r+");
        
	//Check for count of command line arguments
	if(argc != 3)
	{
		printf("Too few arguments\n");
	}
	
	//Check whether the input file is empty or not
	if(input_ptr == NULL)
        {
                printf("File empty\n ");
        }
	

	//Read the input from the text file line by line
	while(fgets(str, MAX, input_ptr)!=NULL)	
	{
		//Allocate memory to read and store the each line
		array = (char*)malloc(sizeof(char)*strlen(str));
		
		//Prevents garbage values
		memset(array,'\0',sizeof(char)*strlen(str));
		
		//Copy the word into array pointer from str
		strcpy(array,str);

		//Allocate memory to store pointers in an array
		array_lines[i] = (char*)malloc(sizeof(char)*strlen(array));
	
		// Prevents garbage values
		memset(array_lines,'\0',sizeof(char)*strlen(array_lines));
		if( array != NULL)
		{
			array_lines[i] = array;
		}
		printf("%s\n",array_lines[i]);			
	i++;
	}
	

	//Function to remove duplicates funcation calls
	remove_duplicates(array_lines, i);

	//Write the output to the output text file
	for(i = 0; array_lines[i]!=NULL; i++)
	{
		fprintf(out_ptr,"%s\n",array_lines[i]);
	}


	//Close the input and output file
	fclose(input_ptr);
	fclose(out_ptr);
}






