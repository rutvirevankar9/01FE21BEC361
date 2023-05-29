#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int transposed[MAX_COLS][MAX_ROWS])
 {
    for (int i = 0; i < rows; i++)
        {
        for (int j = 0; j < cols; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
 {
    int matrix[MAX_ROWS][MAX_COLS];
    int transposed[MAX_COLS][MAX_ROWS];
    int rows, cols;

    FILE* file = fopen("matrix.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }


    rows = 0;
    cols = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL && rows < MAX_ROWS) {
        char* token = strtok(line, " ");
        cols = 0;
        while (token != NULL && cols < MAX_COLS) {
            matrix[rows][cols] = atoi(token);
            token = strtok(NULL, " ");
            cols++;
        }
        rows++;
    }

    fclose(file);

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols, transposed);

    printf("Transposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    FILE* outputFile = fopen("transposed_matrix.txt", "w");

    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        return 1;
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            fprintf(outputFile, "%d ", transposed[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    return 0;
}
