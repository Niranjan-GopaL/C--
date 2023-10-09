#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "../include/interpreter.h"
#include "../include/print.h"
#include "../include/variable.h"
#include "../include/arithmetic.h"
#include "../include/condition.h"



#define space                  " "
#define newline                "\n"
#define LAST(str)              strlen(str) - 1
#define STRING_TERMINATOR      '\0'


void new_variable( char* var_name, char* variable_1 );



void execute_c_minus_minus(char *code)
{

    print_nl();

    // it will break the code at newlines 
    char *current_token = strtok(code,newline); 
    char *save_ptr      = NULL;


    while( current_token != NULL )
    {
        // token is 'int'
        char *token = strtok_r( current_token, space, &save_ptr);

        if( strcmp(token,"int") == 0 ){

            token = strtok_r(NULL, space, &save_ptr);
            // x
            char *var_name = token;

            //  =
            token = strtok_r(NULL,space,&save_ptr);
            // 10;
            token = strtok_r(NULL,space,&save_ptr);
            

            
            // var_name -> name of variable
            // literal_1      -> value of variable
            

            // literal_1 = '10;' or 'x'
            char *literal_1 = token;

            // replacing ; with \0 <- does not work in {-> int z = x + y
            if( literal_1[ LAST(literal_1) ] == ';')
                literal_1[ LAST(literal_1) ] = STRING_TERMINATOR;
            

            // vars[count].name , vars[count].value , 
            // atoi('x') will be the case for {-> int z = x + y case  
            // ATOI("123") ----> 123
            if(atoi(literal_1)) new_variable(var_name, literal_1);
            
        
            // ATOI("STRING") ----> 0 
            else{

                
                token = strtok_r(NULL,space,&save_ptr); char *operation = token;

                token = strtok_r(NULL,space,&save_ptr); char *literal_2 = token;

                literal_2[LAST(literal_2)] = STRING_TERMINATOR;

                // value_1 -> 10
                // value_2 -> 5
                int value_1 = get_variable_value(literal_1);
                int value_2 = get_variable_value(literal_2);
                
                // result
                int result  = perform_arithmetic(value_1, operation, value_2);
                
                // result
                char *result_value = malloc(sizeof(char)*20);

                // format and store a series of characters (a string) 
                // into a character array (a buffer). 
                sprintf(result_value,"%d",result);

                // convert an integer `result` into its string representation 
                // and store it in the character array `result_value`
                new_variable(var_name, result_value);

            }
            
        }


        else if(strcmp(token, "print") == 0){

            // w
            token = strtok_r(NULL, space, &save_ptr);

            char *name_print = token;
            name_print[LAST(name_print)] = STRING_TERMINATOR;

            print_variable(name_print);

        }

        else if( strcmp(token,"if") == 0 ){

            // (z
            token = strtok_r(NULL,space,&save_ptr);
            char *variable_1 = token;

            // removing (
            // now variable_1 --> z
            variable_1++;

            // value if z
            int value_1 = get_variable_value(variable_1);

            // operation
            token=strtok_r(NULL,space,&save_ptr);
            char *op = token;

            // 10
            token=strtok_r(NULL,space,&save_ptr);
            char *literal_2 = token;

            literal_2[LAST(literal_2)] = STRING_TERMINATOR;


            int value_2=atoi(literal_2);
            if(evaluate_condition(value_1, op, value_2))
            {
                current_token=strtok(NULL,newline);
                continue;
            }
            else
                break;
            
        }
        else
            break;
        
        current_token=strtok(NULL, newline);
    }
}



void new_variable( char* var_name, char* variable_1 ){
    create_variable(var_name);
    assign_variable(variable_1);
    count++;
}

void print_nl(){
    for (int i = 0; i < 5; i++)
        printf(newline);
}



// int main() {
//     char code[] =
//         "int x = 10;\n"
//         "int y = 5;\n"
//         "int z = x + y;\n"
//         "print z;\n"
//         "if (z > 10) {\n"
//         "    int w = 20;\n"
//         "    print w;\n"
//         "}";


//     execute_c_minus_minus(code);

//     return 0;
// }