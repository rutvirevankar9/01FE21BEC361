#include <stdio.h>

#define MAX_SIZE 100

void insertion_sort(int arr[], int n);
void print_array(int arr[], int n);

int main()
{
    int arr[MAX_SIZE];
    int n, i, square_sum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);

    for (i = 0; i < n; i += 2)
    {
        arr[i]=arr[i]*arr[i];
    }
    printf("square of even indices%d",arr[i]);

}

void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

