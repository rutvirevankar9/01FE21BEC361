#include <stdio.h>
int maxofarray(int a[10], int n);
int maxofarray(int a[10], int n)
{
int first = 0, last = n-1, mid;

 while(first<= last)

 {
        mid = first + (last - first) / 2;
        if(a[mid] < a[mid+1])
        {
            first = mid + 1;
        }
        else if(a[mid]>a[mid+1])
        {
            last = mid - 1;
        }
        else
        {
            return a[mid];
        }
    }

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
    int highest = maxofarray(a,n);
    printf("the highest element inarray is: %d\n", highest);

}
