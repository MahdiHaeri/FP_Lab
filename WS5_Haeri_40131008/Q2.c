#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int _random(int start, int end) {
  return ((rand() % (end - start)) + start + 1);
}

double to_radian(double deg) {
  return (M_PI * deg / 180);
}

double to_degree(double radian) {
  return (180 * radian / M_PI);
}

int main() {
  srand(time(NULL));

  double a = _random(5, 25);
  double b = _random(5, 25);
  double deg_c = _random(0, 90);

  // double a, b, deg_c;
  // scanf("%lf %lf %lf", &a, &b, &deg_c);

  printf("random input:\na: %.0lf\nb: %.0lf\ndeg_c: %.0lf\n\n", a, b, deg_c);

  double c = sqrt((a * a) + (b * b) - (2 * a * b * cos(to_radian(deg_c))));

  double deg_a = to_degree(asin(((sin(to_radian(deg_c)) * a) / c)));
  double deg_b = to_degree(asin(((sin(to_radian(deg_c)) * b) / c)));
  if ((deg_a + deg_b + deg_c) != 180) {
    if(a > b) {
      deg_a = 180 - deg_a;
    } else {
      deg_b = 180 - deg_b;
    }
  }
  printf("answer:\nc: %lf\ndeg_a: %lf\ndeg_b: %lf\n", c, deg_a, deg_b);

  return 0;
}
