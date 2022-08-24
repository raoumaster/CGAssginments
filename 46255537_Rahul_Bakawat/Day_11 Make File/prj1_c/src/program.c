#include <stdio.h>
#include "simplelink.h"

int main()
{
  int flag = 10;
  int retval = 0;
  gsimple = flag + gsimple;
  printf("\ngsimple before simplelink call: %d \n", gsimple);
  retval = simplelink(flag);
  printf("\ngsimple after simplelink call: %d \n", gsimple);
  printf("\nreturn value from simplelink : %d \n", retval);
  printf("\nreturn value from simplelink : %d \n", retval);
  printf("\nreturn value from simplelink : %d \n", retval);

  printf("\ngcomplex before complexlink call: %d \n", gcomplex);
  retval = complexlink(flag);
  printf("\ngcomplex after complexlink call: %d \n", gcomplex);
  printf("\nreturn value from complexlink : %d \n", retval);
  return retval;
}

