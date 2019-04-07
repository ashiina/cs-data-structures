#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node 
{
	int data;
	struct Node* next;
};

void push (struct Node** root, int data) 
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = *root;

	*root = node;
}

int pop (struct Node** root)
{
	if (*root == NULL) {
		return INT_MIN;
	}

	struct Node* node = *root;
	*root = (*root)->next;
	int data = node->data;
	free(node);
	return data;
}

int peek (struct Node* root)
{
	return root->data;
}

int main() 
{
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root->data = 1;
	root->next = NULL;

	push(&root, 3);
	push(&root, 5);
	printf("%d\n", pop(&root));
	printf("%d\n", pop(&root));
	push(&root, 7);
	push(&root, 9);
	push(&root, 11);
	printf("%d\n", peek(root));
	printf("%d\n", pop(&root));
	printf("%d\n", pop(&root));
	printf("%d\n", pop(&root));
	printf("%d\n", pop(&root));
	printf("%d\n", pop(&root));
}


