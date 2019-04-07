#include <stdio.h>
#include <stdlib.h>

struct Tnode
{
	int data;
	struct Tnode* left;
	struct Tnode* right;
};


/* queue */
struct Qnode 
{
	struct Tnode* data;
	struct Qnode* next;
};

struct Queue
{
	struct Qnode* front;
	struct Qnode* rear;
};

void enqueue (struct Queue* queue, struct Tnode* data)
{
	struct Qnode* node = (struct Qnode*)malloc(sizeof(struct Qnode));
	node->data = data;
	node->next = NULL;

	if (queue->front == NULL) {
		queue->front = node;
	}

	if (queue->rear != NULL) {
		queue->rear->next = node;
	}
	queue->rear = node;

//	printf("enqueued %d\n", data->data);
}

struct Tnode* dequeue (struct Queue* queue)
{
	if (queue->front == NULL) {
		return NULL;
	}

	struct Qnode* node = queue->front;
	struct Tnode* data = node->data;

	queue->front = node->next;
	free(node);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	return data;
}

/* binary tree */

struct Tnode* newNode(int data)
{
	struct Tnode* node = (struct Tnode*)malloc(sizeof(struct Tnode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert(struct Tnode* root, int data)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, root);

	while (queue->front != NULL) {
		struct Tnode* node = dequeue(queue);
		if (node->left == NULL) {
			node->left = newNode(data);
			break;
		} else {
			enqueue(queue, node->left);
		}
 
		if (node->right == NULL) {
			node->right = newNode(data);
			break;
		} else {
			enqueue(queue, node->right);
		}
	}
}

void deleteDeepest(struct Tnode* root, struct Tnode* dnode)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, root);

	while (queue->front != NULL) {
	struct Tnode* node = dequeue(queue);
		if (node->left != NULL) {
			if (node->left == dnode) {
				node->left = NULL;
				free(dnode);
				break;
			} else {
				enqueue(queue, node->left);
			}
		}
 
		if (node->right != NULL) {
			if (node->right == dnode) {
				node->right = NULL;
				free(dnode);
				break;
			} else {
				enqueue(queue, node->right);
			}
		}
	}
}

void deletion(struct Tnode* root, int data)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, root);

	struct Tnode* delete_node;
	struct Tnode* node;
	while (queue->front != NULL) {
		node = dequeue(queue);
		if (node->data == data) {
			delete_node = node;
		}

		if (node->left != NULL) {
			enqueue(queue, node->left);
		}
 
		if (node->right != NULL) {
			enqueue(queue, node->right);
		}
	}

	delete_node->data = node->data;
	deleteDeepest(root, node);
}

void inorder(struct Tnode* root)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf(" %d ", root->data);
	inorder(root->right);
}

void preorder(struct Tnode* root)
{
	if (root == NULL) {
		return;
	}
	printf(" %d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct Tnode* root)
{
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf(" %d ", root->data);
}



/* main */
int main()
{
	printf("=====insert/delete=====\n");
	struct Tnode* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->left->right = newNode(12);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

//	insert(root, 12);
//	printf("should be 12: %d\n", root->left->right->data);
	deletion(root, 11);
	printf("should be 8: %d\n", root->left->data);
	inorder(root);
	printf("\n");

	printf("=====traversal=====\n");
	struct Tnode* root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);
	printf("preorder:\n");
	preorder(root2);
	printf("\n");
	printf("inorder:\n");
	inorder(root2);
	printf("\n");
	printf("postorder:\n");
	postorder(root2);
	printf("\n");
}

