#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  int maxColumnInRow[n];
  long maxInRow[n];
  int minRowInColumn[n];
  long minInColumn[n];
  for (int i = 0; i < n; i++)
  {
    maxInRow[i] = -1;
    minInColumn[i] = LONG_MAX;
  }

  for (int i = 0; i < n * n; i++)
  {
    long a;
    int row = i / n,
        column = i % n;
    scanf("%ld", &a);
    if (a > maxInRow[row])
    {
      maxInRow[row] = a;
      maxColumnInRow[row] = column;
    }
    if (a < minInColumn[column])
    {
      minInColumn[column] = a;
      minRowInColumn[column] = row;
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   printf("%d \t", maxColumnInRow[i]);
  //   /* code */
  // }
  // printf("\n");
  // for (int i = 0; i < n; i++)
  // {
  //   printf("%d \t", minRowInColumn[i]);
  //   /* code */
  // }
  // printf("\n");

  int ret_row = -1, ret_column = -1;
  for (int row = 0; row < n; row++)
  {
    if (minRowInColumn[maxColumnInRow[row]] == row)
    {
      ret_row = row;
      ret_column = maxColumnInRow[row];
      break;
    }
  }
  if (ret_row >= 0 && ret_column >= 0)
  {
    printf("%d %d", ret_row, ret_column);
  }
  else
  {
    printf("NO");
  }

  return 0;
}
