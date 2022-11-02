#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 void sort(char str[][25], int c)
{
char temp[70];
int i,j;
 for(i=0;i<=c;i++)
 for(j=i+1;j<=c;j++)
 {
         if(strcmp(str[i],str[j])>0)
             {
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
             }
  }

   printf("Order of Sorted Strings:");
   for(i=0;i<=c;i++)
      puts(str[i]);
}
   
int main()
{
   int i,j,count;
   char string[25][25];
   puts("How many strings u are going to enter?: ");
   scanf("%d",&count);

   puts("Enter Strings one by one: ");
   for(i=0;i<=count;i++)
      gets(string[i]);

sort(string,count);
  
   return 0;
}
