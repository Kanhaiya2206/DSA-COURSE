//REVERSE a linked list......
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

struct node* Reverse_List(struct node* S)
{
  struct node *p,*q;
  while(S!=NULL)
  {
      p=q;
      q=S;
      S=S->next;
      q->next=p;

  }
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
    
    struct node* a=Reverse_List(head);

    printf("Reversed Linked List");
    for(int i=0;i<n;i++)
    {
       printf(" %d -> ",a->data);
       a=a->next;
    }
    
    

    return 0;
}    