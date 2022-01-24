//Remove duplicates from Sorted Linked List....
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

struct node* removeduplicate(struct node* head)
{
    struct node* S1=head;
    while(S1!=NULL && S1->next!=NULL)
    {
        if(S1->data==S1->next->data)
        {
            S1->next=S1->next->next;
        }
        else
          S1=S1->next;
    }
    return head;
    
}
int main()
{
    // input keys
    int keys[] = { 2, 2, 2, 2, 2 };
    int n = 5;
 
    struct node* head=NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    struct node* p=removeduplicate(head);

    for(int i=0;i<n;i++)
    {
       printf(" %d -> ",p->data);
       p=p->next;
    }

    return 0;
}    