#include<stdio.h>
void recursion(int n);
void recursion(int n)
{
    int i;
    if(n>0)
    {


        {
            printf("%d",n);
        }
        recursion(n-1);
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
