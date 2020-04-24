#include <stdio.h>
#define MAXLENGTH 101
int scanf_pc(long *coefficients);
void printfItem(int coefficient, int power);

int main(int argc, char const *argv[])
{
  // int powers[101] = {0};
  long coefficients_a[MAXLENGTH] = {0};
  // long coefficients_b[MAXLENGTH] = {0};
  int isFirstPass = 1;
  int maxIndex = scanf_pc(coefficients_a);
  scanf_pc(coefficients_a);
  for (int i = maxIndex; i >= 0; i--)
  {
    if (coefficients_a[i] == 0 && i == 0 && i == maxIndex)
    {
      printf("0");
      break;
    }
    if (coefficients_a[i] == 0 && i == maxIndex)
    {
      maxIndex--;
      continue;
    }
    if (i != maxIndex && coefficients_a[i] > 0)
    {
      // 非首次输出
      printf("%c", '+');
    }
    if (i >= 2 && coefficients_a[i] != 0)
    {
      printf("%ldx%d", coefficients_a[i], i);
    }
    else if (i == 0 && maxIndex == i)
    {
      printf("0");
    }
    else if (i == 0 && coefficients_a[i] != 0)
    {
      printf("%ld", coefficients_a[i]);
    }
    else if (i == 1 && coefficients_a[i] == 1)
    {
      printf("x");
    }
    else if (i == 1 && coefficients_a[i] == -1)
    {
      printf("-x");
    }
    else if (i == 1 && coefficients_a[i] != 0)
    {
      printf("%ldx", coefficients_a[i]);
    }
  }
  printf("\n");
  return 0;
}

int scanf_pc(long *coefficients)
{
  int power = 0;
  int ret = -1;
  do
  {
    long coefficient = 0;
    scanf("%d %ld", &power, &coefficient);
    coefficients[power] += coefficient;
    if (ret == -1)
    {
      ret = power;
    }
    /* code */
  } while (power > 0);
  return ret;
}
