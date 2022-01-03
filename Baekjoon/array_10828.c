#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 7
int stack[10000];

int main(){
	int n, buf, top = -1;
	char command[BUFFER_SIZE];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", command);
		
		if(strcmp(command, "push") == 0){
			scanf("%d", &buf);
			top++;
			stack[top] = buf;
		}
		if(strcmp(command, "pop") == 0){
			if(top < 0)
				printf("-1\n");
			else{
				printf("%d\n", stack[top]);
				top--;
			}
		}
		if(strcmp(command, "size") == 0){
			printf("%d\n", top+1);
		}
		if(strcmp(command, "empty") == 0){
			if(top < 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if(strcmp(command, "top") == 0){
			if(top < 0)
				printf("-1\n");
			else{
				printf("%d\n", stack[top]);
			}
		}
	}
}
