#include <stdio.h>
#include <math.h>
// int isPrime(long);
// int main(int argc, char const *argv[])
// {
//   int start, end;
//   long ret = 0;
//   int prime[201] = {0, 2, 0};
//   int prime_idx = 2;
//   for (long i = 3;; i++)
//   {
//     if (isPrime(i) == 1)
//     {
//       // printf("%ld\t", i);
//       prime[prime_idx++] = i;
//     }
//     if (prime_idx > 200)
//     {
//       break;
//     }
//   }
//   scanf("%d", &start);
//   scanf("%d", &end);
//   for (; start <= end; start++)
//   {
//     ret += prime[start];
//   }
//   printf("%ld", ret);
//   return 0;
// }

// int isPrime(long number)
// {
//   int ret = 1;
//   int s = (int)sqrt(number);
//   for (int i = 2; i <= s; i++)
//   {
//     if (number % i == 0)
//     {
//       ret = 0;
//       break;
//     }
//   }
//   return ret;
// }

int main(int argc, char const *argv[])
{
  int pinyin_index[7] = {-1, -1, -1, -1, -1, -1, -1};
  int cur_i = 6;
  char const *pinyin[] = {
      "ling",
      "yi",
      "er",
      "san",
      "si",
      "wu",
      "liu",
      "qi",
      "ba",
      "jiu"};
  long number;
  scanf("%ld", &number);
  if (number < 0)
  {
    printf("%s ", "fu");
    number = 0 - number;
  }
  else if (number == 0)
  {
    pinyin_index[6] = 0;
  }
  while (number > 0)
  {
    int n = number % 10;
    pinyin_index[cur_i--] = n;
    number = number / 10;
  }
  for (int i = 0; i < sizeof(pinyin_index) / sizeof(pinyin_index[9]) - 1; i++)
  {
    if (pinyin_index[i] != -1)
    {
      printf("%s ", pinyin[pinyin_index[i]]);
    }
  }
  printf("%s", pinyin[pinyin_index[6]]);
  return 0;
}
