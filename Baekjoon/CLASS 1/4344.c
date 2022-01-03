#include <stdio.h>

int main(){
	int c, i, j, n, sum = 0; int cnt = 0;
	int arr[1000] = {0, };
	scanf("%d", &c);
	
	for(i = 0; i < c; i++){
		scanf("%d", &n);
		float avg;
		
		for(j = 0; j < n; j++){
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		
		avg = sum / (float) n;
		
		for(j = 0; j < n; j++){
			if(avg < (float) arr[j])
				cnt++;
		}
		
		printf("%.3f%%\n", cnt / (float) n * 100);
		sum = 0;
		cnt = 0;
	}
	
	return 0;
}
