#include <stdio.h>
int maxadd(int a[10], int n);
int maxadd(int a[10], int n)
{
    int i, j;
    int maxadd[n];
    int maximum=0;

    for (int i=0; i<n ; i++)
    {
        maxadd[i] = a[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if((a[i]>a[j]) && (maxadd[i]< (maxadd[j]+a[i]) ))
            {
                maxadd[i] = maxadd[j] + a[i];
            }
        }
    }

    for(int i = 0; i<n; i++)
    {

        if(maximum < maxadd[i])
        {
            maximum = maxadd[i];
        }
    }
 return maximum;
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
  x=maxadd(a,n);

  printf("maximum addition of increasing subsequence is  %d",x);
  return 0;
}
