// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next, *prev;
};

// function to count pairs whose sum equal to given 'value'
int countPairs(struct Node* first, struct Node* second, int value)
{
	int count = 0;

	// The loop terminates when either of two pointers
	// become NULL, or they cross each other (second->next
	// == first), or they become same (first == second)
	while (first != NULL && second != NULL &&
		first != second && second->next != first) {

		if ((first->data + second->data) == value) {

			count++;

		
			first = first->next;

		
			second = second->prev;
		}

		// if sum is greater than 'value'
		// move second in backward direction
		else if ((first->data + second->data) > value)
			second = second->prev;

		// else move first in forward direction
		else
			first = first->next;
	}

	// required count of pairs
	return count;
}
int countTriplets(struct Node* head, int x)
{
	
	if (head == NULL)
		return 0;

	struct Node* current, *first, *last;
	int count = 0;

	last = head;
	while (last->next != NULL)
		last = last->next;
	for (current = head; current != NULL; current = current->next) {

	
		first = current->next;

		// count pairs with sum(x - current->data) in the range
		// first to last and add it to the 'count' of triplets
		count += countPairs(first, last, x - current->data);
	}
	return count;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}


int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);

	int x = 17;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
