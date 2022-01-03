#include <stdio.h>
#include <math.h>
/*
int main(){
	int up, down;
	long long int total, sum = 0;
	long long int day = 0;
	scanf("%d %d %lld", &up, &down, &total);
	
	while(sum != total){
		day++;
		if(sum + up == total || sum + up >= total)
			break;
		
		sum += up - down;
	}
	
	printf("%d", day);
}
// 시간초과 
*/

int main(){
	long long int a, b, v, day;
	long double tmp;
	scanf("%lld %lld %lld", &a, &b, &v);
	
	tmp = (v-a) / (long double)(a-b) + 1;
	day = ceil(tmp);
		
	printf("%lld", day);
}
