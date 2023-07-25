#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    return node;
}

// Function to perform pre-order traversal of the binary search tree
void preOrder(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        fprintf(outputFile, "%d ", node->data);
        preOrder(node->left, outputFile);
        preOrder(node->right, outputFile);
    }
}

// Function to perform in-order traversal of the binary search tree
void inOrder(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        inOrder(node->left, outputFile);
        fprintf(outputFile, "%d ", node->data);
        inOrder(node->right, outputFile);
    }
}

// Function to perform post-order traversal of the binary search tree
void postOrder(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        postOrder(node->left, outputFile);
        postOrder(node->right, outputFile);
        fprintf(outputFile, "%d ", node->data);
    }
}

int main()
{
    FILE* inputFile = fopen("inputs.txt", "r");
    int n;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    // Set the seed for random number generation
    srand(time(0));


    for (int i = 0; i < n; i++)
    {
        fprintf(inputFile,"%d\n", rand());
    }

    return 0;
    // Open input and output files

    FILE* preOrderFile = fopen("preorder.txt", "w");
    FILE* inOrderFile = fopen("inorder.txt", "w");
    FILE* postOrderFile = fopen("postorder.txt", "w");

    // Check if files were opened successfully
    if (inputFile == NULL || preOrderFile == NULL || inOrderFile == NULL || postOrderFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    // Read numbers from input file and generate binary search tree
    struct Node* root = NULL;
    int num;
    while (fscanf(inputFile, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    // Perform pre-order traversal and measure time complexity
    clock_t preOrderStart = clock();
    preOrder(root, preOrderFile);
    clock_t preOrderEnd = clock();
    double preOrderTime = (double)(preOrderEnd - preOrderStart) / CLOCKS_PER_SEC;

    // Perform in-order traversal and measure time complexity
    clock_t inOrderStart = clock();
    inOrder(root, inOrderFile);
    clock_t inOrderEnd = clock();
    double inOrderTime = (double)(inOrderEnd - inOrderStart) / CLOCKS_PER_SEC;

    // Perform post-order traversal and measure time complexity
    clock_t postOrderStart = clock();
    postOrder(root, postOrderFile);
    clock_t postOrderEnd = clock();
    double postOrderTime = (double)(postOrderEnd - postOrderStart) / CLOCKS_PER_SEC;

    // Close all files
    fclose(inputFile);
    fclose(preOrderFile);
    fclose(inOrderFile);
    fclose(postOrderFile);

    // Display time complexities
    printf("Pre-order time complexity: %f seconds\n", preOrderTime);
    printf("In-order time complexity: %f seconds\n", inOrderTime);
    printf("Post-order time complexity: %f seconds\n", postOrderTime);

    return 0;
}

