#include <stdio.h>
#define MAX_ROWS 5
#define MAX_COLS 4

void print_square (int *p); 

int main(){
	int table [MAX_ROWS][MAX_COLS] = 
			{
				{0, 1, 2, 3},
				{10, 11, 12, 13},
				{20, 21, 22, 23},
				{30, 31, 32, 33},
				{40, 41, 42, 43}
			};
	int row, col;
	int *p;
	
	for (row = 0; row < MAX_ROWS; row++){
		for (col = 0; col < MAX_COLS; col++){
			p = &table[row][col];
			print_square(p);
		}
		printf("\n");
	}
	return 0;
}

void print_square (int *p) { 
	printf("%6d ",(*p) * (*p));
	return;
}
