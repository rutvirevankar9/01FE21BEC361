#include <stdio.h>
int calculate(int a[], int n);
int calculate(int a[], int n)
{
    int max = 0,sum;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
         {
            sum += a[j];
            if(sum  > max) {
                max = sum;
            }
        }
    }
    return sum;
}

int main()
{
  int i,n,a[10],x;
  printf("enter the number");
  scanf("%d",&n);
  for (int i = 0; i<n; i++)
  {
      scanf("%d",&a[i]);
  }
    int max= calculate(a, n);
    printf("Maximum subarray sum is %d", max);
    return 0;
}
