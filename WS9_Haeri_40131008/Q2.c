#include <stdio.h>

// find the combination of r from n with dynammic programing
int dp_combination(int n, int r) {
  int array[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || i == j) {
        array[i][j] = 1;
      } else {
        array[i][j] = (array[i - 1][j] + array[i - 1][j - 1]);
      }
    }
  }

  return array[n][r];
}

int main(int argc, char const *argv[]) {
  int n, r;
  printf("Please enter n and r for combination r from n:\n");
  scanf("%d %d", &n, &r);

  if (n < r) {
    printf("Oops! Incorrect input (n < r).\n");
    return 0;
  }

  // find the answer with dynammic programing
  int answer = dp_combination(n, r);

  printf("combination of %d from %d is: %d\n", r, n, answer);
  return 0;
}
