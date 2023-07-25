#include<stdio.h>
#include<stdlib.h>
void frequency(int a[20],int n);
int frequency(int a[20],int n)
{
    int i,j;
    int count=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count=count+1;
            }
        }

    }


}
int main()
{
    int n,a[20],i,j;
    int count=0;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    frequency(a,n);

}
