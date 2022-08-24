#include <stdio.h>
#include"simplelink.h"

//int gsimple = 0;
//int gcomplex = 0;

int complexlink(int lflag)
{
  int retval = 0;
  printf("\nENTER complexlink function");
  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    gcomplex = 0;
    retval = 1;
  }
  else
  {
    printf("\nlflag is different from zero");
    gcomplex = 1;
    retval = 0;
  }
  printf("\nEXIT complexlink function");
  return retval;
}

int simplelink(int lflag)
{
  int retval = 0;
  printf("\nENTER simplelink function");
  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    gsimple = 1;
    retval = 0;
  }
  else
  {
    printf("\nlflag is different from zero");
    gsimple = 0;
    retval = 1;
  }
  printf("\nEXIT simplelink function");
  return retval;
}

