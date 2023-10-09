#include <stdio.h>
#include <stdbool.h>

// Function prototypes for test functions
extern void run_arithmetic_tests();
extern void run_condition_tests();

int main() {
    printf("Running Arithmetic Tests:\n");
    run_arithmetic_tests();

    printf("\nRunning Condition Tests:\n");
    run_condition_tests();

    return 0;
}


