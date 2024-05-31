#include <stdio.h>
#include <math.h>

// Get fib(n) by recersive way
long long recersive_fib(long long n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return (recersive_fib(n - 1) + recersive_fib(n - 2));
}

// Get fib(n) by direct way
long long fib(int n) {
  long long first = 1, second = 1, temp;
  for (int i = 1; i < n; i++) {
    temp = first;
    first = first + second;
    second = temp;
  }
  return first;
}

// Get fib(n) by formoul 
long long fib_by_formoul(int n) {
  n++;
  return ((pow(((1.0 + sqrt(5)) / 2.0), n) - (pow((1.0 - sqrt(5)) / 2.0, n))) / sqrt(5));
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  printf("%lld\n", fib_by_formoul(n));
  printf("%lld\n", fib(n));
  printf("%lld\n", recersive_fib(n));

  return 0;
}
