#include <stdio.h>
int main() {
        FILE *fip;                                      
        int a=0, max=0,temp=0;
        char fname[40], c;

        printf("Enter file name: ");          
        scanf("%s", fname);
        fip = fopen(fname, "r");                

        c = fgetc(fip);
        while (c != EOF){
                temp++;
                if (c == '\n'){
                        a = a + 1;
                        if(temp>=max){
                                max=temp;
                                temp=0;
                        }
                }
                chr = fgetc(fip);               
        }
        fclose(fip);
        printf("Max Length: %d\n",max-1);
        printf("There are %d lines in %s in a file\n", a, fname);
        return 0;
}