
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 64

typedef struct {
    char piece[10];
    char position[3];
} Coin;

int main() {
    Coin coins[MAX_COINS];
    FILE *file = fopen("chessboard.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int numCoins = 0;
    char line[20];

    while (fgets(line, sizeof(line), file) != NULL && numCoins < MAX_COINS) {
        sscanf(line, "%s %s", coins[numCoins].piece, coins[numCoins].position);
        numCoins++;
    }

    fclose(file);


    for (int i = 0; i < numCoins; i++) {
        printf("Piece: %s, Position: %s\n", coins[i].piece, coins[i].position);
    }

    return 0;
}

