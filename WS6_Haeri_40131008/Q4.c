#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[]) {
  double left_side[3], right_side[3];
  double left = -INFINITY, right = +INFINITY;

  // get input
  for (int i = 0; i < 3; i++) {
    printf("please enter range %d: ", i + 1);
    scanf("%lf %lf", &left_side[i], &right_side[i]);
  }

  // set left to maximum left_sides and set right to minimum right_sides
  for (int i = 0; i < 3; i++) {
    if (left < left_side[i]) {
      left = left_side[i];
    }
    if (right > right_side[i]) {
      right = right_side[i];
    }
  }

  if (left <= right) {
    printf("(%lf, %lf)\n", left, right);
  } else {
    printf("there is no rage for answer\n");
  }

  return 0;
}
