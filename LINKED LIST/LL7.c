//Find starting point of loop in linked list...
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* Detectnode(struct node* S)
{
    struct node* slow=S;
    struct node* fast=S;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return slow;
        }
    }
    return NULL;//Returning NULL means Cycle not present in List.
    
}
struct node* LoopStarting(struct node* S)
{
    struct node* meet=Detectnode(S);
    struct node* start=S;
    while(start!=meet)
    {
        start=start->next;
        meet=meet->next;
    }
    return start;
}
int main()
{
    
    struct node* a= NULL;
    struct node* b= NULL;
    struct node* c= NULL;
    struct node* d,*e,*f= NULL;

    a=(struct node*)malloc(sizeof(struct node)); 
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));
    d=(struct node*)malloc(sizeof(struct node));
    e=(struct node*)malloc(sizeof(struct node));
    f=(struct node*)malloc(sizeof(struct node));

     struct node* S = a;

    a->data=1;
    a->next=b;

    b->data=2;
    b->next=c;

    c->data=3;
    c->next=d;

    d->data=4;
    d->next=e;
    
    e->data=5;
    e->next=f;

    f->data=6;
    f->next=c;


    struct node*k=LoopStarting(S);
    printf("Stating point:%d",k->data);
    return 0;
}