#include <stdio.h>
#include <math.h>
// 4.1
// int main(int argc, char const *argv[])
// {
//   unsigned long number;
//   unsigned long number_of_odd = 0;
//   unsigned long number_of_even = 0;
//   scanf("%lu", &number);
//   while (number != -1)
//   {
//     if (number % 2 == 0)
//     {
//       number_of_even++;
//     }
//     else
//     {
//       number_of_odd++;
//     }
//     scanf("%lu", &number);
//   }
//   printf("%lu %lu", number_of_odd, number_of_even);
//   return 0;
// }

// 4.2
unsigned long convert_binary_decimal(unsigned long number);
int main(int argc, char const *argv[])
{
  unsigned long number;
  unsigned long binary_code = 0;
  unsigned long current_bit = 1;
  unsigned start = 1;
  scanf("%lu", &number);
  while (number > 0)
  {
    unsigned bit = number % 10;
    if (start % 2 == bit % 2)
    {
      binary_code += current_bit;
    }
    start++;
    current_bit *= 10;
    number /= 10;
  }

  printf("%lu", convert_binary_decimal(binary_code));
  return 0;
}

unsigned long convert_binary_decimal(unsigned long number)
{
  // printf("%lu\n", number);
  unsigned long ret = 0;
  unsigned current_bit = 0;
  while (number > 0)
  {
    unsigned bit = number % 10;
    if (bit == 1)
    {
      if (current_bit == 0)
      {
        ret++;
      }
      else
      {
        ret += pow(2, current_bit);
      }
    }
    current_bit++;
    number /= 10;
  }
  return ret;
}
