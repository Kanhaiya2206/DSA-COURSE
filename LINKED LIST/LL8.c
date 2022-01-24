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

struct node* moveLastFirst(struct node* head)
{
    struct node* S1=head;
    struct node* p;
    while(S1->next!=NULL)
    {
        p=S1;
        S1=S1->next;
    }
    S1->next=head;
    head=S1;
    p->next=NULL;

    return head;
    
}
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = 5;
 
    struct node* head=NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    struct node* a=moveLastFirst(head);

    for(int i=0;i<n;i++)
    {
       printf(" %d -> ",a->data);
       a=a->next;
    }

    return 0;
}    