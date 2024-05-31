#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define SIZE 100

// change the capital character to small character
void lower(char *string) {
  for (int i = 0; i < SIZE; i++) {
    if (string[i] < 'a' && string[i] >= 'A') {
      string[i] = (char)(string[i] + ('a' - 'A'));
    }
  }
}

// get a string until user press an enter
void get_string(char *string) {
  char character;
  for (int i = 0; i < SIZE; i++) {
    scanf("%c", &character);
    if (character == '\n') {
      break;
    }
    string[i] = character;
  }
}


int get_string_size(char *string) {
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (string[i] == '\0') {
      break;
    }
    counter++;
  }
  return counter;
}

// check input character is there in alphabet character of don't
bool is_alphabet(char character) {
  if (character >= 'A' && character <= 'z') {
    return true;
  }
  return false;
}

// remove space and signs from input string
void remove_space_and_signs(char *string) {
  int delay_char = 0;
  for (int i = 0; i < SIZE; i++) {
    while (!is_alphabet(string[i + delay_char])) {
      delay_char++;
      if (string[i + delay_char] == '\0') {
        break;
      }
    }
    string[i] = string[i + delay_char];
  }
}

// remove space and signs from input string and change the capital character to small character
void make_normal_string(char *string) {
  remove_space_and_signs(string);
  lower(string);
}

void print_hashed_string(char *string, int c, int r) {
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      if (string[i + (j * c)] != '\0') {
        printf("%c", string[i + (j * c)]);
      } else {
        printf(" ");
      }
    }
    if (i == (c - 1)) {
      printf("\n");
      return;
    }
    printf("!");
  }
}

// find a value for column and row that have rules of question
void set_column_row(int *column, int *row, int string_size) {
  *column = (ceil(sqrt(string_size)));
  *row = *column;
  if (((*column) * (*row - 1)) >= string_size) {
    (*row)--;
  }
}

int main() {
  char text[SIZE];

  get_string(text); // get input string without know size of string, finish by an enter
  make_normal_string(text);
  int string_size = get_string_size(text);

  int column, row; // Columns and Rows of square
  set_column_row(&column, &row, string_size);

  print_hashed_string(text, column, row);
  return 0;
}
