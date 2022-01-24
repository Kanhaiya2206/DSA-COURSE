//Detect loop in linked list...
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
};


bool Detectnode(struct node* S)
{
    struct node* slow=S;
    struct node* fast=S;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
        return true;
        }
        
    
    }
    return false;//Returning false means Cycle not present in List.
    
}
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
    d->next=b;

   bool p= Detectnode(S);
   printf("%s",p ? "true" : "false"); /*This is how we print boolean in C,if we 
                                        use %d,p it will print 1 for true*/

    return 0;
}