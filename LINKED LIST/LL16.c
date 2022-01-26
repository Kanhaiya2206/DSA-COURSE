// Check if Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node
{
	int data;
	struct Node* next;
};    

/* Should return true if linked list is circular, else false */
bool isCircular(struct Node *head){
    
    if(head==NULL)
    return true;
    
    struct Node* S=head;
    while(true)
    {
        if(S->next==head)
          return true;
        if(S->next==NULL)
          return false;
        
        S=S->next;  
    }
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d", &n);
		scanf("%d", &k);
		int first;
		scanf("%d", &first);
		struct Node *head;
		head = (struct Node *) malloc(sizeof(struct Node));
		head->data = first;
		head->next = NULL;
		struct Node *tail = head;

		for (int i = 1; i < n; ++i)
		{
			int data;
			scanf("%d", &data);
			struct Node *temp;
			temp = (struct Node *) malloc(sizeof(struct Node));
			temp->data = data;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
		}

        if (k==1 && n >= 1)
            tail->next = head;
		
		printf("%d \n", isCircular(head));
	}
	return 0;
}  