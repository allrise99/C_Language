#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_prn (char **sp);

int main(){
	char temp[80];
	char c;
	char **str;
	int max; // 문자열 개수 
	int i, j; 
	int length; // 문자열의 길이 
	
	printf("# of strings : ");
	scanf("%d", &max); // 문자열의 개수 입력 
	str = (char **)malloc(sizeof(char *) * (max+1)); // 2차원 배열중 세로 부분 메모리 할당
	i = 0;
	
	while (1){
		printf("Input the string : ");
		scanf("%s", temp);
		length = strlen(temp); 
		str[i] = (char *)malloc(sizeof(char) * (length + 1)); // 세로 메모리 할당
		strcpy(str[i], temp);
		
		if(length % 2 != 0){
			for (j = 0; j <= (length - 1) / 2; j++){
				c = str[i][j];
				str[i][j] = str[i][length-j-1];
				str[i][length-j-1] = c;
				}
			}
		else if (length % 2 == 0){
			for (j = 0; j <= (length / 2) - 1; j++){
				c = str[i][j];
				str[i][j] = str[i][length-j-1];
				str[i][length-j-1] = c;
			}
		}
		i++;
		if(i == max){
			printf("Complete!!");
			break;
		}
	}
	
	str[i] = 0;
	str_prn(str);
	
	i = 0;
	while(str[i] != 0){
		free(str[i]);
		++i;
	}
	free(str);
	
	return 0;
}

void str_prn (char **sp){
	printf("\n\n");
	while (*sp != 0){
		printf("\t%s\n", *sp);
		sp++;
	}
	return;
}
