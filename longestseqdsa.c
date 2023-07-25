#include <stdio.h>
#include <string.h>

int longseq(char *p, char *q)
{
    int m = strlen(p);
    int n = strlen(q);
    int c[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            }
            else if (p[i-1] == q[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    return c[m][n];
}
int max(int a, int b)
{
    if(a>b)
    {
       return (a > b);
    }

}


int main()
{
    char p[] = "bvbhubli";
    char q[] = "kletechhubli";
    int answer = longseq(p, q);
    printf("hence the result implies %d\n",answer);
    return 0;
}

