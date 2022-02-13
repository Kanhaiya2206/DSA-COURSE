// C++ program to merge k sorted Linked List...
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* Merge(Node* a,Node* b)
    {
        Node* result;
        if(a==NULL) return b;
        if(b==NULL) return a;
        
        if(a->data<=b->data)
        {
            result=a;
            result->next=Merge(a->next,b);
        }
        else
        {
            result=b;
            result->next=Merge(a,b->next);
        }
        return result;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           int i=0;
           int last=K-1;
           int j;
           while(last!=0)
           {
               i=0;
               j=last;
              while(i<j)
              {
               arr[i]=Merge(arr[i],arr[j]);
               i++;
               j--;
               if(i>=j)
                 last=j;
               
              }
           }
           return arr[0];
           
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends