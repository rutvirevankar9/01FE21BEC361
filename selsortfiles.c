#include <stdio.h>

void selection_sort(int arr[], int n);

int main()
{
    int x; // number of elements to be sorted
    int arr[1000]; // array to store the elements (maximum size of 1000)
    FILE *fp_in, *fp_out; // file pointers for input and output files
    int i;

    // Open the input file
    fp_in = fopen("input.txt", "r");
    if (fp_in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read the number of elements to be sorted
    fscanf(fp_in, "%d", &x);

    // Read in the numbers from the file
    for (i = 0; i < x; i++) {
        fscanf(fp_in, "%d", &arr[i]);
    }

    // Close the input file
    fclose(fp_in);

    // Sort the array using selection sort
    selection_sort(arr, x);

    // Open the output file
    fp_out = fopen("output.txt", "w");
    if (fp_out == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write the sorted numbers to the output file
    for (i = 0; i < x; i++) {
        fprintf(fp_out, "%d\n", arr[i]);
    }

    // Close the output file
    fclose(fp_out);

    return 0;
}

void selection_sort(int arr[], int n)
{
    int i, j, min_idx, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

