#include <stdio.h>
#include <stdlib.h>

#define SIZE 80

void read(FILE * fip) {
        char ch;
        do {
                ch = fgetc(fip);
                putchar(ch);
        } while (ch != EOF);
}

void disp(FILE *fip){
        fip = freopen("test.txt", "r", fip);
        printf("Stack: \n");
        read(fip);
}

int main() {
        FILE *fip;
        char append[SIZE];

        fip = fopen("test.txt", "a");

        if (fip == NULL) {
                printf("File doesn't exist\n");
                exit(EXIT_FAILURE);
        }

        printf("Enter data to append: ");
        fgets(append, SIZE, stdin);
        
        fiputs(append, fip);

        disp(fip);

        fclose(fip);

        return 0;
}