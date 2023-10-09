#include <stdio.h>
#include <stdbool.h>
#include "../src/condition.c"


void run_condition_tests();

// A macro for assertions
#define ASSERT(condition) \
    if (!(condition)) {   \
        printf("Test failed at line %d.\n", __LINE__); \
        return false;     \
    }


int evaluate_condition(int x, char *op, int y);


void run_condition_tests() {
    bool test_result;

    // Test 1: x > y
    test_result = evaluate_condition(5, ">", 3);
    ASSERT(test_result);

    // Test 2: x < y
    test_result = evaluate_condition(2, "<", 4);
    ASSERT(test_result);

    // Test 3: x == y
    test_result = evaluate_condition(7, "=", 7);
    ASSERT(test_result);

    // Test 4: Invalid operator
    test_result = evaluate_condition(1, "&", 2);
    ASSERT(!test_result);

    printf("All tests passed!\n");
}


