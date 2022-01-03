#include <stdio.h>
#include <stdlib.h>

int row = 4;
int col = 3;
int rowsum (int p[], int i);
void colsum (int **p, int j);
int total(int **p, int row, int col);

int main(){
	int i, j, rsum, csum, totalsum;
	int **p;
	
	p = (int **)malloc(sizeof(int *)*row);
	
	for (i = 0; i < row; i++){
		p[i] = (int *)malloc(sizeof(int)*col);
	}
		
	printf("Enter the array...\n");
	for (i = 0; i < row; i++ ) {
		int k = i + 1;
		printf("%d: ", k);
		for (j = 0; j < col; j++){
			scanf("%d", &p[i][j]);
		}
	}
		
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf("%d ", p[i][j]);
			rsum = rowsum(p[i], row);
		}
		printf("| %-4d\n", rsum);
	}
	printf("---------------------------\n");
	
	totalsum = total (p, row, col);
	colsum(p, col);
	printf("| %-4d", totalsum);	
	
	for(i = 0; i < row; i++){
		free(p[i]);
	}
	free(p);
	
	return 0;
}

int rowsum (int p[], int i){ // 가로의 합 
	int j;
	int rsum = 0;
	for (j = 0; j < col; j++){
		rsum += *(p+j);
	}
	return rsum;
}

void colsum (int **p, int j){ // 세로의 합 
	int i;
	int csum[3];
	for (i = 0; i < row; i++){
		csum[i] += *(*(p+i)+j);
	}
	printf("%-3d %-3d %-3d ", csum[0], csum[1], csum[2]);
	return;
}

int total(int **p, int row, int col){
	int i, j;
	int totalsum = 0;
 	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			totalsum += p[i][j];
		}
	}
	return totalsum;
} 
