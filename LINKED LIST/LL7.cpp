//Remove duplicates from UnSorted Linked List....
#include<bits/stdc++.h>
using namespace std;

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
    
         map<int,int> m;
         struct node* curr=head;
         m[curr->data]=1;
         struct node* prev=curr;
         curr=curr->next;
         while(curr!=NULL)
         {
             if(m[curr->data])
             {
                 prev->next=curr->next;
                 free(curr);
             }
             else
              {
                  m[curr->data]=1;
                  prev=curr;
              }
              curr=prev->next;
         }
         return head;
    
}
int main()
{
    // input keys
    int keys[] = { 2, 2, 3, 2, 5 };
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