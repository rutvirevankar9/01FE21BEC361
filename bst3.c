#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    return node;
}

void preOrder(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        fprintf(outputFile, "%d ", node->data);
        preOrder(node->left, outputFile);
        preOrder(node->right, outputFile);
         fprintf(preOrderFile, "%d ", node->data);
    }
}

void inOrder(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        inOrder(node->left, outputFile);
        fprintf(outputFile, "%d ", node->data);
        inOrder(node->right, outputFile);
         fprintf(inOrderFile, "%d ", node->data);
    }
}

void postOrder(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        postOrder(node->left, outputFile);
        postOrder(node->right, outputFile);
        fprintf(postOrderFile, "%d ", node->data);
    }
}

int main()
{
    FILE* inputFile = fopen("input.txt", "r");
    FILE* preOrderFile = fopen("preorder.txt", "w");
    FILE* inOrderFile = fopen("inorder.txt", "w");
    FILE* postOrderFile = fopen("postorder.txt", "w");

    if (inputFile == NULL || preOrderFile == NULL || inOrderFile == NULL || postOrderFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    int num;
    struct Node* root = NULL;

    // Set the seed for random number generation
    srand(time(0));

    while (fscanf(inputFile, "%d", &num) != EOF) {
        // Generate a random number between 0 and 99
        int randomNum = rand() % 100;
        root = insertNode(root, randomNum);
        fprintf(inputFile,"%d",randomNum);
    }

    clock_t preOrderStart = clock();
    preOrder(root, preOrderFile);
    clock_t preOrderEnd = clock();
    double preOrderTime = (double)(preOrderEnd - preOrderStart) / CLOCKS_PER_SEC;

    clock_t inOrderStart = clock();
    inOrder(root, inOrderFile);
    clock_t inOrderEnd = clock();
    double inOrderTime = (double)(inOrderEnd - inOrderStart) / CLOCKS_PER_SEC;

    clock_t postOrderStart = clock();
    postOrder(root, postOrderFile);
    clock_t postOrderEnd = clock();
    double postOrderTime = (double)(postOrderEnd - postOrderStart) / CLOCKS_PER_SEC;

    fclose(inputFile);
    fclose(preOrderFile);
    fclose(inOrderFile);
    fclose(postOrderFile);

    printf("Pre-order time complexity: %f seconds\n", preOrderTime);
    printf("In-order time complexity: %f seconds\n", inOrderTime);
    printf("Post-order time complexity: %f seconds\n", postOrderTime);

    return 0;
}

