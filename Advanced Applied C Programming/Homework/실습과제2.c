#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	int a;
	printf("Input : ");
	scanf("%d", &a);
	
	int sum = 0;
	int count = 0;
	int i;
	
	for(i = 1; ; i++){
		if(i > 1000)
			break;
		else if(i % 7 != 0)
			continue;
		count++;
		sum += i;
		
		if(count == a) // count가 n일때 
			printf("\n\nOutput\n\n\tthe %dth number is %d", a, i); 
			//그때의 루프 횟수 i와 입력값 n 출력  
	}
	
	printf("\n\n\tsum is %d\n\n\tnumber is %d", sum, count);
	
	return 0;	
}
