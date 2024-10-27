#include <stdio.h>

#include "days.h"

struct day {
  void (*part1)(void);
  void (*part2)(void);
};

static struct day days[] = {
    {.part1 = day1_part1, .part2 = day1_part2},
    {.part1 = day2_part1, .part2 = day2_part2},
};

int main(void) {
  for (size_t i = 0; i < sizeof(days) / sizeof(struct day); i++) {
    printf("Day %zu:\n", i + 1);
    printf("  Part 1: ");
    (days[i].part1)();
    printf("\n");
    printf("  Part 2: ");
    (days[i].part2)();
    printf("\n");
  }
}
