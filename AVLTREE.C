#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

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
    newNode->height = 1;
    return newNode;
}

// Function to right rotate a subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate a subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into the AVL tree
struct Node* insertNode(struct Node* root, int data) {
    // Perform the normal BST insertion
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else // Duplicate keys are not allowed in AVL tree
        return root;

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and perform rotations if necessary
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the unchanged root
    return root;
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        fprintf(fp, "%d ", root->data);
        preorderTraversal(root->left, fp);
        preorderTraversal(root->right, fp);
    }
}

// Function to perform inorder traversal of the AVL tree
void inorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        inorderTraversal(root->left, fp);
        fprintf(fp, "%d ", root->data);
        inorderTraversal(root->right, fp);
    }
}

// Function to perform postorder traversal of the AVL tree
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

    srand(time(0)); // Seed the random number generator with current time

    int num;
    int numCount = 10; // Number of random numbers to generate

    // Generate random numbers and store them in the input file
    for (int i = 0; i < numCount; i++) {
        num = rand() % 100; // Generate a random number between 0 and 99
        fprintf(inputFile, "%d\n", num);
    }

    // Move the file pointer to the beginning of the file
    rewind(inputFile);

    struct Node* root = NULL;

    // Read numbers from the input file and insert them into the AVL tree
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
