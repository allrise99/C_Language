#include <stdio.h>

int number = 10;

void quicksort(int *data, int start, int end){
	if(start >= end){
		return;
	}
	
	int key = start; // �ǹ�
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){ // ������ ������ �ݺ� 
		while(data[i] <= data[key]){ // �ǹ����� ū ���� ���������� ���������� �̵� 
			i++;
		}
		while(data[j] >= data[key] && j > start){ // �ǹ����� ���� ���� ���������� �������� �̵� 
			j--;
		}
		
		if(i > j){ // �����ȴٸ� �ǹ� ���� ��ü 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		
		else{ // �������� �ʾҴٸ� ū ���� ���� ���� ��ȯ 
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	// �ǹ� �������� ������ �����ٸ� ���ʰ� �����ʿ� ���ؼ� �������� 
	
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
