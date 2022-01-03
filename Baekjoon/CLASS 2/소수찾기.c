#include <stdio.h>

int main(){
	int i, j, n, a, count = 0;
	int tmp = 1;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a);
		if(a == 1)
			continue;
					
		for(j = a-1; j > 1; j--){
			if(a % j == 0){
				tmp = 0;	
			}
		}
				
		if(tmp)
			count++;
		
		tmp = 1;
	}
	
	printf("%d", count);
}
