#include <stdio.h>

#include "days.h"
#include "input/day1.h"

void day1_part1(void) {
  int result = 0;

  for (unsigned int i = 0; i < SRC_INPUT_DAY1_LEN; i++) {
    if (SRC_INPUT_DAY1[i] == '(')
      result++;
    if (SRC_INPUT_DAY1[i] == ')')
      result--;
  }

  printf("%d", result);
}

void day1_part2(void) {
  int result = 0;
  unsigned int i = 0;

  for (i = 0; i < SRC_INPUT_DAY1_LEN; i++) {
    if (SRC_INPUT_DAY1[i] == '(')
      result++;
    if (SRC_INPUT_DAY1[i] == ')')
      result--;

    if (result == -1) {
      break;
    }
  }

  printf("%u", i);
}