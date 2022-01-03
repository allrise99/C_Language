#include <stdio.h>

int number = 10;

void quicksort(int *data, int start, int end){
	if(start >= end){
		return;
	}
	
	int key = start; // 피벗
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){ // 엇갈릴 떄까지 반복 
		while(data[i] <= data[key]){ // 피벗보다 큰 값을 만날때까지 오른쪽으로 이동 
			i++;
		}
		while(data[j] >= data[key] && j > start){ // 피벗보다 작은 값을 만날떄까지 왼쪽으로 이동 
			j--;
		}
		
		if(i > j){ // 엇갈렸다면 피벗 값과 교체 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		
		else{ // 엇갈리지 않았다면 큰 값과 작은 값을 교환 
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	// 피벗 기준으로 정렬이 끝났다면 왼쪽과 오른쪽에 대해서 정렬해줌 
	
	quicksort(data, start, j-1);
	quicksort(data, j+1, end);
	
}

int main(){
	int i;
	int data[10];
	
	for(i = 0; i < 10; i++){
		scanf("%d", &data[i]);
	}
		
	quicksort(data, 0, number-1);
	
	for(i = 0; i < number; i++){
		printf("%d ", data[i]);
	} 
}
