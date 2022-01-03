#include <stdio.h>

int main(){
	int i, n, k, num = 1;
	scanf("%d %d", &n, &k);
	
	for(i = n; i >= n-k+1; i--){
		num *= i;
	}
	
	for(i = 1; i <= k; i++){
		num /= i;
	}
	
	printf("%d", num);
}
