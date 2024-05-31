#include <stdio.h>

#define SIZE 100
#define SEPARATOR '!'

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

// find cout of column if write text under each other
int find_column(char *string, int string_size) {
  int column = 0;
  for (int i = 0; i < string_size; i++) {
    if (string[i] == SEPARATOR) {
      return column;
    }
    column++;
  }
  return 0;
}

// find cout of row if write text under each other
int find_row(char *string, int string_size) {
  int row = 0;
  for (int i = 0; i < string_size; i++) {
    if (string[i] == SEPARATOR) {
      row++;
    }
  }
  return row + 1;
}

// remove SEPARATOR from text
void remove_separator(char *string, int string_size) {
  int delay_char = 0;
  for (int i = 0; i < string_size; i++) {
    while (string[i + delay_char] == SEPARATOR) {
      delay_char++;
      if(string[i + delay_char] == '\0') {
        break;
      }
    }
    string[i] = string[i + delay_char];
  }
}

// get the size of string
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

void print_normal_text(char *string, int column, int row) {
  for (int i = 0; i < column; i++) {
    for (int j = 0; j < row; j++) {
      if (string[i + (j * column)] != '\0') {
        printf("%c", string[i + (j * column)]);
      } else {
        printf(" ");
      }
    }
    if (i == (column - 1)) {
      printf("\n");
      return;
    }
  }
}

int main() {
  char text[SIZE];
  get_string(text); // get input text from user in one line
  int string_size = get_string_size(text);
  int column, row;

  column = find_column(text, string_size);
  row = find_row(text, string_size);
  
  remove_separator(text, string_size);
  print_normal_text(text, column, row);
  return 0;
}
