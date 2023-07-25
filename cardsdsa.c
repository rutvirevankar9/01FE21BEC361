#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *deck, int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main()
{
    int deck[52];
    for (int i = 0; i < 52; i++)
        deck[i] = i + 1;
    shuffle(deck, 52);
    printf("The shuffled deck is:\n");
    for (int i = 0; i < 52; i++)
        printf("%d ", deck[i]);
    return 0;
}

