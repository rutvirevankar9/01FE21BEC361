#include <stdio.h>

#define MAX_SIZE 100

int isSymmetric(int matrix[][MAX_SIZE], int size)
{
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i])
                {
                return 0;
        }
    }

    return 1;
}

int main() {
    int size, i, j;

    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    int matrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }


    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);


    file = fopen("matrix.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int readMatrix[MAX_SIZE][MAX_SIZE];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fscanf(file, "%d", &readMatrix[i][j]);
        }
    }

    fclose(file);


    int isSym = isSymmetric(readMatrix, size);
    if (isSym) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}

