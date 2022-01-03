#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	if(*(int *)a > *(int *)b)
		return 1;
	if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

typedef struct person{
	int age;
	char name[101];
} person;


int main(){
	int i, n;
	person p[100000];
	// person *ptr = &p;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %s", &p[i].age, p[i].name);
	}
	/*
	qsort(ptr, n, sizeof(p), compare);
	*/
	for(i = 0; i < n; i++)
		printf("%d %s", p[i].age, p[i].name);
}
