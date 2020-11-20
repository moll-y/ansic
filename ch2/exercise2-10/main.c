#include <stdio.h>

int lower (int c);

int
main ()
{
  printf ("%c\n", lower ('A'));
  return 0;
}

/* lower: convert c to lower case; ASCII only */
int
lower (int c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
