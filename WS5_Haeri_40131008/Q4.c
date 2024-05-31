// add #include <stdio.h> for fixing the warning error
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// change "Main" to "main" because it had linker error
int main() {
    // change type of num1, num2, result from int to double because in sin, cos, tan, we have need double type
    // and change all of %d to %lf because i change type of num1, num2, num3 from int to double and %lf is used for double
    double num1, num2;                 // input values
    char op;                        // operator
    double result;                     // output
    // change "Printf" to "printf" because c is case sensitive language and ‘Printf’ was not declared in this scope.
    printf("Choose operation to perform (+, -, *, /, %%, sin, cos, tan): ");
    // scanf() need address of variable of op ---> waring error
    scanf("%c", &op);

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    // add a ';' in the end of this command for showing the command finished ---> compiler error
    scanf("%lf", &num2);

    // do the operation
    if(op == '+') {
        // the part that calculates the sum of two numbers
        result = num1 + num2;
    }
    else if(op == '-') {
        // the part that calculates the difference of two numbers
        result = num1 - num2;
    }
    else if(op == '*') {
        // the part that calculates the product of two numbers
        result = num1 * num2;
    }
    else if(op == '/') {
        // the part that calculates the division of two numbers
        // if denominator equals to zero exit the program
        if(num2 == 0) {
            printf("invalid input! divide by zero");
            return -1;
        }
        else {
            result = num1 / num2;
        }
    }
    else if(op == '%') {
        // the part that calculates the remainder of a number over another number
        if ((num1 - (int)num1 == 0) && (num2 - (int)num2) == 0) {
            result = (int)num1 % (int)num2;
        }
        else {
            printf("incorrect input");
            return 0;
        }
    }
    else if(op == 's') {
        // the part that calculates sine of an angle
        result = sin(num1 / num2);
    }
    else if(op == 'c') {
        //the part that calculates the cosine of an angle
        result = cos(num1 / num2);
    }
    else if(op == 't') {
        // the part that calculates the tangent of an angle
        result = tan(num1 / num2);
    }

    // print result
    // add '\n' in the end of all printf message because is better
    if(op == 's') {
        printf("result : sin(%lf/%lf) = %lf\n", num1, num2, result);
    }
    else if(op == 'c') {
        printf("result : cos(%lf/%lf) = %lf\n", num1, num2, result);
    }
    else if(op == 't') {
        printf("result : tan(%lf/%lf) = %lf\n", num1, num2, result);
    }
    else if(op == '%') {
        // add '.0' before 'lf' for print double number as integer number
        printf("result : %.0lf %% %.0lf = %.0lf\n", num1, num2, result);
    }
    else {
        printf("result : %lf %c %lf = %lf\n", num1, op, num2, result);
    }

    return 0;
}
