//2nd Last Node in Linked List
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

struct node* second_last(struct node* S)
{
  if(S==NULL)
  {
      printf("Empty list");
  }
  if(S->next==NULL)
  {
      printf("list have one element");
  }
  while(S->next->next!=NULL)
  {
       S=S->next;
  }
  return S;
}

int main()
{
    // input keys
    int keys[] = {1,2,3,4,5};
    int n = 5;
 
    struct node* head=NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    struct node* p=second_last(head);
    
    printf("2nd last node from end is %d",p->data);
    

    return 0;
}    