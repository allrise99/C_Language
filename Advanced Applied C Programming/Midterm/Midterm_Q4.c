// ¹®Á¦ 4 
#include <stdio.h>
#include <stdlib.h>
int maximum(int *p, int size);
float average(int sum, int size);
int total (int *p, int size);

int main(){
	int i, j, size, max, sum;
	float avg;
	int *p;
	printf("How many students : ");
	
	scanf("%d", &size);
	p = (int *)malloc(sizeof(int) * size);
	
	printf("\nInput numbers : ");
	for (i = 0; i < size; i++){
		scanf("%d", p+i);
	}
	
	max = maximum(p, size);
	sum = total(p, size);
	avg = average(sum, size);
	
	printf("\n\nArray size : %d\n", size);
	printf("Maximum : %d\n", max);
	printf("Average : %.2f\n", avg);
	printf("Sum : %d\n", sum);	
	
	free(p);
	
	return 0;
}

int maximum(int *p, int size){
	int *pwalk, *plast;
	int max = *p;
	plast = p + size - 1;
	for (pwalk = p; pwalk <= plast; pwalk++){
		if(max < *pwalk)
			max = *pwalk;
	}
	return max;
}

float average(int sum, int size){
	return sum / (float) size;
}

int total (int *p, int size){
	int i;
	int sum = 0;
	for (i = 0; i < size; i++){
		sum += *(p+i);
	}
	return sum;
}
