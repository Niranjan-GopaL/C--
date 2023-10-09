#include<stdio.h>
#include<stdbool.h>
#include"../include/interpreter.h"
#include"../include/condition.h"



int evaluate_condition(int x, char *op, int y)
{
    
    switch( op[0] )
    {
        case'>':
            return x>y;  
            break;

        case'<':
            return x<y;  
            break;

        case'=':
            return x==y;  
            break;

        default:
            return 0;
    }

}







