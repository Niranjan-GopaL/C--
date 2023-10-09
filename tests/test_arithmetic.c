#include <stdio.h>
#include "../src/arithmetic.c"



int run_arithmetic_tests() {
    int result;

    // Test addition
    result = perform_arithmetic(5, "+", 3);
    if (result == 8) {
        printf("Test passed: Addition\n");
    } else {
        printf("Test failed: Addition\n");
    }

    // Test subtraction
    result = perform_arithmetic(10, "-", 4);
    if (result == 6) {
        printf("Test passed: Subtraction\n");
    } else {
        printf("Test failed: Subtraction\n");
    }

    // Test division
    result = perform_arithmetic(12, "/", 3);
    if (result == 4) {
        printf("Test passed: Division\n");
    } else {
        printf("Test failed: Division\n");
    }

    // Test multiplication
    result = perform_arithmetic(6, "*", 7);
    if (result == 42) {
        printf("Test passed: Multiplication\n");
    } else {
        printf("Test failed: Multiplication\n");
    }

    // Test invalid operator
    result = perform_arithmetic(8, "%", 2); // Using '%' as an invalid operator
    if (result == 0) {
        printf("Test passed: Invalid operator\n");
    } else {
        printf("Test failed: Invalid operator\n");
    }

    return 0;
}
