#include <stdio.h>
#include <string.h>
#define CAPA 10

typedef struct queue {
	int array[CAPA];
	int head;
	int tail;
	int size;
}Queue;
Queue* q;

int is_empty(Queue q);
void push(Queue q, int data);
int pop(Queue q);
int size(Queue q);
int empty(Queue q);
int front(Queue q);
int back(Queue q);


int main() {
	int n;
	char buffer[CAPA];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", buffer);
		if (strcmp("push", buffer) == 0) {

		}
		if (strcmp("pop", buffer) == 0) {


		}
		if (strcmp("size", buffer) == 0) {

		}
		if (strcmp("empty", buffer) == 0) {

		}
		if (strcmp("front", buffer) == 0) {

		}
		if (strcmp("back", buffer) == 0) {

		}
	}


}

int is_empty(Queue q) {
	if (size == 0)
		return 1;
	else
		return 0;
}

void push(Queue q, int data) {
	
}
int pop(Queue q);
int size(Queue q);
int empty(Queue q);
int front(Queue q);
int back(Queue q);
