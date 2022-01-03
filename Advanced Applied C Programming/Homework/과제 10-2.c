#include <stdio.h>
#include <stdlib.h>

int total(int x[]);
float average(int sum);

int main(){
	int student, score;
	int i, sum;
	float avg;
	int **p;
	
	printf("Input the number of students : ");
	scanf("%d", &student); // 학생 수 입력 
	
	p = (int **)malloc(sizeof(int*)*student); // 세로 메모리 할당 
	i = 0;
	printf("Enter the score...\n");
	
	while(1) {
		p[i] = (int *)malloc(sizeof(int)*3); // 가로 메모리 할당
		int k = i + 1;
		printf("%d: ", k);
		scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
		i++;
		if(i == student)
			break;
	}
	
	printf("\n\nNO   KOR   ENG   MATH\tTOT   AVG\n");
	for (i = 0; i < student; i++){
		sum = total(p[i]);
		avg = average(sum);
		printf("%d : %4d  %4d  %4d \t %d   %.2f\n", i+1, p[i][0], p[i][1], p[i][2], sum, avg);	
	}
		
	for (i = 0; i < student; i++){
		free(p[i]);
	}
	free(p);
	
	return 0;
}

int total (int x[]){
	int i;
	int sum = 0;
	for (i = 0; i < 3; i++){
		sum += x[i];
	}
	return sum;
}

float average(int sum){
	return sum / 3.0;
}
