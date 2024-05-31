#include <stdio.h>

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int main(int argc, char const *argv[]) {
  int n;
  printf("please enter count of numbers in array: ");
  scanf("%d", &n);
  int array[n];

  printf("please enter your numbers: ");
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    array[i] = x;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (array[j + 1] < array[j]) {
        swap(array, j, j + 1);
      }
    }
  }
  
  printf("sorted array is: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
