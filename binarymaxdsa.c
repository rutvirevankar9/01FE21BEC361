#include <stdio.h>
int maxofarray(int a[10], int n);
int maxofarray(int a[10], int n)
{
    int first = 0, last = n-1, mid;
    while(first<= last) {
        mid = first + (last - first) / 2;

        if(mid == n-1 || a[mid] > a[mid+1])
        {
            return a[mid];
        }
        else if(a[mid] < a[mid+1])
        {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, i,a[10];
    printf("Enter the number of elements ");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max = maxofarray(a,n);
    printf("The maximum element in the array is: %d\n", max);

}

