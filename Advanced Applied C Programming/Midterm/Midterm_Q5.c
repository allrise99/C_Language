#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int size, i, length;
	char **str;
	char temp[80];
	printf("How many names do you plan to input? ");
	scanf("%d", &size);
	
	str = (char **)malloc(sizeof(char *) * (size+1));
	i = 0;
	printf("\nEnter names : \n");
	while(1) {
		scanf("%s", temp);
		length = strlen(temp);
		str[i] = (char *)malloc(sizeof(char) * (length + 1));
		strcpy(str[i], temp);		
		i++;
		
		if(i == size)
			break;
	}
	
	printf("\n입력한 이름들 : \n");
	
	for (i = 0; i < size; i++){
		printf("%d : %s\n", i, str[i]);
	}
	
	
	for (i = 0; i < size; i++){
		free(str[i]);
	}
	
	free(str);
	
	return 0;
}
