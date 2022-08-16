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

int main()
{
    FILE *fp;
    char append[SIZE];
    fp = fopen("test.txt","a");
    printf("Enter data to append: ");
    fgets(append, SIZE, stdin);
    read(fp);
    fputs(append, fp);
    fclose(fp);
    return 0;
}
