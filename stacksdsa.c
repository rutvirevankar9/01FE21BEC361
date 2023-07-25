#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 100
struct node
{
    int a[size];
    int top;
};
void push(struct node *s,int data);
void pop(struct node *s,int data);
void push(struct node * s,int data)
{
    if(s->top==size-1)
    {
        printf("overflow");
    }
    else
    {

        s->top++;
        s->a[s->top]=data;



    }

}
void pop(struct node *s,int data)
{

    if(s->top==-1)
    {
        printf("underflow");

    }
    else
    {

        data=s->a[s->top];
        s->top--;
        printf("%d\n",data);
    }
}
int main()

{

    int randm[100];

    FILE *ipfile = fopen("input.txt", "r");
    FILE *stackfile = fopen("stack.txt", "w");
    FILE *pushfile = fopen("push.txt", "w");
    FILE *popfile = fopen("pop.txt", "w");
    FILE *opfile = fopen("output.txt", "w");
    int n,i,data;
    fscanf(ipfile, "%d", &n);
    srand(time(NULL));
    struct node *s;
    s->top=-1;
    for (i= 0; i < n; i++)
    {
        int randm[i] = rand()%100;

        fprintf(stackfile, "%d\n",randm[i]);
        push(&s, randm[i]);
    }
    int ch;
    int num;
    printf("enter the operation to be performed");
    scanf("%s",&ch);
    while(1)
    {

        printf("enter 1 for push and 2 for pop\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d",&randm[i]);
                   fprintf(pushfile, "%d\n",randm[i]);
                   push(s,data);
                   break;

            case 2:fprintf(popfile, "%d\n",randm[i]);
                   pop(s,data);
                   break;

        }

    }
    fprintf(opfile, "stack:\n");
    for (int i = s->top; i >= 0; i--)
    {
        fprintf(opfile, "%d\n", s->a[i]);
    }
    fclose(ipfile);
    fclose(stackfile);
    fclose(pushfile);
    fclose(popfile);
    fclose(opfile);

    return 0;

}
