#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

node *head = NULL;

void add_first(int p){
	node *temp = (node *)malloc(sizeof(node));
	temp->data = p;
	temp->next = head;
	head = temp;
}

int main(){
	int num, n;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%d", &n);
		add_first(n);
	}

	node *k = head;
	while(k != NULL){
		printf("%d\n", k->data);
		k = k->next;
	}
}
