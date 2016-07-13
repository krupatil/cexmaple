#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
} Node;

void reverse(Node **head)
{
	Node *curr = NULL, *prev = NULL, *next = NULL;

	curr = *head;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	}
	*head = prev;
}

int count(Node *head)
{
	int c = 0;

	while(head != NULL)
	{
		head = head->next;
		c++;
	}
	printf("Count: %d\n", c);	
	return c;
}

void findMiddleIdx(Node *head)
{
	int count = 0;
	Node *slow = head, *fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		count++;
	}
	printf("Count: %d\n", count);
}


void printList(Node *head)
{
	while(head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

void swap(Node **head, int x, int y)
{
	Node *xNode = *head, *prevX = NULL, *yNode = *head, *prevY = NULL;

	while( xNode != NULL && xNode->data != x)
	{
		prevX = xNode;
		xNode = xNode->next;
	}
	if(xNode == NULL)
		printf("Key: %d not found.\n", x);
	else 
	{
		while(yNode != NULL && yNode->data != y)
		{
			prevY = yNode;
			yNode = yNode->next;
		}

		if(yNode == NULL)
			printf("Key: %d not found.\n", y);
		else
		{
			if(prevX != NULL)
				prevX->next = yNode;
			else
				*head = yNode;

			if(prevY != NULL)
				prevY->next = xNode;
			else
				*head = xNode;

			Node *temp = yNode->next;
			yNode->next = xNode->next;
			xNode->next = temp;
		}
	}
}

void delete(Node **head, int key)
{
	Node *prev, *temp = *head;

	if(*head != NULL && (*head)->data == key)
	{
		*head = temp->next;
		free(temp);	
	}
	else
	{
		while(temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL)
			printf("Key: %d not found.\n", key);
		else
		{
			prev->next = temp->next;
			free(temp);
		}
	}
}

void addBefore(Node **head, int key, int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;

	if(*head != NULL && (*head)->data == key)
	{
		new->next = (*head)->next;
		(*head)->next = new;
	}
	else
	{
		Node *prev = NULL, *temp = *head;
		while(temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL)
			printf("Key: %d not found.\n", key);
		else
		{
			new->next = temp;
			prev->next = new;
		}
	}
}

void addAfter(Node **head, int key, int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;

	if(*head != NULL && (*head)->data == key)
	{
		new->next = (*head)->next;
		(*head)->next = new;
	}
	else
	{
		Node *temp = *head;
		while(temp != NULL && temp->data != key)
			temp = temp->next;
		
		if(temp == NULL)
			printf("Key: %d not found.\n", key);
		else {
			new->next = temp->next;
			temp->next = new;
		}
	}
}

void append(Node **head, int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	
	if(*head == NULL)
		*head = new;
	else {
		Node *last = *head;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void push(Node **head, int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->next = *head;
	*head = new;
}

int main()
{
	Node *head = NULL;
	int i = 0;
	for(i = 0; i < 5; i++) {
		push(&head, i + 1);
		printList(head);
	}

	printf("################## APPEND ################### \n");
	append(&head, ++i);
	printList(head);
	
	printf("################## ADD AFTER################### \n");
	addAfter(&head, 6, ++i);
	printList(head);
	
	printf("################## ADD BEFORE################### \n");
	addBefore(&head, 6, ++i);
	printList(head);

	printf("################## DELETE################### \n");
	delete(&head, 5);
	printList(head);

	printf("################## SWAP ################### \n");
	swap(&head, 4, 7);
	printList(head);

	count(head);
	findMiddleIdx(head);

	reverse(&head);
	printList(head);
}

