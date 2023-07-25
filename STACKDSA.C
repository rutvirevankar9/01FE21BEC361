#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node
{
    int a[size];
    int top;

};
void push(struct node *s,int data);
void pop(struct node *s,int data);
void peek(struct node *s);

void  push(struct node* s,int data)
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

        data=2*s->a[s->top];
        s->top--;
        printf("the doubled data is %d\n",data);
    }
}
int main()
{
    struct node *s;
    struct node p;
    s=&p;
    s->top=-1;
    int ch,data;

    while(1)
    {
        printf("enter 1 for push and 2 for pop\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d",&data);
                   push(s,data);
                   break;
            case 2:pop(s,data);
                   break;

        }
    }

}
