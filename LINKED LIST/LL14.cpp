//QuickSort for Linked Lists....
#include <iostream>
#include <cstdio>
using namespace std;
 

struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}

//My contribution to the code starts from here..

node* partition(node* head,node* tail) //partition algo which returns address of pivot element.
{
    node* i=head;
    node* j=head;
    int pivot=head->data;
    while(j!=NULL)
    {
        if(j->data<pivot)
        {
            i=i->next;
            swap(i->data,j->data);
        }
        j=j->next;
    }
    swap(i->data,head->data);
    
    return i;
}
void Quick(node* head,node * tail)        //QuickSort Algorithm
{       
    
        if(head!=tail)
        {
        node* pivot=partition(head,tail);
        Quick(head,pivot);
        Quick(pivot->next,tail);
        }
    
}
void quickSort(struct node **headRef) {
    Quick(*headRef,NULL);
    
}