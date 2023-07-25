#include<stdio.h>
void array(int a[10],int n);
void array(int a[10],int n)
{
    int i;
    while(i<n)
    {

            for(i=0;i<n;i++)  // n
            {
                printf("%d",a[i]); // n*n
            }

    }
    array(a,n-1);//n-1
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

