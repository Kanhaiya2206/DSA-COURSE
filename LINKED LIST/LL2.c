//REVERSE a linked list in given K group...
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

struct node* Reverse_List(struct node* S,int k)
{
  struct node *p,*q;
  struct node *S1=S;
  while(S1!=NULL && k--)
  {
      p=q;
      q=S1;
      S1=S1->next;
      q->next=p;

  }
  if(S1!=NULL)
    S->next=Reverse_List(S1,k);
  return(q);
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
    int k=3;
    struct node* a=Reverse_List(head,k);

    printf("Reversed Linked List");
    for(int i=0;i<n;i++)
    {
       printf(" %d -> ",a->data);
       a=a->next;
    }
    
    

    return 0;
}    