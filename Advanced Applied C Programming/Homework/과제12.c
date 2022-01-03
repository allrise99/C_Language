#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_prn (char **sp);

int main(){
	char temp[80];
	char c;
	char **str;
	int max; // ���ڿ� ���� 
	int i, j; 
	int length; // ���ڿ��� ���� 
	
	printf("# of strings : ");
	scanf("%d", &max); // ���ڿ��� ���� �Է� 
	str = (char **)malloc(sizeof(char *) * (max+1)); // 2���� �迭�� ���� �κ� �޸� �Ҵ�
	i = 0;
	
	while (1){
		printf("Input the string : ");
		scanf("%s", temp);
		length = strlen(temp); 
		str[i] = (char *)malloc(sizeof(char) * (length + 1)); // ���� �޸� �Ҵ�
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
