#include <stdio.h>
#include <stdbool.h> 

#define MAX_STRING_LENGTH 100

// Function to compare two strings
bool compare_strings(char first_string[], char second_string[]) {
  int i = 0;
  while (first_string[i] != '\0' && second_string[i] != '\0') { // loop until the end of the strings
    if (first_string[i] != second_string[i]) { // if the characters are not equal return false
      return false;
    }
    i++;
  }
  return true; // if the strings are equal return true 
}

int main(int argc, char const *argv[]) {
  char first_string[MAX_STRING_LENGTH]; 
  char second_string[MAX_STRING_LENGTH]; 

  printf("Enter the first string: ");
  fgets(first_string, MAX_STRING_LENGTH, stdin); // get first string from user
  
  printf("Enter the second string:");
  fgets(second_string, MAX_STRING_LENGTH, stdin);  // get second string from user

  if (compare_strings(first_string, second_string)) {
    printf("The strings are equal"); 
  } else { 
    printf("The strings are not equal");
  }
  return 0;
}
