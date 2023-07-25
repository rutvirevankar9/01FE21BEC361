#include<stdio.h>
int calculate(int a[10], int n,  int x)
int calculate(int a[10], int n,  int x)
{
    int i, c= 0;

    for(i = 0; i < n; i++)
    {

        while(x>= a[i])
        {

            x -= a[i];
            a[c] = a[i];
            c++;
        }

    }

    return c;
}

int main()
{
    int i,n,a[10],b[10],x,number;
    printf("enter size");
    scanf("%d",&n);
    printf("enter the values");

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }
        printf("enter the value");
        scanf("%d",&x);



     number = calculate(a,n,x);

    printf("required coins are = %d\n",number);

    printf("anwer is ");
    for(i = 0; i < number; i++)
        printf("%d ", b[i]);

    return 0;
}
