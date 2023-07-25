#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    FILE *input, *output;
    int x, i;

    // Open input file
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Read x from input file
    fscanf(input, "%d", &x);

    // Create array of x numbers
    int arr[x];
    for (i = 0; i < x; i++) {
        fscanf(input, "%d", &arr[i]);
    }

    // Close input file
    fclose(input);

    // Sort the array using merge sort
    mergeSort(arr, 0, x - 1);

    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Write sorted array to output file
    for (i = 0; i < x; i++) {
        fprintf(output, "%d ", arr[i]);
    }

    // Close output file
    fclose(output);

    return 0;
}

