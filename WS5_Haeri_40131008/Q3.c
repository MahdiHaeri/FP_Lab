#include <stdio.h>

int main(int argc, char const *argv[]) {
  int input_second;
  printf("home many second? ");
  scanf("%def\n", &input_second);

  int day = input_second / 86400;
  input_second %= 86400;
  int hour = input_second / 3600;
  input_second %= 3600;
  int minute = input_second / 60;
  input_second %= 60;
  int second = input_second;
  printf("day: %d   hour: %d   minute: %d   second: %d   \n", day, hour, minute, second);

  return 0;
}
