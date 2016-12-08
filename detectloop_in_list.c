#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct List {
	int data;
	struct List *next;
	
} List;

List * getNewNode(int data)
{
	List *new = malloc(sizeof(List));
	new->data = data;
	new->next = NULL;
	return new;
}

void printList(List *head)
{
	List *temp = head;
	while(temp) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void push(List **head, int data)
{
	List *new = getNewNode(data);
	new->next = *head;
	*head = new;
}

void detectAndRemove(List *head)
{
	List *slow = head;
	List *fast = head;
	List *temp = NULL;
	bool found = false;

	while(slow && fast && fast->next)
	{
		if(slow->next == head)
			temp = slow;
		
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			found = true;
			if(fast == head)
				temp->next = NULL;
			else
				fast->next = NULL;
			break;
		}
	}
	if(found)
		printf("Loop found and removed.\n");
	else
		printf("Loop not found.\n");
}

int main()
{
	List *head = NULL;
	push(&head, 0);
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	printList(head);
	
	head->next->next->next = head->next->next;
	detectAndRemove(head);
	detectAndRemove(head);
}
