// 练习题
#include <stdio.h>
#include <stdlib.h>

void practice_1();
void practice_2();
void practice_3();
void practice_4();
void practice_5(char const *source, char *target, unsigned long len);
unsigned long practice_6(char const *a, char const *b);
char *practice_7(char const *a, char const *b);
void practice_8();

int main(int argc, char const *argv[])
{
  practice_8();
}

void practice_1()
{
  char letter = '$';
}

void practice_2()
{
  char string[] = "Pointers are fun!";
  printf("%s", string);
}

void practice_3()
{
  char *string = "Pointers are fun!";
  printf("%s", string);
}

void practice_4()
{
  char string[81];
  scanf("%s", string);
  printf("%s", string);
}

void practice_5(char const *source, char *target, unsigned long len)
{
  for (unsigned long i = 0; i < len; i++)
  {
    if (source[i] != '\0')
    {
      target[i] = source[i];
    }
    else
    {
      break;
    }
  }
}

unsigned long practice_6(char const *a, char const *b)
{
  unsigned long len_a = 0, len_b = 0;
  while (a[len_a] != '\0')
    len_a++;
  while (b[len_b] != '\0')
    len_b++;
  return len_a > len_b ? len_a : len_b;
}

char *practice_7(char const *a, char const *b)
{
  unsigned long a_len = practice_6("", a);
  unsigned long b_len = practice_6("", b);
  char *new_str = (char *)malloc(sizeof(char) * (a_len + b_len + 2));
  practice_5(a, new_str, a_len);
  new_str[a_len] = ' ';
  practice_5(b, new_str + (a_len + 1), b_len);
  return new_str;
}

void practice_8()
{
  unsigned width = 15;
  for (unsigned h = 0; h < width; h++)
  {
    for (unsigned w = 0; w < width; w++)
    {
      if (h == 0)
      {
        if (w == 0)
          printf("%s", "╔");
        else if (w == width - 1)
          printf("%s\n", "╗");
        else
          printf("%s", "═");
      }
      else if (h == width - 1)
      {
        if (w == 0)
          printf("%s", "╚");
        else if (w == width - 1)
          printf("%s\n", "╝");
        else
          printf("%s", "═");
      }
      else
      {
        if (w == 0)
          printf("%s", "║");
        else if (w == width - 1)
          printf("%s\n", "║");
        else
          printf(" ");
      }
    }
  }