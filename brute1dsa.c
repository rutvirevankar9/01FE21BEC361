#include <stdio.h>
void calculate(int a[10], int size, int val);
void calculate(int a[10], int size, int val)
{
    int c = 0;
    int x;
    for(int i = 0; i < size; i++) {
        int p = a[i] * x + c;
        a[i] = p % 10;
        c = p / 10;
    }
    while(c)
{
        a[size] = c% 10;
        c /= 10;
        size++;
    }
}

void factorial(int n)
{
    int a[10];
    a[0] = 1;
    int size = 1;
    for(int i = 2; i <= n; i++)
    {
        calculate(a, size, i);
    }
    printf("Factorial of %d is: ", n);
    for(int i = size - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
}

int main()
{
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    factorial(n);

}
