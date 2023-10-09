# C--

C-- is a simple C-based interpreter for executing C-like code 
with basic arithmetic operations, variable assignments, printing variables, 
and conditional statements.

## Features

- Supports integer variable assignments (int x = 10;).
- Handles arithmetic operations on variables (int z = x + y;).
- Prints the values of variables (print z;).
- Evaluates simple conditional statements (if (z > 10) { ... }).
- All unit tests are written in `./test` folder
- There are comphrehensive makefiles for :- 
    - Building the project
    - Unit Testing

## Usage

> To use C-Minus-Minus, you can include the necessary header files and 
> call the execute_c_minus_minus function with your code as a string.


## Building and Running

In the project directory open terminal and run :- 

```shell
make cmm
```

In order to unit test, go to the `./tests` folder and run :-

> NOTE : 
> - `make clear` after after you used makefile in the project directory.
> - otherwise makefile in tests/ folder won't work


```shell
make run_tests
```
