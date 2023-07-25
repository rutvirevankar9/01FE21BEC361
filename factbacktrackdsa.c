#include <stdio.h>
#include <string.h>
int palindrome(char *word, int beg, int end);
void calculate(int n, char *word, int cur, char *p, int *used, int *present);
int palindrome(char *word, int beg, int end)
{
    if (beg>=end)
    {
        return 1;
    } else {
        return (word[beg] == word[end]) && palindrome(word, beg+1, end-1);
    }
}

void calculate(int n, char *word, int cur, char *p, int *used, int *present)
{


    if (cur == n) {
        if (palindrome(p, 0, n-1))
        {
            printf("%s\n", p);
            *present = 1;
        }
    } else
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (used[i])
                {
                continue;
            }
            p[cur] = word[i];
            used[i] = 1;
            calculate(n, word, cur+1, p, used,present);
            used[i] = 0;
        }
    }
}

int main()
{
    int i;
    char word[] = "bvb";
    int n = strlen((word));
    char p[n+1];
    p[n] = '\0';
    int used[n], present = 0;
    for (i = 0; i < n; i++)
    {


        used[i] = 0;
    }
    calculate(n,word, 0, p, used, &present);

}
