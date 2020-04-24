#include <stdio.h>
#define ARRMAX 200
int main(int argc, char const *argv[])
{
  int a, b;
  int remainder = 0;
  int ret[ARRMAX] = {0};
  unsigned cur_bit = 0;
  scanf("%d/%d", &a, &b);
  remainder = a % b;
  while (remainder > 0 && cur_bit < 200)
  {
    remainder *= 10;
    ret[cur_bit] = remainder / b;
    remainder = remainder % b;
    cur_bit++;
    /* code */
  }
  printf("%s", "0.");
  for (int i = 0; i < cur_bit; i++)
  {
    printf("%d", ret[i]);
  }
  printf("%s", "\n");
  return 0;
}
