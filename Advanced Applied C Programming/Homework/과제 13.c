#include <stdio.h>

int i_average (int a[]);
double h_average (double a[]);

int main(){
	FILE *ifp, *ofp;
	char name[20];
	int a[3];
	double h[3];
	int age, res, avg_a, i;
	double height, avg_h;
	
	ifp = fopen("1.txt", "r");
	if(ifp == NULL){
		printf("file not opened\n");
		return 1;
	}
	
	ofp = fopen("2.txt", "w");
	if(ofp == NULL){
		printf("file not opened\n");
		return 1;
	}
	
	i = 0;
	while (1){
		res = fscanf(ifp, "%s%d%lf", name, &age, &height);
		a[i] = age;
		h[i] = height;
		i++;
		if(res == EOF){
			avg_a = i_average(a);
			avg_h = h_average(h);			
			break;
		}
	
		fprintf(ofp,"%.1lf %d %s\n", height, age, name);
	}
	fprintf(ofp, "Average Height : %.1lf Average Age : %d\n", avg_h, avg_a);
	fclose(ifp);
	fclose(ofp);
	return 0;
}

int i_average (int a[]){
	int sum = 0;
	int i;
	for (i = 0; i < 3; i++){
		sum += a[i];
	}
	return sum / 3;
}

double h_average (double a[]){
	int sum = 0;
	int i;
	for (i = 0; i < 3; i++){
		sum += a[i];
	}
	return sum / (float) 3;
}
