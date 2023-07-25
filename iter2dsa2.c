#include<stdio.h>
int array(int a[10],int n);
int  array(int a[10],int n)
{
    int i=0;
    while(i<n)    // n
    {

       a[i]=a[i]*a[i];  //1
       printf("%d\n",a[i]);//1
       i++;
    }



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

//T(n)=n+1+n+.....
//=>o(n) is the time complexity

