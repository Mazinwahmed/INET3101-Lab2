# INET3101 Lab2
## Code for INET 3101 Lab 2
Written by Mazin Ahmed and Ahmad Minhas
# Memory Management in C

## Overview
This project is a simple C program that demonstrates dynamic memory allocation for managing part records. It allows users to add and delete records while keeping track of the total number of entries. The program uses `malloc()`, `free()`, and optionally `realloc()` for efficient memory management.

## Features
- Dynamically allocate memory for part records
- Store part details such as:
  - Part Number (`int`)
  - Part Name (`char array`)
  - Part Size (`float`)
  - Part Size Unit (`char array`)
  - Part Cost (`float`)
- Interactive menu with options to:
  - Print all records
  - Print the number of records
  - Print the database size
  - Add new records
  - Delete the last added record
- Uses manual memory management without arrays or linked lists

## Usage
To compile and run the program:

```sh
gcc -o memory_management memory_management.c
./memory_management
