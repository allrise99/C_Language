#include <stdio.h>
#include <string.h>

int main(){
	int n, i, j;
	char buf[51];
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		scanf("%s", buf);
		int count = 0;
		
		for(j = 0; j < strlen(buf); j++){
			if(buf[j] == '(')
				count++;
			else
				count--;
			
			if(count < 0)
				break;
		}
		
		if(count == 0)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	
	return 0;
}
