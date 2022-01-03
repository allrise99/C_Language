#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	if(*(int *)a < *(int *)b)
		return -1;
		
	if(*(int *)a > *(int *)b)
		return 1;
	
	return 0;
}

int search (int arr[], int n, int target){
	int left = 0;
	int right = n-1;
	int pivot;
		
	while(left <= right){
		pivot = (left + right) / 2;
		
		if(arr[pivot] == target){
			return 1;
		}
		
		else if(arr[pivot] < target)
			left = pivot + 1;
		
		else
			right = pivot - 1;		
	}
	return 0;
}


int main(){
	int n, m, i, res;
	int arr[100000] = { 0, };
	int tmp[100000] = { 0, };
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	qsort(arr, n, sizeof(int), compare);
		
	scanf("%d", &m);
	
	for(i = 0; i < m; i++)
		scanf("%d", &tmp[i]);
		
	for(i = 0; i < m; i++){
		res = search(arr, n, tmp[i]);
		printf("%d\n", res);
	}
}
