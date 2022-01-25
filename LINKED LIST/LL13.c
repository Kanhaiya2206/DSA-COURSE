//MERGE SORT for Linked List....
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

struct node *middlenode(struct node *head){
        
        struct node *prevv = NULL, *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            prevv = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prevv->next = NULL;
        
        return slow;
    }

    //Code not giving any o/p when i run the below middle node func.
/*struct node* middlenode(struct node* head) 
{
    struct node* S=head;
    int c=0;
    while(S!=NULL)
    {
        S=S->next;
        c=c+1;
    }
    c=floor((c/2)+1);
    while(c!=1)
    {
        head=head->next;
        c=c-1;
    }
    return head;
}*/

struct node* mergeSort(struct node* head)
{
    struct node* S=head;
    if(S->next==NULL) return S;
    
       struct node* m=middlenode(S);
       struct node* left=mergeSort(S);
       struct node* right=mergeSort(m);
       return merge(left,right);
}

int main()
{
    // input keys
    int keys[] = { 10, 20, 80, 40, 60, 30, 5, 65, 9 };
    int n = 9;
 
    struct node* head=NULL;
    for (int i = n- 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
    struct node* x=mergeSort(head);

    for(int i=0;i<n;i++)
    {
       printf(" %d -> ",x->data);
       x=x->next;
    }

    return 0;
}    