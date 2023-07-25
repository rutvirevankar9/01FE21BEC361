#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define MAX_PROBE 10

struct Resource {
    int id;
    char name[20];
};

// Function to initialize the hash table
void initializeTable(struct Resource* table, int size) {
    for (int i = 0; i < size; i++) {
        table[i].id = -1;
        table[i].name[0] = '\0';
    }
}

// Hash function to calculate the hash value for a given key
int hashFunction(int key, int size) {
    return key % size;
}

// Function to insert a resource into the hash table using quadratic probing
void insertResource(struct Resource* table, int size, int id, const char* name) {
    int index = hashFunction(id, size);
    int probe = 1;

    // Quadratic probing to find the next available slot
    while (table[index].id != -1) {
        index = (index + probe * probe) % size;
        probe++;

        // If the number of probes exceeds the maximum allowed, output an error message and return
        if (probe > MAX_PROBE) {
            printf("Table is full, cannot insert resource with ID %d\n", id);
            return;
        }
    }

    // Insert the resource at the available slot
    table[index].id = id;
    strcpy(table[index].name, name);
}

// Function to find a resource in the hash table using quadratic probing
int findResource(struct Resource* table, int size, int id) {
    int index = hashFunction(id, size);
    int probe = 1;

    // Quadratic probing to search for the resource
    while (table[index].id != -1) {
        if (table[index].id == id) {
            return index;
        }

        index = (index + probe * probe) % size;
        probe++;

        // If the number of probes exceeds the maximum allowed, break out of the loop
        if (probe > MAX_PROBE) {
            break;
        }
    }

    // Resource not found
    return -1;
}

// Function to display all resources in the hash table
void displayResources(struct Resource* table, int size) {
    printf("Resource Table:\n");
    printf("ID\tName\n");

    for (int i = 0; i < size; i++) {
        if (table[i].id != -1) {
            printf("%d\t%s\n", table[i].id, table[i].name);
        }
    }
}

int main() {
    const char* inputFilename = "resources.txt";

    // Open the input file
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", inputFilename);
        return 1;
    }

    struct Resource resourceTable[TABLE_SIZE];
    initializeTable(resourceTable, TABLE_SIZE);

    int id;
    char name[20];

    // Read resource data from the input file and insert into the hash table
    while (fscanf(inputFile, "%d %s", &id, name) != EOF) {
        insertResource(resourceTable, TABLE_SIZE, id, name);
    }

    fclose(inputFile);

    // Display all resources in the hash table
    displayResources(resourceTable, TABLE_SIZE);

    // Example usage: Find resource by ID
    int searchId;
    printf("Enter the ID of the resource to search: ");
    scanf("%d", &searchId);

    // Search for the resource in the hash table
    int index = findResource(resourceTable, TABLE_SIZE, searchId);
    if (index != -1) {
        printf("Resource found at index %d\n", index);
        printf("ID: %d, Name: %s\n", resourceTable[index].id, resourceTable[index].name);
    } else {
        printf("Resource not found.\n");
    }

    return 0;
}
