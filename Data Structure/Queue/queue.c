#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"
#define INIT_CAPACITY 100

struct queue_type {
	Item* contents;
	int front;
	int rear;
	int size; // 배열에 들어있는 수의 개수
	int capacity; // 배열 contents의 수용 능력
};

void terminate(const char* message) {
	printf("%s\n", message);
	exit(1);
}

int getsize(Queue q) {
	return q->size;
}

Queue create() {
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create : queue could not be created.");
	q->contents = (Item*)malloc(sizeof(Item) * INIT_CAPACITY);
	if (q->contents == NULL) {
		free(q);
		terminate("Error in create : queue could not be created.");
	}
	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = INIT_CAPACITY;
	return q;
}

void destroy(Queue q) {
	free(q->contents);
	free(q);
}

void make_empty(Queue q) {
	q->front = 0;
	q->rear = -1;
	q->size = 0;
}

bool is_empty(Queue q) {
	return q->size == 0;
}

bool is_full(Queue q) {
	return q->size == q->capacity;
}

void enqueue(Queue q, Item i) {
	if (is_full(q))
		reallocate(q);
	q->rear = (q->rear + 1) % q->capacity;
	q->contents[q->rear] = i;
	q->size++;
}

Item dequeue(Queue q) {
	if (is_empty(q))
		terminate("Error in dequeue : queue is empty.");
	Item result = q->contents[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return result;
}

Item peek(Queue q) {
	if (is_empty)
		terminate("Error in peek : queue is empty.");
	return q->contents[q->front];
}

void reallocate(Queue q) {
	Item* temp = (Item*)malloc(sizeof(Item) * 2 * q->capacity);
	if (temp == NULL)
		terminate("Error in create : queue could not be expanded.");
	int j = q->front;
	for (int i = 0; i < q->size; i++) {
		temp[i] = q->contents[j];
		j = (j + 1) % q->capacity;
	}
	free(q->contents);
	q->front = 0;
	q->rear = q->size - 1;
	q->contents = temp;
	q->capacity *= 2;
}

int main() {
	int n;
	scanf(% d, &n);
	while()
}