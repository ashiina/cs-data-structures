#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void printList(struct Node *n)
{
	while (n != NULL) {
		printf("# %d (next:%p) \n", n->data, n->next);
		n = n->next;
	}
}

int main() 
{

	int nodes = 25;
	struct Node* first_node = NULL;
	struct Node* prev_node = NULL;

	for (int i=0; i < nodes; i++) {
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		node->data = i+1;
		node->next = NULL;

		if (first_node == NULL) {
			first_node = node;
		}

		if (prev_node != NULL) {
			prev_node->next = node;
		}

		prev_node = node;
	}


	printList(first_node);

	return 0;
}

