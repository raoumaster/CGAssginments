#include<stdio.h>
//include<conio.h>
int main()
{
       int c=0, num, res, n, flag=0, i;
       while(c!=4)
       {
               //display menu
               printf("\nl.Factorial of a number\n2. Prime or not\n3. odd or even\n4. Exit\n");
               //display choice option to the user
               printf("\nEnter your choice:");
               scanf("%d" ,&c);
               //write case statement for Four options
               switch(c)
               {
                       //for factorial block
                       case 1:
                               //code for factorial functionality
                               printf("Enter an integer: ");
                               scanf("%d" ,&num);
                               n=num;
                               res=num;
                               while(num>1)
                               {
                                       res = res*(num-1);
                                       num =num-1;
                               }
                               printf("\nFactorial of %d is %d. \n\n",n, res);
                               break;
                               //For prime block
                       case 2:
                               //functionality of prime or not
                               printf("Enter an integer: ");
                               scanf("%d", &num);
                               n=num;
                               for(i=2;i<=n/2;i++)
                               {
                                       if(num%i==0)
                                       {
                                               flag=1;
                                               break;
                                       }
                               }
                               if(num==1)
                                       printf("\n1 is neither prime nor composite");
                               else
                               {
                                       if(flag==0)
                                               printf("\n%d is prime number.\n\n", n);
                                       else

                                               printf("\n%d is not a prime number.\n\n", n);
                               }
                               break;
                       case 3:
                               //functionality for odd-even
                               printf("Enter an integer: ");
                               scanf("%d",&num);
                               n=num;
                               if(num%2==0)
                                       printf("\n%d is Even number.\n\n",n);
                               else
                                       printf("\n%d is not Even number.\n\n",n);
                               break;
                       case 4:
                               printf("\nExit");
                               break;
               }

        }
}
