#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 10
#

struct term {
	int coef; // 계수 
	int expo; // 지수 
	struct term *next; // 다음 노드 저장 
};
typedef struct term Term;

typedef struct polynomial{
	char name; // 이름 ex. f, g 
	Term *first; // 다항식을 구성하는 첫번째 요소의 주소 
	int size; // 함수의 크기 
} Polynomial;

Polynomial *poly[MAX_POLYS]; // polys는 다항식들에 대한 포인터의 배열 
int n = 0; // 저장된 다항식 개수 

Term *create_term_instance{ //새로운 항 만들기 
	Term *t = (Term *)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

Polynomial *create_polynomial_instance(char name){ // 새로운 함수 생성 
	Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial *body){  // cx^e 추가 
	if(c == 0)
		return;
	Term *p = poly->first, *q = NULL;
	while(p != NULL && p->expo > e){
		q = p;
		p = p->next;
	}
	if(p != NULL && p->expo == e){
		if(q == NULL)
			poly->first = p->next;
	}
}


int main(){
	
}













