#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {	
	printf("�ټ� �ڸ� ���ڸ� �Է��Ͻÿ�.\n�Է� : ");
	long long int a;
	scanf("%d", &a);
	
	int arr[5] = {0, };
	int i;
	
	printf("��� : ");
	for(i = 4; i >= 0; i--){
		arr[i] = a % 10;
		a /= 10;
		printf("%d", arr[i]);
	}
	
	return 0;
} 
