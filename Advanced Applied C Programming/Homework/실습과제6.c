#include <stdio.h>

int main(){
	
	char str[81];
	
	fgets(str, sizeof(str), stdin);
	if(islower(*str))
		fputs(str, stdout);
		
	return 0;	
} 
