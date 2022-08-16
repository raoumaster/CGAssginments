/*Code to print the max length of a line in a file.
  print total number of lines in a file/
*/

#include <stdio.h>
int main() 
{
    FILE *fp;
    int n = 0; // Number of Lines
    int max = 0; // Maximum Length
    int temp = 0; 
    char fname[40]; //Name of the file 
    char chr;

    printf("Enter file name: "); //give the file name to read lines
    scanf("%s", fname);
    fp = fopen(fname, "r");

    chr = fgetc(fp);
    while (chr != EOF)
    {
        temp++;
        if (chr == '\n')
        {
            n = n + 1;
            if(temp>=max)
            {
                max=temp;
                temp=0;
            }
        }
        chr = fgetc(fp);
    }
    fclose(fp);
    printf("Max Length: %d\n",max-1);
    printf("There are %d lines in %s in a file\n", n, fname);
    return 0;
}