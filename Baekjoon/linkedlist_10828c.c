#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZ 7

int count = 0;
typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct stack {
	node *top;
}stack;
//stack.top = NULL;

int isempty(stack *s);
void push(stack *s, int input);
int pop(stack *s);
void size(stack *s, int count);
int empty(stack *s);
int print_top(stack *s);

int main(){
	int n, data;
	stack s;
	char cmd[BUF_SIZ];
	scanf("%d", &n);
	
	for (int i=0; i<n; i++){
		scanf("%s", cmd);
		if(strcmp(cmd, "push") == 0){
			scanf("%d", &data);
			push(&s, data);
			count++;
		}
		
		if(strcmp(cmd, "pop") == 0){
			printf("%d\n", pop(&s));
		}
		
		if(strcmp(cmd, "size") == 0)
			size(&s, count);

		if(strcmp(cmd, "empty") == 0)
			printf("%d\n", empty(&s));
			
		if(strcmp(cmd, "top") == 0)
			printf("%d\n", print_top(&s));
	}
	
	return 0;
}

int isempty(stack *s){
	return s->top == NULL;
}

void push(stack *s, int input){
	node *newnode= (node *)malloc(sizeof(node));
	newnode->data = input;
	newnode->next = s->top;
	s->top = newnode;
}

int pop(stack *s){
	if(empty(s))
		return -1;
		
	else {
	node *popnode = (node *)malloc(sizeof(node));
	int re;

	popnode = s->top;
	re = popnode->data;
	s->top->next = popnode->next;
	free(popnode);	
	return re;
	}
}

void size(stack *s, int count){
	printf("%d\n", count);
}

int empty(stack *s){
	if(isempty(s))
		return 1;
	return 0;
}

int print_top(stack *s){
	if(isempty(s))
		return -1;
	return s->top->data;
}
