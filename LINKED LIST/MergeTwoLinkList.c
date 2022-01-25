//Move Last node to First in Linked List....
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
void push(struct node** S, int data)
{
    // create a new linked list node from the heap
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
 
    newNode->data = data;
    newNode->next = *S;
    *S= newNode;
}

struct node* merge(struct node* head1,struct node* head2)
{
    struct node* S1=head1;
    struct node* S2=head2;
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=-1;a->next=NULL;
    struct node* S3=a;

    while(S1!=NULL && S2!=NULL)
    {
       if(S1->data<S2->data)
       {
           S3->next=S1;
           S1=S1->next;
       }
       else
       {
           S3->next=S2;
           S2=S2->next;
       }
       S3=S3->next;
    }
    while(S1!=NULL)
    {
        S3->next=S1;
        S1=S1->next;
        S3=S3->next;
    }
     while(S2!=NULL)
    {
        S3->next=S2;
        S2=S2->next;
        S3=S3->next;
    }
    return a->next;
}

int main()
{
    // input keys
    int keys1[] = { 10, 20, 30, 40, 50 };
    int n1 = 5;
 
    struct node* head1=NULL;
    for (int i = n1- 1; i >= 0; i--) {
        push(&head1, keys1[i]);
    }
    int keys2[] = { 11, 21, 31, 41, 51 };
    int n2 = 5;

    struct node* head2=NULL;
    for (int i = n2- 1; i >= 0; i--) {
        push(&head2, keys2[i]);
    }   

    struct node* x=merge(head1,head2);

    for(int i=0;i<(n1+n2);i++)
    {
       printf(" %d -> ",x->data);
       x=x->next;
    }

    return 0;
}    