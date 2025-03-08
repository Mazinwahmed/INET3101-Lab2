#include <stdio.h>
#include <stdlib.h>

// stores part info
typedef struct {
    int part_number;
    char part_name[50];
    float part_size;
    char part_size_metric[10];
    float part_cost;
} Part;

Part *database = NULL;
int num_records = 0;

// Function to add a new part
void add_record() {
    Part *new_db = malloc((num_records + 1) * sizeof(Part));
    if (new_db == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    for (int i = 0; i < num_records; i++) {
        new_db[i] = database[i];
    }
    
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
    
    free(database);
    database = new_db;
    num_records++;
    printf("part has been added.\n");
}

// Function to delete the last added part
void delete_record() {
    if (num_records == 0) {
        printf("no parts to delete.\n");
        return;
    }
    
    Part *new_db = malloc((num_records - 1) * sizeof(Part));
    if (new_db == NULL && num_records > 1) {
        printf("memory allocation failed.\n");
        return;
    }
    
    for (int i = 0; i < num_records - 1; i++) {
        new_db[i] = database[i];
    }
    
    free(database);
    database = new_db;
    num_records--;
    printf("last part removed.\n");
}

// Function to print all parts
void print_records() {
    if (num_records == 0) {
        printf("no parts available.\n");
        return;
    }
    
    for (int i = 0; i < num_records; i++) {
        printf("part %d:\n", i + 1);
        printf("number: %d\n", database[i].part_number);
        printf("name: %s\n", database[i].part_name);
        printf("size: %.2f %s\n", database[i].part_size, database[i].part_size_metric);
        printf("cost: %.2f\n", database[i].part_cost);
        printf("--------------------\n");
    }
}

// Function to show record count
void print_num_records() {
    printf("total parts: %d\n", num_records);
}

// Function to show memory size used
void print_database_size() {
    printf("memory used: %lu bytes\n", num_records * sizeof(Part));
}

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
    
    free(database);
    return 0;
}