//kth node from last in Linked List
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void push(struct node** S, int data)
{
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
 
    newNode->data = data;
    newNode->next = *S;
    *S= newNode;
}

struct node* kth_last(struct node* S,int k)
{
  struct node* S1=S;
  while(k!=1)
  {
      S1=S1->next;
      k=k-1;
  }
  while(S1->next!=NULL)
  {
      S=S->next;
      S1=S1->next;
  }
  return(S);
}

int main()
{
    
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = 5;
 
    struct node* head=NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
    int k=4;
    struct node* p=kth_last(head,k);
    
    printf("kth last node from end is %d",p->data);
    

    return 0;
}    