#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// return true if input number is a prime number
bool is_prime_number(int number) {
  for (int i = 2; i < sqrt(number); i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

// return number of digits in input number
int number_of_digits(int number) {
 int counter = 0;
 while (number != 0) {
   counter++;
   number /= 10;
 }
 return counter;
}

bool is_upper_prime_number(int number) {
  int slice = 10;
  for (int i = 0; i < number_of_digits(number); i++) {
    if (!is_prime_number(number % slice)) {
      return false;
    }
    slice *= 10;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  // get input ---> number
  int number;
  scanf("%d", &number);

  // check the number is upper prime or not
  if (is_upper_prime_number(number)) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return 0;
}
