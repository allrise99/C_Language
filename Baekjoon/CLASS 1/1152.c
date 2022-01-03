#include <stdio.h>
#include <string.h>

int main(){
	int cnt = 0;
	char str[1000001];
	scanf("%[^\n]s", str);
	char *ptr = strtok(str, " ");
	
	while(ptr != NULL){
		cnt++;
		ptr = strtok(NULL, " ");
	}
	
	printf("%d\n", cnt);
	return 0;
}
