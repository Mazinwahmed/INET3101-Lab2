#include <stdio.h>
#include <stdlib.h>

// stores part info and defines "part" type that holds details of a given part
typedef struct {
    int part_number;
    char part_name[50];
    float part_size;
    char part_size_metric[10];
    float part_cost;
} Part;

// pointer and counter for parts
Part *database = NULL;
int num_records = 0;

// function to add a new part by allocating new memory space
void add_record() {
    Part *new_db = malloc((num_records + 1) * sizeof(Part));
    if (new_db == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    // copies existing records to new memory
    for (int i = 0; i < num_records; i++) {
        new_db[i] = database[i];
    }
    
    // new part details inputed from user
    printf("part number: ");
    scanf("%d", &new_db[num_records].part_number);
    printf("part name: ");
    scanf("%s", new_db[num_records].part_name);
    printf("part size: ");
    scanf("%f", &new_db[num_records].part_size);
    printf("part size metric: ");
    scanf("%s", new_db[num_records].part_size_metric);
    printf("part cost: ");
    scanf("%f", &new_db[num_records].part_cost);
    
    // updates pointer and frees old memory
    free(database);
    database = new_db;
    num_records++;
    printf("part has been added.\n");
}

// function to delete the last added part
void delete_record() {
    if (num_records == 0) {
        printf("no parts to delete.\n");
        return;
    }
    
    // allocates new memory 
    Part *new_db = malloc((num_records - 1) * sizeof(Part));
    if (new_db == NULL && num_records > 1) {
        printf("memory allocation failed.\n");
        return;
    }
    
    // copies all records besides the last into new memory
    for (int i = 0; i < num_records - 1; i++) {
        new_db[i] = database[i];
    }
    
    // updates pointer and frees old memory
    free(database);
    database = new_db;
    num_records--;
    printf("last part removed.\n");
}

// function to print all parts
void print_records() {
    if (num_records == 0) {
        printf("no parts available.\n");
        return;
    }
    
    // loops through the records and prints them
    for (int i = 0; i < num_records; i++) {
        printf("part %d:\n", i + 1);
        printf("number: %d\n", database[i].part_number);
        printf("name: %s\n", database[i].part_name);
        printf("size: %.2f %s\n", database[i].part_size, database[i].part_size_metric);
        printf("cost: %.2f\n", database[i].part_cost);
        printf("--------------------\n");
    }
}

// function to show record count
void print_num_records() {
    printf("total parts: %d\n", num_records);
}

// function to show memory used by database
void print_database_size() {
    printf("memory used: %lu bytes\n", num_records * sizeof(Part));
}

// menu options
int main() {
    int choice;
    do {
        printf("\nMENU\n======\n");
        printf("1. Show all parts\n");
        printf("2. Show total parts\n");
        printf("3. Show memory usage\n");
        printf("4. Add part\n");
        printf("5. Remove last part\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        // actions to be performed based off user input
        switch (choice) {
            case 1: print_records(); break;
            case 2: print_num_records(); break;
            case 3: print_database_size(); break;
            case 4: add_record(); break;
            case 5: delete_record(); break;
            case 6: printf("See ya.\n"); break;
            default: printf("invalid choice, try again.\n");
        }
    } while (choice != 6);
    
    // frees allocated memory before program exit
    free(database);
    return 0;
}