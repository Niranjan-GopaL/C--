#include<stdio.h>
#include"../include/arithmetic.h"
#include"../include/interpreter.h"


int perform_arithmetic(int x, char *op, int y)
{
    switch (*op)
    {
        case '+':
            return x+y;
            break;

        case '-':
            return x-y;
            break;

        case '/':
            return x/y;
            break;

        case '*':
            return x*y;
            break;
            
        default:
            return 0;
    }
}
