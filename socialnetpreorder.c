#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    struct User* connections[100];
    int num_connections;
};

struct User* createUser(const char* name) {
    struct User* user = (struct User*)malloc(sizeof(struct User));
    strcpy(user->name, name);
    user->num_connections = 0;
    return user;
}

void addConnection(struct User* user, struct User* connection) {
    user->connections[user->num_connections] = connection;
    user->num_connections++;
}

void preorderTraversal(struct User* user, FILE* output_file) {
    if (user == NULL) {
        return;
    }
    fprintf(output_file, "%s\n", user->name);  // Write the current user node to the output file
    for (int i = 0; i < user->num_connections; i++) {
        preorderTraversal(user->connections[i], output_file);  // Recursively traverse the connections
    }
}

int main() {
    const char* filename = "social_network.txt";
    const char* startingUser = "Alice";
    const char* outputFilename = "output.txt";

    // Read social network connections from the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    struct User* users[100];
    int num_users = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';  // Remove the trailing newline character
        }

        if (num_users < 100) {
            users[num_users] = createUser(line);
            num_users++;
        }
    }
    fclose(file);

    // Build the social network tree
    for (int i = 0; i < num_users; i++) {
        struct User* currentUser = users[i];
        file = fopen(filename, "r");
        while (fgets(line, sizeof(line), file)) {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';  // Remove the trailing newline character
            }

            if (strcmp(line, currentUser->name) == 0) {
                while (fgets(line, sizeof(line), file)) {
                    if (line[strlen(line) - 1] == '\n') {
                        line[strlen(line) - 1] = '\0';  // Remove the trailing newline character
                    }

                    if (strcmp(line, "end") == 0) {
                        break;
                    }

                    for (int j = 0; j < num_users; j++) {
                        if (strcmp(users[j]->name, line) == 0) {
                            addConnection(currentUser, users[j]);
                            break;
                        }
                    }
                }
                break;
            }
        }
        fclose(file);
    }

    // Perform preorder traversal starting from the specified user and write the output to the output file
    file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", outputFilename);
        return 1;
    }

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i]->name, startingUser) == 0) {
            preorderTraversal(users[i], file);
            break;
        }
    }

    fclose(file);

    // Free allocated memory
    for (int i = 0; i < num_users; i++) {
        free(users[i]);
    }

    return 0;
}
