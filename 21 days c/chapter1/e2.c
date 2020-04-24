#include <stdio.h>

int x, y, door = 2, amount = 54;

int main(void)
{
  printf("请输入门所在的那面墙的长度:\n");
  scanf("%d", &x);
  y = (54 + 2 - x) / 2;
  printf("两侧墙的长度都为:%d\n", y);
  return 0;
}