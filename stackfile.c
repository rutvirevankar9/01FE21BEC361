#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s)
{
    s->top = -1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}

int isFull(Stack* s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int data)
{
    if (isFull(s)) {
        printf("Error: Stack is full.\n");
        exit(1);
    }
    s->arr[++s->top] = data;
}

int pop(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    return s->arr[s->top--];
}

int main()
{
    // Open files
    FILE *inputFile = fopen("inputt.txt", "r");
    FILE *stackFile = fopen("stack.txt", "w");
    FILE *pushFile = fopen("push.txt", "w");
    FILE *popFile = fopen("pop.txt", "w");
    FILE *outputFile = fopen("outputt.txt", "w");

    // Generate random numbers and store them in stack file
    int n;
    fscanf(inputFile, "%d", &n);
    srand(time(NULL));
    Stack s;
    init(&s);
    for (int i = 0; i < n; i++) {
        int num = rand();
        fprintf(stackFile, "%d\n", num);
        push(&s, num);
    }

    // Read user input and perform push/pop operations
    char operation[5];
    int num;
    while (scanf("%s", operation) != EOF)
    {
        if (operation[0] == 'p' && operation[1] == 'u')
        {
            scanf("%d", &num);
            fprintf(pushFile, "%d\n", num);
            push(&s, num);
        } else if (operation[0] == 'p' && operation[1] == 'o')
        {
            num = pop(&s);
            fprintf(popFile, "%d\n", num);
        } else {
            printf("Error: Invalid operation.\n");
            exit(1);
        }
    }

    // Write overall output to output file
    fprintf(outputFile, "Stack:\n");
    for (int i = s.top; i >= 0; i--)
    {
        fprintf(outputFile, "%d\n", s.arr[i]);
    }
    fprintf(outputFile, "Pushed:\n");
    rewind(pushFile);
    while (fscanf(pushFile, "%d", &num) != EOF)
    {
        fprintf(outputFile, "%d\n", num);
    }
    fprintf(outputFile, "Popped:\n");
    rewind(popFile);
    while (fscanf(popFile, "%d", &num) != EOF)
    {
        fprintf(outputFile, "%d\n", num);
    }

    // Close files
    fclose(inputFile);
    fclose(stackFile);
    fclose(pushFile);
    fclose(popFile);
    fclose(outputFile);

    return 0;
}

