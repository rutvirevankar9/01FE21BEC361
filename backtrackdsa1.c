#include <stdio.h>

#define N 4
int chess[N][N];
int enter(int r, int c);
int enter(int r, int c)
{
    int i, j,n;

    for (i = 0; i < c; i++)
    {
        if (chess[r][i])
        {
            return 0;
        }
    }


    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j])
        {
            return 0;
        }
    }
    for (i = r, j = c; j >= 0 && i < n; i++, j--)
    {
        if (chess[i][j])
        {
            return 0;
        }
    }


    for (i = r, j = c; j >= 0 && i < n; i++, j--)
    {
        if (chess[i][j])
        {
            return 0;
        }
    }

    return 1;
}

int nqueens(int c)
{
    if (c >= n)
    {
        return 1;
    }

    int r;
    for (r = 0; r< n; r++)
        {
        if (enter(r, c))
        {
            chess[r][c] = 1;


            if (nqueens(c + 1))
            {
                return 1;
            }

            chess[r][c] = 0;
        }
    }

    return 0;
}


void display()
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            chess[i][j] = 0;
        }
    }


    if (nqueens(0))
    {
        printf("result =>\n");
        display();
    } else
    {
        printf("not possible to arrange \n");
    }

    return 0;
}







