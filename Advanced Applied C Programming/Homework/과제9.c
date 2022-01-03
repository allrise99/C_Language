#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {	
	printf("다섯 자리 숫자를 입력하시오.\n입력 : ");
	long long int a;
	scanf("%d", &a);
	
	int arr[5] = {0, };
	int i;
	
	printf("출력 : ");
	for(i = 4; i >= 0; i--){
		arr[i] = a % 10;
		a /= 10;
		printf("%d", arr[i]);
	}
	
	return 0;
} 
