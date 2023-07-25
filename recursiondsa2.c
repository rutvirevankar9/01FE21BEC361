#include<stdio.h>
void recursion(int n);
void recursion(int n)
{
    int i;
    if(n>0)
    {
        for(i=1;i<n;i=i*2)

        {
            printf("%d",n);
        }
        recursion(n-1);
    }
}
int main()
{
    int n;
    printf("enter the value of n");
    scanf("%d",&n);
    recursion(n);
}

