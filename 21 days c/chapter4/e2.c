#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  FILE *fp;
  char ch;
  char input;
  char xuanze;
  char handle;
  if ((fp = fopen(argv[1], "r+")) == NULL)
  {
    printf("can not open the file!Create the File?(y/n)(the file is only read)");
    xuanze = getchar();
    if (xuanze == 'y')
    {
      if ((handle = creat(argv[1], 0)) == -1)
      {
        printf("create error!");
        exit(0);
      }
      else
      {
        printf("create!");
        exit(0);
      }
    }
    if (xuanze == 'n')
    {
      exit(0);
    }
  }
  else
  {
    printf("the file:\n");
  }
  ch = fgetc(fp);
  while (ch != EOF)
  {
    putchar(ch);
    ch = fgetc(fp);
  }
  printf("\nyou can add some text at last(input the # to end):\n");
  input = getchar();
  while (input != '#')
  {
    fputc(input, fp);
    input = getchar();
  }
  fclose(fp);
}