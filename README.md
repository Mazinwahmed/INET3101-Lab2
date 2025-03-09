# INET3101 Lab 2  
## Memory Management in C  

### Authors  
Code written by Mazin Ahmed and Ahmad Minhas  

## Overview  
This project is a simple C program that demonstrates dynamic memory allocation for managing part records. It allows users to add and delete records while keeping track of the total number of entries. The program uses `malloc()`, `free()`, and optionally `realloc()` for efficient memory management.  

## Features  
- Dynamically allocate memory for part records  
- Store part details such as:  
  - **Part Number** (`int`)  
  - **Part Name** (`char array`)  
  - **Part Size** (`float`)  
  - **Part Size Unit** (`char array`)  
  - **Part Cost** (`float`)  
- Interactive menu with options to:  
  1. Print all records  
  2. Print the number of records  
  3. Print the database size  
  4. Add a new record  
  5. Delete the last added record  
  6. Exit the program  
- Uses manual memory management without arrays or linked lists  


## Compilation and Execution  
To compile and run the program, use the following commands:  

```sh
gcc -o lab2 lab2.c
./lab2
