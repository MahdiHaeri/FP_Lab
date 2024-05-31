#include <stdio.h>

int memoization_array[1000];

// return fibonachi by memoization
int memoization_fib(int n) {
  if (n == 1 || n == 0) {
    return 1;
  }

  if (memoization_array[n] == 0) {
    memoization_array[n] = memoization_fib(n - 1) + memoization_fib(n - 2);
  }
  return memoization_array[n];
}

// return fibonachi by dynammic programing
int dp_fib(int n) {
  int array[n];

  array[0] = 1;
  array[1] = 1;

  for (int i = 2; i <= n; i++) {
    array[i] = array[i - 1] + array[i - 2];
  }

  return array[n];
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  // print fibonachi with dynammic programing
  printf("fib(%d) = %d \n", n, dp_fib(n));

  // print fibonachi with memoization
  printf("fib(%d) = %d \n", n, memoization_fib(n));
  return 0;
}
