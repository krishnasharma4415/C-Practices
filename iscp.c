#include<stdio.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

int isEmpty(struct node *top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
int isFull()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
        return 1;
    else 
        return 0;
}

int push(struct node *top, int data)
{
    if(isFull())
        printf("Stack Overflow");
    else
    {
        struct node *n = (struct node *)malloc(sizeof (struct node));
        n->data = data;
        n->next = top;
        top = n;
        return top->data;
    }
}
int pop(struct node *top)
{
    if(isEmpty())
        printf("Stack Underflow");
    else
    {
        struct node *n = top;
        int x = top->data;
        top = top->next;
        free(n);
        return x;
    }
}

void traverse(struct node *top)
{
    struct node *   ptr = top;
    while(ptr->next!=NULL)
    {
        printf("%d->"ptr->data);
        ptr = ptr->next;
    }
}

