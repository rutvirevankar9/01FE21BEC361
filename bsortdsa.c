#include<stdio.h>
#include<stdlib.h>
struct bsort
{
  int data;
  struct node*next;

};
struct node *head;
struct bsort *insert_at_beg(struct bsort *);
struct bsort *calculate (struct bsort *);
void display(struct bsort *);
struct bsort *temp,temp1,newnode;
int main()
{
    head=NULL;
    int ch;
    while(1)
    {
        printf("insert at begining");
        printf("calculate");
        printf("enter your choice");
        scanf("%d",&ch);
     switch(ch)
     {
      case 1:newnode=(struct bsort*)malloc(sizeof(struct bsort));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
     case 2:calculate(head);
            break;
     case 3:display(head);
            break;
    default:printf("invalid choice");
    }

}
struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
}
void display(struct node *head)
{
   if(head==NULL)
   {
     printf("the linkded list is empty\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("%d->",temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}
void calculate(struct node *head,int data,int n)
{
    int i,j,tempr;
    printf("enter the how many numbers");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                tempr=a[i];
                a[i]=a[j];
                a[j]=tempr;
            }
        }
    }

}
