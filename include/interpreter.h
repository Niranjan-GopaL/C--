#ifndef INTERPRETER_H
#define INTERPRETER_H

void execute_c_minus_minus(char *code);

struct var
{
    char*name;
    int value;
};
extern struct var vars[];
extern int count;
#endif /* INTERPRETER_H */
