#include <stdio.h>
void pf(int number);
int main()
{
  int number;
  scanf("%3d", &number);
  int h = number / 100, td = (number - h * 100) / 10, od = number % 10;
  pf(od);
  pf(td);
  pf(h);
  return 0;
}

void pf(int number)
{
  if (number > 0)
  {
    printf("%d", number);
  }
}