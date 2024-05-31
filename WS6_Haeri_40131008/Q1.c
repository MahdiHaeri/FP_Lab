#include <stdio.h>
#include <math.h>

double to_radian(double degree) {
  return ((M_PI * degree) / 180);
}

double to_degree(double radian) {
  return ((180 * radian) / M_PI);
}

int main() {
  double input_sin, cosinuse;
  char sign;

  printf("Please enter sin: ");
  scanf("%lf", &input_sin);

  while (input_sin > 1 || input_sin < -1) {
    printf("Incurrect input!\ntry again: ");
    scanf("%lf", &input_sin);
  }

  printf("Please enter sign (+, -): ");
  getchar();
  scanf("%c", &sign);

  while (sign != '+' && sign != '-') {
    printf("Incurrect input!\ntry again: ");
    getchar();
    scanf("%c", &sign);
  }

  cosinuse = sqrt(1 - (input_sin * input_sin));

  if (sign == '-') {
    cosinuse = -cosinuse;
  }

  printf("cosinuse: %lf\n", cosinuse);

  if (input_sin > 0) {
    if (cosinuse > 0) {
      printf("1\n");
    } else if (cosinuse < 0) {
      printf("2\n");
    } else {
      printf("90 degree\n");
    }
  } else if (input_sin < 0) {
    if (cosinuse > 0) {
      printf("4\n");
    } else if (cosinuse < 0) {
      printf("3\n");
    } else {
      printf("270 degree\n");
    }
  } else {
    if (cosinuse > 0) {
      printf("0 degree\n");
    } else {
      printf("180 degree\n");
    }
  }


  return 0;
}
