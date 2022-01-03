#include <stdio.h>

#define COUNT 10

int main(){
	int i, tmp, cnt = 0;
	int a[42] = {0, };
	
	for(i = 0; i < COUNT; i++){
		scanf("%d", &tmp);
		tmp %= 42;
		a[tmp] = 1;
	}
	
	for(i = 0; i < 42; i++){
		if(a[i] == 1)
			cnt++;
	}
	
	printf("%d", cnt);
}

/* 참고 : 다른 수 찾는 알고리즘

#include <stdio.h>
int main(){
     int n, i, tmp, cnt=0;
     int a[1000]={0, };
     scanf("%d", &n);
     
     for(i=0; i<n; i++){
        scanf("%d", &tmp);
        a[tmp] = 1; 
    }
     for(i=0; i<1000; i++){
      if(a[i] == 1)
       cnt++;
     }
     printf("%d", cnt);
}

*/ 
