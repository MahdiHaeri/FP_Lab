#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 100

void recersive_print(int i, int j, int n, char my_map[][ARRAY_SIZE]) {
  if (n == 0) {
    my_map[i][j] = '*';
  } else {
    n /= 2;

    // call three recersive_print function in three point of 2d array
    recersive_print(i, j, n, my_map);
    recersive_print(i + n, j - n, n, my_map);
    recersive_print(i + n, j + n, n, my_map);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  // make an 2d array
  char my_map[ARRAY_SIZE][ARRAY_SIZE];

  // set all cell of array with space character
  for (int i = 0; i < ARRAY_SIZE; i++) {
    for (int j = 0; j < ARRAY_SIZE; j++) {
      my_map[i][j] = ' ';
    }
  }

  // make triangel with recersive solution
  recersive_print(0, n, n, my_map);


  // print all of array 2D
  for (int i = 0; i < ARRAY_SIZE; i++) {
    for (int j = 0; j < ARRAY_SIZE; j++) {
      printf("%c", my_map[i][j]);
    }
    printf("\n");
  }
  return 0;
}
