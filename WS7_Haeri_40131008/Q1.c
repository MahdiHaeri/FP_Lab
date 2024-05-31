#include <stdio.h>

// return true if all of digits input number are 4 or 7 
bool lucky_number(long long number) {
  if (number == 0)
    return false;

  while (number != 0) {
    if (((number % 10) != 4) && (( number % 10) != 7)) {
      return false;
    }

    number /= 10;
  }
  return true;
}

// return count of digits 4 and 7 in input number
int count_of_lucky(long long number) {
  int counter = 0;
  while (number != 0) {
    if (lucky_number(number % 10)) {
      ++counter;
    }
    number /= 10;
  }
  return counter;
}

int main(int argc, char const *argv[]) {
  long long number;
  scanf("%lld", &number);

  // print count of digits 4 adn 7
  printf("count of lucky: %d\n", count_of_lucky(number));

  // print the input number is neighbor of lucky number of not
  if (lucky_number(count_of_lucky(number))) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return 0;
}
