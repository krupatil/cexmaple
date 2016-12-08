#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
} List;

void printNode(List *head)
{
	if(!head)
		printf("List is empty.\n");

	while(head) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

int deleteNode(List **head, int data)
{
	List *curr = *head;
	List *prev = *head;

	if(curr && curr->data == data)
	{
		*head = curr->next;
		free(curr);
		return 0;
	}

	while(curr) { 
		if(curr->data == data)
			break;

		prev = curr;
		curr = curr->next;
	}

	if(!curr) {
		printf("Element not found.\n");
		return -1;
	}

	prev->next = curr->next;
	free(curr);
	
	return 0;
}

int addNode(List **head, int data)
{
	List *new = (List *)malloc(sizeof(List));
	if(new == NULL) {
		printf("Failed to allocate memory for new node.\n");
		return -1;
	} else {
		new->data = data;
		new->next = NULL;

		if(*head == NULL)
			*head = new;
		else {
			List *temp = *head;
			while(temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
	return 0;
}


int main()
{
	List *head = NULL;

	for(int i = 0; i < 5; i++) {
		printf("Adding Element: %d\n", i);
		(void)addNode(&head, i);
	}

	(void)deleteNode(&head, 2);
#if 0
	for(int i = 4; i >= 0; i--) {
		printf("Deleting Element: %d\n", i);
		(void)deleteNode(&head, i);
	        printNode(head);
	}
#endif
	printNode(head);
}
