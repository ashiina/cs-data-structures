#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Qnode 
{
	int data;
	struct Qnode* next;
};

struct Queue
{
	struct Qnode* front;
	struct Qnode* rear;
};

void enqueue (struct Queue* queue, int data)
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

	printf("enqueued %d\n", data);
}

int dequeue (struct Queue* queue)
{
	if (queue->front == NULL) {
		return INT_MIN;
	}

	struct Qnode* node = queue->front;
	int data = node->data;

	queue->front = node->next;
	free(node);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	return data;
}

int main() 
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;

	enqueue(queue, 1);
	printf("%d\n", dequeue(queue));

	enqueue(queue, 3);
	printf("%d\n", dequeue(queue));

	enqueue(queue, 5);
	enqueue(queue, 7);
	enqueue(queue, 9);

	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
}


