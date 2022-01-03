#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, buf, top = -1;
	int sum = 0;
	scanf("%d", &n);
	int *p = (int *)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++){
		scanf("%d", &buf);
		if(buf == 0){
			*(p+top) = 0;
			top--;
		}
	
		else{
			top++;
			*(p+top) = buf;
		}
	}
	
	for(i = 0; i <= top; i++){
		sum += p[i];
	}
	
	printf("%d", sum);
}
