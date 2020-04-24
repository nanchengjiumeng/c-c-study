#include <stdio.h>
#include <string.h>

#define PI 3.14159

int main(void)
{
  char buffer[256];
  printf("Enter your name and press <Enter>: \n");
  fgets(buffer, 256, stdin);
  if (buffer[strlen(buffer) - 1] == '\n')
    buffer[strlen(buffer) - 1] = '\0';
  printf("\nYour name has %d characters and spaces!", (int)strlen(buffer));
  printf("\n%f", PI);
}