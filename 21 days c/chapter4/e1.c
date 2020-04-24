// 1. 让用户输入新的数据
// 2. 修改现有的条目
// 3. 按姓氏排列
// 4. 修改文件
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 255

char *scanf_name();
void puts_name_then_show(char *name);

int main(int argc, char const *argv[])
{
  char *name = scanf_name();
  puts_name_then_show(name);
  free(name);
  return 0;
}
char *scanf_name()
{
  char *name;
  name = (char *)malloc(255);
  puts("请输入你的名称:");
  scanf("%s", name);
  return name;
}

void puts_name_then_show(char *name)
{
  char names[255][255];
  unsigned int names_len = 0;
  FILE *fp;
  fp = fopen("./data.txt", "r+");
  unsigned long start = 0;
  for (; names_len < (sizeof(names) / sizeof(names[0])); names_len++)
  {
    char name[255];
    if (fgets(name, 255, fp) != NULL)
    {
      strcpy(names[names_len], name);
    }
    else
    {
      break;
    }
  }
  for (int i = 0; i < names_len; i++)
  {
    printf("%s", names[i]);
  }
  puts("\n");

  if (ferror(fp))
    puts("I/O error when reading");
  else if (feof(fp))
    puts("End of file reached successfully");

  fclose(fp);
  fp = fopen("./data.txt", "a+");
  if (!fp)
  {
    perror("File opening failed");
    // return EXIT_FAILURE
  }
  fputs("\n", fp);
  fputs(name, fp);
  fclose(fp);
}
