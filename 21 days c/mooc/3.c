#include <stdio.h>
int main(int argc, char const *argv[])
{
  unsigned long number;
  scanf("%ld", &number);
  if (number >= 1)
  {
    printf("%d", 1);
    for (unsigned long i = 2; i <= number; i++)
    {
      if (i % 2 == 1)
      {
        printf(" %lu", i);
      }
    }
  }

  return 0;
}
