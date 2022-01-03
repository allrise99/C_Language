#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, col;
	char c;
	char **matrix;
	printf("Enter the size of matrix & alphabet : \n");
	scanf("%d %d %c", &row, &col, &c);
	
	matrix = (char **)malloc(sizeof(char *) * row);
	int i, j;
	for (i = 0; i < row; i++){
		matrix[i] = (char *)malloc(sizeof(char) * col);
	} // 메모리 할당 
		
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if(i == j)
				matrix[i][j] = '0';
			else if (i < j){ // upper diagonal 
				matrix[i][j] = c;
				if('a' <= c && c <= 'z')
				matrix[i][j] = c - 97 + 65;
			}
			else if (j < i){ // lower diagonal
				matrix[i][j] = c;
				if('A' <= c && c <= 'Z'){
					matrix[i][j] = c - 65 + 97;
				}
			}							
		}
	}
	
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	} // 출력 
	
	for (i = 0; i < col; i++){
		free(matrix[i]);
	}
	free(matrix); // 메모리 해제 
	
	return 0;
}
