#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char *data;
	struct node *next;
} Node;

Node *head = NULL;

void add_first(Node **ptr_head, char *item){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = item;
	temp->next = *ptr_head;
	*ptr_head = temp;
	printf("%s\n", head->data);
}

int main(){
	Node *head = (Node *)malloc(sizeof(Node));
	head->data = "B";
	head->next = NULL;
	
	Node *q = (Node *)malloc(sizeof(Node));
	q->data = "D";
	q->next = NULL;
	head->next = q;
	
	char *item = "Ann";
	add_first(&head, item);
	
	Node *curr = head;
	while(curr != NULL){
		printf("%s\n", curr->data);
		curr = curr->next;	
	}
}


