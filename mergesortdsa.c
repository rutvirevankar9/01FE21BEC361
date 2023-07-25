#include <stdio.h>
#include <stdlib.h>

void merge(int a[10], int front[], int s1, int rear[], int s2)
{
    int i = 0, j = 0, k = 0;

    while (i < s1 && j < s2)
    {
        if (front[i] <= rear[j])
        {
            a[k++] = front[i++];
        } else
        {
            a[k++] = rear[j++];
        }
    }

    while (i < s1) {
        a[k++] = front[i++];
    }

    while (j < s2) {
        a[k++] = rear[j++];
    }
}

void mergesort(int a[10], int n) {
    if (n < 2) {
        return;
    }

    int mid = n / 2;
    int front[mid];
    int rear[n - mid];

    for (int i = 0; i < mid; i++) {
        front[i] = a[i];
    }

    for (int i = mid; i < n; i++)
    {
        rear[i - mid] = a[i];
    }

    mergesort(front, mid);
    mergesort(rear, n - mid);
    merge(a,front, mid, rear, n - mid);
}

int main()
{
    int n, i,a[10];
    printf("Enter the number of elements ");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a,n);

    printf("after sorting ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
