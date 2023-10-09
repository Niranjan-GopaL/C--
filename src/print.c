#include<stdio.h>
#include<string.h>
#include"../include/interpreter.h"
#include"../include/print.h"



void print_variable(char *token)
{
    for(int i=0; i<count; i++)
    {
        if(strcmp(vars[i].name,token)==0)
        {
            printf("%s=%d\n",token,vars[i].value);
            return;
        }
    }
}

