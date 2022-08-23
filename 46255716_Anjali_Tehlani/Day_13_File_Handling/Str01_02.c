/*Q.1,2 :code to read a line from cmd and store in a stack form
  function to display stack */
 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void read(FILE * fp) {
        char ch1;
        do {
                ch1 = fgetc(fp);
                putchar(ch1);
        } while (ch1 != EOF);
}

void display(FILE *fp){
        fp = freopen("stud.dat", "r", fp);
        printf("Stack : \n");
        read(fp);
}

int main() {
        FILE *fp;
        char append[SIZE];

        fp = fopen("stud.dat", "a");

        if (fp == NULL) {
                printf("File doesn't exist\n");
                exit(EXIT_FAILURE);
        }

        printf("Enter data to append: ");
        fgets(append, SIZE, stdin);

        fputs(append, fp);

        display(fp);

        fclose(fp);

        return 0;
}