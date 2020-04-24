#include <stdio.h>

int main(int argc, char const *argv[])
{
  char ch;
  int word_length = 0;
  do
  {
    scanf("%c", &ch);
    if (ch != ' ' && ch != '.' && ch != '\n')
    {
      word_length++;
    }
    else if (word_length)
    {
      printf("%d%s", word_length, ch != '.' ? " " : "");
      word_length = 0;
    }
  } while (ch != '.');

  return 0;
}
