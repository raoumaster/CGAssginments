/*code to read a line from cmd and store in a stack form
* function to display stack
* Store the output in a different file
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 80

void read(FILE * fp)
{
    char ch;
    do 
    {
        ch = fgetc(fp);
        putchar(ch);
    } 
    while (ch != EOF);
}

void disp(FILE *fp)
{
    fp = freopen("test.txt", "r", fp);
    printf("Stack: \n");
    read(fp);
}

int main()
{
    FILE *fp;
    char append[SIZE];
    fp = fopen("test.txt", "a");

    if (fp == NULL)
    {
        printf("File doesn't exist\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter data to append: ");
    fgets(append, SIZE, stdin);
    fputs(append, fp);
    disp(fp);
    fclose(fp);
    return 0;
}
