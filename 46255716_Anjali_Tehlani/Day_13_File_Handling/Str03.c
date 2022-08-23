/* Q.3 : Code to print the max length of a line in a file.*/

#include <stdio.h>

int main() {
        FILE *fp;
        int n = 0,max=0,temp=0;
        char fname[40], ch;

        printf("Enter file name: ");
        scanf("%s", fname);
        fp = fopen(fname, "r");

        ch = fgetc(fp);
        while (ch != EOF){
                temp++;
                if (ch == '\n'){
                        n = n + 1;
                        if(temp>=max){
                                max=temp;
                                temp=0;
                        }
                }
                ch = fgetc(fp);
        }
        fclose(fp);
        printf("Max Length: %d\n",max-1);
        printf("There are %d lines in %s in a file\n", n, fname);
        return 0;
}