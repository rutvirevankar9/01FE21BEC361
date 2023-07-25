#include <stdio.h>

#define N 6
int chess[N][N];
void display();


int enter(int r, int c)
{
    int i, j;


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


    for (i = r, j = c; j >= 0 && i < N; i++, j--)
    {
        if (chess[i][j])
         {
            return 0;
        }
    }

    return 1;
}


int nqueens(int c)
{    int r;
    if (c>= N)
    {
        return 1;
    }


    for (r = 0; r < N; r++)
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
    for (i = 0; i < N; i++)
        {
        for (j = 0; j < N; j++)
        {
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int i, j;
    for (i = 0; i < N; i++)
     {
        for (j = 0; j < N; j++)
        {
            chess[i][j] = 0;
        }
    }


    if (nqueens(0))
    {
        printf("hence the placing \n");
        display();
    } else
    {
        printf("cannot place\n");
    }

    return 0;
}


