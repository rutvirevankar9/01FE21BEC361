#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        fprintf(fp, "%d ", root->data);
        preorderTraversal(root->left, fp);
        preorderTraversal(root->right, fp);
    }
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        inorderTraversal(root->left, fp);
        fprintf(fp, "%d ", root->data);
        inorderTraversal(root->right, fp);
    }
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        postorderTraversal(root->left, fp);
        postorderTraversal(root->right, fp);
        fprintf(fp, "%d ", root->data);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open file!\n");
        return 1;
    }

    struct Node* root = NULL;
    int num;

    // Read numbers from the input file and create the binary tree
    while (fscanf(inputFile, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    // Perform traversals and write the results to the output file
    fprintf(outputFile, "Preorder traversal: ");
    preorderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Inorder traversal: ");
    inorderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Postorder traversal: ");
    postorderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    printf("Traversals have been written to the output file successfully!\n");

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
