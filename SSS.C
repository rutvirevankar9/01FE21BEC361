#include <stdio.h>

#define MAX_SIZE 100

int main()
 {
    FILE *file;
    int numbers[MAX_SIZE] = {0};
    int frequency[MAX_SIZE] = {0};
    int count = 0;

    file = fopen("sss.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &numbers[count])==1 && count < MAX_SIZE)
    {
        frequency[numbers[count]]++;
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        if (frequency[numbers[i]] != 0)
        {
            printf("Number %d: %d\n", numbers[i], frequency[numbers[i]]);
            frequency[numbers[i]] = 0;
        }
    }

    fclose(file);

    return 0;
}

