#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    // Sort the array using heap sort
    heapSort(arr, x);

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

