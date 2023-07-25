#include<stdio.h>
int gmuloftwo(int a[10],int mid);
int gmuloftwo(int a[10],int mid)
{
    int n,num;
    int first=0;
    int last=n-1;
    while(first<=last)
    {
        mid=(last+first)/2;
        if(a[mid]==num)
        {
            return mid;
        }
        else if(a[mid]<num)
        {

          return gmuloftwo(a,mid+1);

        }
        else
        {
            last=gmuloftwo(a,mid-1);
        }
    }
}
int main()
{
    int first,last,mid,n,a[10],num,i;
    printf("enter the number of array elements");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the number");

    scanf("%d",&num);
    int result= gmuloftwo(a,mid);
    printf("element found at %d",result);

}


