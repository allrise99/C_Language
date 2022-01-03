#include <stdio.h>
#include <string.h>

int is_empty(int front, int rear){
	return (front == rear);
}

int main(){
	int n, i, buf; int front = 0; int rear = 0;
	char cmd[7];
	scanf("%d", &n);
	int arr[n];
	
	for(i = 0; i < n; i++)
		arr[i] = 0;
	
	for(i = 0; i < n; i++){
		scanf("%s", cmd);
		
		if(strcmp(cmd,"push") == 0){
			scanf("%d", &buf);
			arr[rear] = buf;
			rear++;
		}
		
		if(strcmp(cmd,"pop") == 0){
			if(is_empty(front, rear))
				printf("-1\n");
			else{
				printf("%d\n", arr[front]);
				arr[front] = 0;
				front++;
			}
		}
		
		if(strcmp(cmd,"size") == 0){
			printf("%d\n", rear-front);
		}
		
		if(strcmp(cmd,"empty") == 0){
			if(is_empty(front, rear))
				printf("1\n");
			else
				printf("0\n");
		}
		
		if(strcmp(cmd,"front") == 0){
			if(is_empty(front, rear)){
				printf("-1\n");
			}
			else
				printf("%d\n", arr[front]);
		}
		
		if(strcmp(cmd,"back") == 0){
			if(is_empty(front, rear)){
				printf("-1\n");
			}
			else
				printf("%d\n", arr[rear-1]);
		}
	}
	return 0;
}
