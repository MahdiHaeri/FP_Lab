#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double num1, num2;                 // input values
  int op;                        // operator
  double result;

  double input_sin, cosinuse;
  char sign;

  printf("Choose operation to perform (1: +, 2: -, 3: *, 4: /, 5: %%, 6: sin, 7: cos, 8: tan, 9: triangle question): ");
  scanf("%d", &op);

  if (op != 9) {
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
  } else {
    printf("Please enter sin: ");
    scanf("%lf", &input_sin);

    while (input_sin > 1 || input_sin < -1) {
      printf("Incurrect input!\ntry again: ");
      scanf("%lf", &input_sin);
    }

    printf("Please enter sign: ");
    getchar();
    scanf("%c", &sign);

    while (sign != '+' && sign != '-') {
      printf("Incurrect input!\ntry again: ");
      getchar();
      scanf("%c", &sign);
    }
  }

  switch (op) {
    case 1:
      // the part that calculates the sum of two numbers
      result = num1 + num2;
    break;

    case 2:
      // the part that calculates the difference of two numbers
      result = num1 - num2;
    break;

    case 3:
      // the part that calculates the product of two numbers
      result = num1 * num2;
    break;

    case 4:
      // the part that calculates the division of two numbers
      // if denominator equals to zero exit the program
      if(num2 == 0) {
        printf("invalid input! divide by zero");
        return -1;
      }
      else {
        result = num1 / num2;
      }
    break;

    case 5:
      // the part that calculates the remainder of a number over another number
      if ((num1 - (int)num1 == 0) && (num2 - (int)num2) == 0) {
        result = (int)num1 % (int)num2;
      }
      else {
        return 0;
      }
    break;

    case 6:
      // the part that calculates sine of an angle
      result = sin(num1 / num2);
    break;

    case 7:
      //the part that calculates the cosine of an angle
      result = cos(num1 / num2);
    break;

    case 8:
      // the part that calculates the tangent of an angle
      result = tan(num1 / num2);
    break;

    case 9:
      cosinuse = sqrt(1 - (input_sin * input_sin));

      if (sign == '-') {
        cosinuse = -cosinuse;
      }

      printf("cosinuse: %lf\n", cosinuse);

      if (input_sin > 0) {
        if (cosinuse > 0) {
          printf("1\n");
        } else if (cosinuse < 0) {
          printf("2\n");
        } else {
          printf("90 degree\n");
        }
      } else if (input_sin < 0) {
        if (cosinuse > 0) {
          printf("4\n");
        } else if (cosinuse < 0) {
          printf("3\n");
        } else {
          printf("270 degree\n");
        }
      } else {
        if (cosinuse > 0) {
          printf("0 degree\n");
        } else {
          printf("180 degree\n");
        }
      }
      return 0;
    break;

    default:
      printf("your input is not currect!\n");
    break;
  };

  switch (op) {
    case 1:
      printf("result : %lf + %lf = %lf\n", num1, num2, result);
    break;
    case 2:
      printf("result : %lf - %lf = %lf\n", num1, num2, result);
    break;
    case 3:
      printf("result : %lf * %lf = %lf\n", num1, num2, result);
    break;
    case 4:
      printf("result : %lf / %lf = %lf\n", num1, num2, result);
    break;
    case 5:
      printf("result : %.0lf %% %.0lf = %.0lf\n", num1, num2, result);
    break;
    case 6:
      printf("result : sin(%lf/%lf) = %lf\n", num1, num2, result);
    break;
    case 7:
      printf("result : cos(%lf/%lf) = %lf\n", num1, num2, result);
    break;
    case 8:
      printf("result : tan(%lf/%lf) = %lf\n", num1, num2, result);
    break;
  }

  return 0;
}
