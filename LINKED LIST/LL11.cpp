// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}



//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    struct Node* S1=head1;
    int c1=0;int c=0;
    struct Node* S2=head2;
    int c2=0; int d=0; 
    
    if(S1 == NULL || S2 == NULL)
      return 0;
    while(S1!=NULL)
    {
        S1=S1->next;
        c1=c1+1;
    }
   
    while(S2!=NULL)
    {
        S2=S2->next;
        c2=c2+1;
    }
      
    if(c1>c2)
    {
        S1=head1;
        S2=head2;
        c=c1-c2;
    
       while(c!=0)
       {
          S1=S1->next;
          c=c-1;
       }
       
    }
    else
    {
        S1=head1;
        S2=head2;
        d=c2-c1;
        while(d!=0)
        {
            S2=S2->next;
            d=d-1;
        }
    
    }
    while(S1!=S2)
    {
        S1=S1->next;
        S2=S2->next;
    }
    
    return S1->data;
    
}

