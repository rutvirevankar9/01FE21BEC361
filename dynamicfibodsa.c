#include <stdio.h>
int fibonnaci(int n, int a[10]);
int fibonnacci(int n, int a[10])
{
  if (n <= 1)
  {
    a[n] = n;
  }
  else
  {
    a[n] = fibonnacci(n-1, a) + fibonnacci(n-2, a);
  }
  if (a[n] != -1)
  {
    return a[n];
  }
}

int main()
{
  int i,n,a[10];
  printf("enter the number");
  scanf("%d",&n);
  for (int i = 0; i <= n; i++)
  {
    a[i] = -1;
  }
  fibonnacci(n,a);
  printf("the fibonnacci of the number given is %d",a[n]);
  return 0;
}

