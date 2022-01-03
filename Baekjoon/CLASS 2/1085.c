#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, c, d, i, min = 0;
	int *p = (int *)malloc(sizeof(int) * 4);
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	*p = a;
	*(p+1) = b;
	*(p+2) = c-a;
	*(p+3) = d-b;
		
	min = *p;
	for(i = 0; i < 4; i++){
		if(*(p+i) < min)
			min = *(p+i);
	}
	
	printf("%d", min);
	
	return 0;
}

// if문 여러개 쓰기 싫어서 그냥 포인터로.. 풀은 문제.. 
