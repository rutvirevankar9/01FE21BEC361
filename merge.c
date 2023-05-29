#include <stdio.h>

#define MAX_SIZE 1000

int main()
{
    FILE *input_file, *output_file;
    int i, j, temp, num_count = 0, x;
    int nums[MAX_SIZE];


    input_file = fopen("input.txt", "r");
    if (input_file == NULL)
    {
        printf("Failed to open input file.");
        return 1;
    }

    while (fscanf(input_file, "%d", &nums[num_count]) == 1)
    {
        num_count++;
    }


    fclose(input_file);


    printf("Enter how many numbers to sort: ");
    scanf("%d", &x);


    for (i = 0; i < x-1; i++)
        {
        for (j = 0; j < x-i-1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }


    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to open output file.");
        return 1;
    }


    for (i = 0; i < x; i++) {
        fprintf(output_file, "%d ", nums[i]);
    }

    fclose(output_file);

    return 0;
}

