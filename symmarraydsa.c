#include<stdio.h>
#include<stdlib.h>
int array(int a[10][10],int r,int c);
int array(int a[10][10],int r,int c)
{
    int i,j,count=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                count=1;
            }

        }
    }
}
int main()
{
    int a[10][10],i,j,r,c,n;
    int count;
    printf("enter the row size");
    scanf("%d",&r);
    printf("enter the column size");
    scanf("%d",&c);
    if(r!=c)
    {
        printf("symmetry cannot be determined");
    }
    printf("enter array elements\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }


    array(a,r,c);
    if(count==0)
    {
        printf("symmetric matrix");

    }

    else
    {
        printf("asymmetric matrix");
    }

}
