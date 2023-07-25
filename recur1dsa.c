#include<stdio.h>
void array(int a[10],int n);
void array(int a[10],int n)
{
    int i=0;
    for(i=0;i<n;i++) //n+1
    {
        i=i*2;     //logn
        printf("%d",a[i]);//1
    }
    array(a,n-1);// n-1

}

int main()
{
    int i,n,a[10];
    printf("enter the value of n");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)  //                  ------>n+1
    {
        scanf("%d",&a[i]);//              ------>n
    }


     array(a,n);//                     ------>n

}
