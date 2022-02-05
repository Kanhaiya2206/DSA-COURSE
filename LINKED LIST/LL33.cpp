//Delete Nodes which have greater value in right..
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

class Solution
{
  public:
Node* Reverse_List(Node* head)
    {
    
        Node* current = head;
        Node *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    Node *compute(Node *head)
    {
        head=Reverse_List(head);
        Node* curr=head;
        int max=head->data;
        Node* prev=head;
        head=head->next;
        while(head)
        {
            if(head->data>=max)
            {
                max=head->data;
                prev=head;
                head=head->next;
            }
            else
            {
                prev->next=head->next;
                head=prev->next;
            }
            
        }
        head=Reverse_List(curr);
        return head;
    
    }
    
};
   




int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
