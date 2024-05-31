#include <stdio.h>

#define N 5 // the heights of shape 

int main(int argc, char const *argv[]) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (N * 2 - 1); j++) {

      if (j <= i) {
        printf("%d", j + 1); // print left side of triangle
      } else if (j >= ((N * 2 - 2) - i)) {
        printf("%d", (N * 2 - 1) - j); // print right side of triangle
      } else {
        printf(" "); // print the space between tow triangle
      }
    }
    printf("\n");
  }

  return 0;
}
