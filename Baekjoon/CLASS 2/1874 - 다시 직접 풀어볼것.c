#include <stdio.h>

int main(){
	int n, i, k, max = 0; int sidx = 0; int cidx = 0;
	int stack[100000]; char calc[200000];
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d", &k);
		if(k > max){
			for(i = max; i < k; i++){
				stack[sidx++] = i + 1;
				calc[cidx++] = '+';
			}
		}
		else if (stack[sidx-1] != k){
			printf("NO");
			return 0;
		}
		
		sidx--;
		calc[cidx++] = '-';
		if(max < k)
			max = k;
	}
	
	for(i = 0; i < cidx; i++)
		printf("%c\n", calc[i]);
		
	return 0;
}
