#include <stdio.h>

void print_base_change(int a, int b) {
  int stack[100]; 
  int i = 0;
  while (a != 0) {
    stack[i] = (a % b);
    a /= b;
    i++;
  }
  while (i > 0) {
    --i;
    printf("%d", stack[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int a, b;
  scanf("%d %def\n",&a, &b);
  print_base_change(a, b);
  return 0;
}
