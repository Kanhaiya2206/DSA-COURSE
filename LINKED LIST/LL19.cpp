
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

Node *pre=NULL;

/* Function to delete a given node from the list */
//void deleteNode(struct Node *head, int key);
void deleteNode(Node **head,int data);
void reverse(Node **head);

/* Function to reverse the linked list */
//static void reverse(struct Node** head_ref);

/* Function to insert a node at the beginning of
a Circular linked list */

void push(struct Node **head_ref, int data)
{
	// Create a new node and make head as next
	// of it.

        struct Node *curr = new Node(data);

        curr->next=curr;
    
    	if(*head_ref==NULL)
        {
            *head_ref=curr;
            curr->next=*head_ref;
            pre=*head_ref;
    
        }
        else
        {
            curr->next=*head_ref;
            pre->next=curr;
            pre=pre->next;
    
    
        }
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
    else
    cout<<"empty"<<endl;

	printf("\n");
}
/* Driver program to test above functions */
int main()
{

	/* Initialize lists as empty */
	int t,a,delnode;
	cin>>t;
	while(t--)
	{
        pre=NULL;
	   Node *head=NULL;
      
        int n;
	    cin>>n;
	    while(n--)
	    {
	        cin>>a;
	        push(&head,a);
	    }    
	/* Created linked list will be 2->5->7->8->10 */
	cin>>delnode;

	deleteNode(&head, delnode);
	
	reverse(&head);

	printList(head);
}
	return 0;
}

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

// Your code goes here
if (*head == NULL)
        return;
         
    // If the list contains only a single node
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
     
    Node *last=*head,*d;
     
    // If head is to be deleted
    if((*head)->data==key)
    {
         
        // Find the last node of the list
        while(last->next!=*head)
            last=last->next;
             
        // Point last node to the next of head i.e.
        // the second node of the list
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
      return;
    }
     
    // Either the node to be deleted is not found
    // or the end of list is not reached
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
     
    // If node to be deleted was found
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    


}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{

// Your code goes here
 if (*head_ref == NULL)
        return;
 
    Node* prev;
    Node* current=*head_ref;
    Node* nex=current->next;
    while(nex!=(*head_ref))
    {
       prev=current;
       current=nex;
       nex=nex->next;
       current->next=prev;
    }
    (*head_ref)->next=current;
    *head_ref=current;

}