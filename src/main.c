#include <stdio.h>
#include <stdlib.h>
#include "../include/interpreter.h"


int main() {
    char code[] =
        "int a = 10;\n"
        "int x = 10;\n"
        "int y = 5;\n"
        "int z = x + y;\n"
        "print z;\n"
        "print a;\n"
        "if (z > 10) {\n"
        "    int w = 20;\n"
        "    print w;\n"
        "}\n";


    execute_c_minus_minus(code);

    return 0;
}


// int main() {

//     FILE *file;
//     // Assuming each line is at most 100 characters long
//     char line[100]; 
//     // Assuming there are at most 100 lines
//     char *code[100]; 

//     // Open the file for reading
//     file = fopen("./../input.txt", "r");
//     if (file == NULL) {
//         perror("Unable to open the file");
//         return 1;
//     }


//     int lineCount = 0;

//     while (fgets(line, sizeof(line), file) != NULL) {
        
//         code[lineCount] = strdup(line);
//         lineCount++;

//     }



//     fclose(file);

//     // Print each element of the code array
//     // for (int i = 0; i < lineCount; i++) {
//     //     printf("Line %d: %s\n", i + 1, code[i]);
//     // }

//     execute_c_minus_minus(code);


//     // Free the allocated memory
//     for (int i = 0; i < lineCount; i++) {
//         free(code[i]);
//     }

//     return 0;
// }





/*
    int lineCount = 0;

    // Read lines from the file and store them in the code array
    while (fgets(line, sizeof(line), file) != NULL) {

        // Remove the newline character at the end of each line
        if (lineCount > 0 && line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        
        // Allocate memory for the line and copy it to the code array
        code[lineCount] = strdup(line);
        lineCount++;

        // Check if the code array is full (you can resize it if needed)
        if (lineCount >= 100) {
            printf("Too many lines in the file\n");
            break;
        }
    }
*/
