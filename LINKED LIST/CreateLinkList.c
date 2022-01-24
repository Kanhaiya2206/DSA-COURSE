//Creating a Linked List and Printing it....
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
int main()
{
    
    struct node* a= NULL;
    struct node* b= NULL;
    struct node* c= NULL;
    struct node* d= NULL;

    a=(struct node*)malloc(sizeof(struct node)); 
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));
    d=(struct node*)malloc(sizeof(struct node));

     struct node* S = a;

    a->data=10;
    a->next=b;

    b->data=20;
    b->next=c;

    c->data=30;
    c->next=d;

    d->data=40;
    d->next=NULL;

    while(S!=NULL)
    {
        printf(" %d ",S->data);
        S=S->next;
    }

    return 0;
}