#include <stdio.h>
#include <stdlib.h>

int main(){
	char str[101];
	FILE *fop;
	fop = fopen("1.txt", "w");
		
	if(fop == NULL){
		printf("Could not open output file\n");
		return 1;
	}
	
	while(fgets(str, sizeof(str), stdin)){
		fputs(str, fop);
	}
	
	fclose(fop);
	
	return 0;	
} 
