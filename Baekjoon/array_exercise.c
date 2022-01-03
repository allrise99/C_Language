#include <stdio.h>
#include <string.h>

#define BUF_SIZ 7
int stack[10000];
int top = -1;

int main(){
	int n, buf;
	char cmd[BUF_SIZ];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", cmd);
		if(strcmp(cmd, "push") == 0){
			scanf("%d", &buf);
			top++;
			stack[top] = buf;
		}
		
		if(strcmp(cmd, "pop") == 0){
			if(top == -1)
				printf("%d\n", -1);
			else {
				printf("%d\n", stack[top]);
				top--;
			}
		}
		if(strcmp(cmd, "size") == 0){
			printf("%d\n", top+1);
		}
		if(strcmp(cmd, "empty") == 0){
			if(top == -1)
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		if(strcmp(cmd, "top") == 0){
			if(top == -1)
				printf("%d\n", -1);
			else
				printf("%d\n", stack[top]);
		}
	}
}
