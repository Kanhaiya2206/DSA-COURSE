//Segregate even & odd nodes in LL...

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
public:
    Node* divide(int N, Node *head)
    {
        // code here
        Node *es=NULL;
        Node *ee=NULL;
        Node *os=NULL;
        Node *oe=NULL;
        Node *curr=head;
        
        while(curr!=NULL)
        {
            if((curr->data)%2==0)
            {
                if(es==NULL)
                {
                    es=curr;
                    ee=curr;
                }
                else
                {
                    ee->next=curr;
                    ee=ee->next;
                }
            }
            else
            {
                if(os==NULL)
                {
                    os=curr;
                    oe=curr;
                }
                else
                {
                    oe->next=curr;
                    oe=oe->next;
                }
            }
            curr=curr->next;
        }
         if(oe!=NULL)
         oe->next=NULL;
         if(es==NULL)
         {
         es=os;
         }
         else
         {
         ee->next=os;
         }
    return es;     
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends