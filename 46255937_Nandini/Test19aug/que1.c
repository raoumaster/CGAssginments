#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

//factorial
void* fact(void *x)
{
        int *num = (int*)x;
        int f;
        pthread_mutex_lock(&lock);
        printf("Enter a number: ");
        scanf("%d", &num);

        for(i=1;i<=num;i++)
                f = f * i;

        printf("%d! = %d\n", num, f);
        return 0;
        pthread_mutex_unlock(&lock);
}

//palindrome
void* pd(void* x){
        int *n =(int *)x;
        int r, sum=0, temp;
         pthread_mutex_lock(&lock);
         temp=n;
        while(n>0)
        {
                r = n%10;
                sum = (sum*10) + r;
                n=n/10;
        }
        if(temp==sum)
        {
                printf("True");
        }
        else
        {
                printf("False");
        }
        pthread_mutex_unlock(&lock);
}
// triangle
void *triangle(void *nu){
           int *nu = (int *)num;
       int i, space, k = 0;
    pthread_mutex_lock(&lock);
    for (i = 1; i <= *nu; ++i, k = 0) {
              for (space = 1; space <= *nu - i; ++space) {
                           printf("  ");
                             }
         while (k != 2 * i - 1) {
            printf("* ");
         ++k;
      }
      printf("\n");
   }
   pthread_mutex_unlock(&lock);
}
int main()
{
        pthread_t tid1;
        int main()
        {
                pthread_t tid1;
                pthread_t tid2;
                pthread_t tid3;
                printf("Enter a number:\n");
                scanf("%d", &x);
                if (pthread_mutex_init(&lock, NULL) != 0) {
                        printf("\n mutex init has failed\n");

                        return 1;
                }
                pthread_create(&tid1, NULL, fact, (void *)&x);
                pthread_create(&tid2, NULL, pal, (void *)&x);
                if(x<10){
                        pthread_create(&tid3, NULL, tri, (void *)&x);
                }
                pthread_join(tid1, NULL);
                pthread_join(tid2, NULL);
                pthread_join(tid3, NULL);
                pthread_mutex_destroy(&lock);
                return 0;
        }