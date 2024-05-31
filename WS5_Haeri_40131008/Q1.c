#include <stdio.h>

int main() {
  int number;
  char character;

  printf("please enter you number: ");
  scanf("%d", &number);

  getchar();

  printf("please enter your character: ");
  scanf("%c", &character);

  character = character + number;

  if (character >= 97) {
    printf("%c %c\n", character, character - ('a' - 'A'));
  } else {
    printf("%c %c\n", character + ('a' - 'A'), character);
  }

  return 0;
}
