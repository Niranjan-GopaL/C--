#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/variable.h"
#include"../include/interpreter.h"



#define VARS_UPPER_BOUND   30



struct var vars[VARS_UPPER_BOUND];
int count=0;




void create_variable(char *token){
    vars[count].name = token;
}


void assign_variable(char *token){
    vars[count].value = atoi(token);
}


int get_variable_value(char *var_name){
    for(int i=0;i<count;i++)
        if( strcmp(vars[i].name,var_name) ==0 )
            return vars[i].value;
        
    
    return -1;
}




