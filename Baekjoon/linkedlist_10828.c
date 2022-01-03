#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	int data;
	Stack* next;
}Stack;

Stack *top;
Stack s[10000];

int main(){
	int i, n, buf;
	char cmd[BUFFER_SIZE];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		if(strcmp(cmd, "push")){
			scanf("%d", &buf);
			Stack *newnode = (Stack *)malloc(sizeof(Stack));
			newnode->data = buf;
			newnode->next = top;
			top = newnode;
			printf("%d\n", buf);
		}
		if(strcmp(cmd, "pop")){
			printf("%d\n", top->data);
			
			
		}
		if(strcmp(cmd, "size")){
			
		}
		if(strcmp(cmd, "top")){
			
		}
		if(strcmp(cmd, "empty")){
			
		}
	}
	return 0;
}
