#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mix(int *card, int n);
void mix(int *card, int n)
{
    int j,i,temp;
    srand(time(NULL));
    for (i = n - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }
}

int main()
{
    int card[100],n,i;
    printf("enter the number of cards");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
        card[i] = i + 1;
    mix(card,n);
    printf("after mixing the cards\n");
    for (i = 0; i <n; i++)
        printf("%d ", card[i]);
    return 0;
}
