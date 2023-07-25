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
    FILE *fp;
    s=&p;
    s->top=-1;
    int ch,data;
    fp=fopen("stackdsa","w");
    scanf("%d",&data);
    push(s,data);
    fprintf(fp,"%d",data);
    fclose(fp);
    fp=fopen("stackdsa","r");
    pop(s,data);
    fclose(fp);

}


