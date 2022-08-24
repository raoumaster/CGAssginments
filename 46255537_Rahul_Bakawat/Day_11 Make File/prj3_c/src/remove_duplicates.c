/***************************************************************************
 * FUNCTION NAME: remove_duplicates
 *
 * DESCRIPTION:Removes the lines which occur more than once and keeps a count
 *             Displays the lines on duplication removal and writes to the
 *             output file
 *
 * RETURNS: Returns the lines of the files after removal of duplicates
***************************************************************************/
#include "../inc/remove_duplicates.h"

int remove_duplicates(char *array_lines[MAX], int i)
{
        int k = 0,
            j = 0,
            count = 0;

        for(j = 0; j < i; j++)
        {
                for(k = 1+j; k < i-j; k++)
                {
			
			//Check for duplicates by traversing through the array of pointers
                        if((strcmp(array_lines[j], array_lines[k]) == 0 && array_lines[k]!=NULL))
                        {
                                printf("\nDuplicate line is: %s\n", array_lines[k]);
                                
				//Count the number of duplicates
				count++;
                                if(array_lines[k+1]!=NULL)
                                {
                                        while(array_lines[k]!=NULL)
                                        {
                                                array_lines[k]=array_lines[k+1];
                                                k++;

                                        }
                                        i--;
                                }
                                else if(array_lines[k+1] == NULL)
                                {
                                        array_lines[k+1] = NULL;
                                        i--;
                                }
                        }
                }
        }
        printf("\nNumber of duplicates is :%d\n",count);
        for(i = 0; array_lines[i]!= NULL; i++)
        {
                printf("%s\n",array_lines[i]);
        }
        return array_lines;
}



