#include <stdio.h>
#include <stdlib.h>


typedef struct ssort
{
    int data;
    struct Node *next;
}ssort;


ssort* formnew(int data)
{
    ssort *newnode = (ssort*) malloc(sizeof(ssort));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


void in_end(ssort **head, int data)
{
    ssort *newnode = formnew(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        ssort *cur= *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newnode;
    }
}


void selectionsort(ssort **head)
{
    ssort *cur = *head;
    while (cur != NULL) {
        ssort *min = cur;
        ssort *temp = cur->next;
        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }
        int temp_data = cur->data;
        cur->data = min->data;
        min->data = temp_data;
        cur = cur->next;
    }
}


void display(ssort *head)
{
    ssort *cur = head;
    while (cur != NULL)
        {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


int main() {
    ssort *head = NULL;
    int x, n;
    printf("enter the number of elements ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter your element %d ", i+1);
        scanf("%d", &x);
        in_end(&head, x);
    }
    selectionsort(&head);
    printf("after sorting ");
    display(head);
    return 0;
}
