#include <stdio.h>

int raduis, area;

int main()
{
  printf("请输入半径：");
  scanf("%d", &raduis);
  area = (int)(3.1415926 * raduis * raduis);
  printf("\n\n面积=%d\n", area);
  return 0;
}