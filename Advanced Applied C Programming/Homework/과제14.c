#include <stdio.h>
#include <string.h>

int main(){
	int i;
	char str[1001]; 
	printf("enter string : ");
	scanf("%s", str);
		
	while (i != strlen(str)){
		if (i % 2 != 0)
			printf("%c ", str[i]);
		i++;	
	}

	return 0;	
}
