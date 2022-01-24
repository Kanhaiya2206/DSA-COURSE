//Middle of Linked List....
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

struct node* middlenode(struct node* head)
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
}
int main()
{
    // input keys
    int keys[] = { 1, 2, 0, 4, 5};
    int n = 5;
 
    struct node* head=NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    struct node* a=middlenode(head);
    cout<<"Middle Point "<<a->data;

    return 0;
}    