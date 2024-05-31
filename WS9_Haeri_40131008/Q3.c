#include <stdio.h>

#define MAX_SIZE 100

int count_of_character_in_array(char character, char array_of_character[], int size) {
  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (array_of_character[i] == character) {
      counter++;
    }
  }

  return counter;
}

int find_size_of_string(char *string) {
  int counter = 0;
  for (int i = 0; i < MAX_SIZE; i++) {
    if (string[i] == '\0') {
      return counter;
    }
    counter++;
  }
  return counter;
}

int main() {
  char array_of_character[MAX_SIZE];
  printf("\n Please Enter any String: ");
  // get a line of string and set that to array_of_character
  gets(array_of_character);
  // find size of string the gets from input
  int string_size = find_size_of_string(array_of_character);

  char max_repeat_character; // character that repeat more than other characters
  int maximume_repeat, current_repeat;

  // find maximume_repeat and and max_repeat_character
  for (int i = 0; i < string_size; i++) {
    current_repeat = count_of_character_in_array(array_of_character[i], array_of_character, string_size);
    if (current_repeat > maximume_repeat) {
      maximume_repeat = current_repeat;
      max_repeat_character = array_of_character[i];
    } else if (current_repeat == maximume_repeat && array_of_character[i] < max_repeat_character) {
      maximume_repeat = current_repeat;
      max_repeat_character = array_of_character[i];
    }
  }

  printf("\'%c\': %d\n", max_repeat_character, maximume_repeat);

  return 0;
}
