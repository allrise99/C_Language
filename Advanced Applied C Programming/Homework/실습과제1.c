#include <stdio.h>

int main() {
	
	int i, j;
	for (i = 2; i <= 9; i++) 
	{
		for (j = 1; j <= 9; j++) {
			printf("%d*%2d=%-2d  ", i, j, i * j);
		}
		printf("\n\n");
	}

	return 0;
}
