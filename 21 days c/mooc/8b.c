#include <stdio.h>
#include <string.h>
int verification_instruction(char *instruction);
void GPRMC_bei_jing_time(char *instruction, char *time_str_bj);

int main(int argc, char const *argv[])
{
  /* code */
  char instruction[128] = "";
  char time_str_bj[7];
  do
  {
    scanf("%s", instruction);
    int ret = verification_instruction(instruction);
    if (ret)
    {
      GPRMC_bei_jing_time(instruction, time_str_bj);
    }
    /* code */
  } while (!strstr(instruction, "END"));
  printf("%c%c:%c%c:%c%c",
         time_str_bj[0], time_str_bj[1],
         time_str_bj[2], time_str_bj[3],
         time_str_bj[4], time_str_bj[5]);
  return 0;
}

// $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
int verification_instruction(char *instruction)
{
  int ret = 0;
  if (strstr(instruction, "$GPRMC") && strstr(instruction, "*"))
  {
    long check_code = instruction[1] ^ instruction[2];
    long check_value = 0;
    char *ch = &instruction[3];
    while (*ch != '*')
    {
      check_code = check_code ^ *ch;
      ch++;
    }
    ch++;
    if (*ch < 58)
      check_value += (long)(*ch - 48) * 16;
    else
      check_value += (long)(*ch - 55) * 16;
    ch++;
    if (*ch < 58)
      check_value += (long)(*ch - 48);
    else
      check_value += (long)(*ch - 55);
    // printf("\n%ld", check_value);
    if (check_code % 65536 == check_value)
      ret = 1;
  }
  if (ret == 1 && instruction[8] == ',')
  {
    ret = 0;
  }
  return ret;
}

void GPRMC_bei_jing_time(char *instruction, char *time_str_bj)
{
  // printf("%s\n", instruction);
  char time_str[7] = "";
  int utc_time_pos = 7;
  int utc_time_len = 10 - 4;
  for (int i = 0; i < utc_time_len; i++)
  {
    time_str[i] = instruction[utc_time_pos + i];
  }
  //024813
  int bjh = ((time_str[0] - 48) * 10 + (time_str[1] - 48) + 24 + 8) % 24;
  time_str[0] = bjh / 10 + 48;
  time_str[1] = bjh % 10 + 48;
  strcpy(time_str_bj, time_str);
}
