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


int main() {
        FILE *fip;
        char append[SIZE];

        fip = fopen("test.txt", "a");

        printf("Enter data to append: ");
        fgets(append, SIZE, stdin);

        read(fip);
        fiputs(append, fip);

        fclose(fip);

        return 0;
}