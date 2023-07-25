#include <stdio.h>
int c = 0;
void permutation(int a[10],int i,int N);
void permutation(int a[10],int i,int N)
{
    int j,k;
    if (i == N)
    {
        c++;
        printf("permutations are %d ", c);
        for (j = 0; j < N; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
        return;
    }
    for (int j = 1; j <= N; j++)
{
        int used = 0;
        for (k = 0; k < i; k++)
        {
            if (a[k] == j)
            {
                used = 1;

            }
        }
        if (!used)
        {
            a[i] = j;
            permutation(a,i + 1,N);
        }
    }
}

int main()
{
    int N,i,a[10];
    printf("enter n");
    scanf("%d",&N);
    permutation(a,i,N);
    return 0;
}
