#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double get_maximum(double *array, int size) { // function to get the maximum number in the array
    double* maximum = array;
    for (int i = 1; i < size; i++) {
        if (*(array + i) > *maximum) {
            maximum = (array + i);
        }
    }
    return *maximum;
}

int main(int argc, char const *argv[]) {
    double *pointer = NULL; // pointer to the array of numbers 
    int size_of_array = 0; 
    double input_number;

    printf("Enter a list of numbers: \n");  
    while (scanf("%lf", &input_number)) { // loop until the user enter a non-number
        size_of_array++;
        pointer = (double*) realloc(pointer, size_of_array * sizeof(double));
        pointer[size_of_array - 1] = input_number;
    }

    printf("The maximum is %f\n", get_maximum(pointer, size_of_array));

    return 0;
}
