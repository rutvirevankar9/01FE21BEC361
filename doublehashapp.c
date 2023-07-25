#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct Device {
    char macAddress[18];
    char ipAddress[16];
};

// Function to initialize the hash table
void initializeTable(struct Device* table, int size) {
    for (int i = 0; i < size; i++) {
        table[i].macAddress[0] = '\0';
        table[i].ipAddress[0] = '\0';
    }
}

// Hash function 1 - DJB2 hash
unsigned long hashFunction1(const char* key, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % size;
}

// Hash function 2 - Simple addition-based hash
unsigned long hashFunction2(const char* key, int size) {
    unsigned long hash = 0;
    int c;

    while ((c = *key++)) {
        hash += c;
    }

    return hash % size;
}

// Double hash function to calculate the next probe position
unsigned long doubleHashFunction(unsigned long index, unsigned long stepSize, int size) {
    return (index + stepSize) % size;
}

// Function to insert a device into the hash table using double hashing
void insertDevice(struct Device* table, int size, const char* macAddress, const char* ipAddress) {
    unsigned long index = hashFunction1(macAddress, size);
    unsigned long stepSize = hashFunction2(macAddress, size);
    unsigned long originalIndex = index;

    while (table[index].macAddress[0] != '\0') {
        index = doubleHashFunction(originalIndex, stepSize, size);

        // Check if the entire hash table has been probed
        if (index == originalIndex) {
            printf("Table is full, cannot insert device with MAC Address %s\n", macAddress);
            return;
        }
    }

    strcpy(table[index].macAddress, macAddress);
    strcpy(table[index].ipAddress, ipAddress);
}

// Function to display all devices in the hash table
void displayDevices(struct Device* table, int size) {
    printf("Device Table:\n");
    printf("MAC Address\t\tIP Address\n");

    for (int i = 0; i < size; i++) {
        if (table[i].macAddress[0] != '\0') {
            printf("%s\t%s\n", table[i].macAddress, table[i].ipAddress);
        }
    }
}

int main() {
    const char* inputFilename = "devices.txt";

    // Open the input file
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", inputFilename);
        return 1;
    }

    struct Device deviceTable[TABLE_SIZE];
    initializeTable(deviceTable, TABLE_SIZE);

    char macAddress[18];
    char ipAddress[16];

    // Read device data from the input file and insert into the hash table
    while (fscanf(inputFile, "%s %s", macAddress, ipAddress) != EOF) {
        insertDevice(deviceTable, TABLE_SIZE, macAddress, ipAddress);
    }

    fclose(inputFile);

    // Display all devices in the hash table
    displayDevices(deviceTable, TABLE_SIZE);

    return 0;
}
