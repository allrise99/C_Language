#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int biggest(int *p, int size); // 최대값 찾는 함수 

int main() {
	int i;
	int size;
	float max;
	float sum = 0.0;
	int *p, *ip;
	
	printf("Input number of students : "); // 학생 수 입력받음 
	scanf("%d", &size);	
	p = (int *)malloc(sizeof(int) * size);
	
	if(p == 0){
		printf("memory not allocated\n");
		return 1;
	}
	
	printf("\nInput %d numbers : ", size);
	
	for (i = 0; i < size; ++i){
		scanf("%d", p+i);
		sum += p[i];
	}
		
	max = (float) biggest(p, size);
	
	printf("\n\n\tArray Size : %d", size);
	printf("\n\nMaximum element : %2.1f", max);
	printf("\n\tAverage : %3.1f\n\t    Sum : %3.1f\n", sum / size, sum);
		
	free(p);

	return 0;	
}

int biggest(int *p, int size){
	int max = *p;
	int *pWalk, *pLast;
	pLast = p + size - 1;
		
	for (pWalk = p; pWalk <= pLast; pWalk++){
		if(max < *pWalk)
			max = *pWalk;
	}
	return max;
}
