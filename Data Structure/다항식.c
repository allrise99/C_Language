#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 10
#

struct term {
	int coef; // ��� 
	int expo; // ���� 
	struct term *next; // ���� ��� ���� 
};
typedef struct term Term;

typedef struct polynomial{
	char name; // �̸� ex. f, g 
	Term *first; // ���׽��� �����ϴ� ù��° ����� �ּ� 
	int size; // �Լ��� ũ�� 
} Polynomial;

Polynomial *poly[MAX_POLYS]; // polys�� ���׽ĵ鿡 ���� �������� �迭 
int n = 0; // ����� ���׽� ���� 

Term *create_term_instance{ //���ο� �� ����� 
	Term *t = (Term *)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

Polynomial *create_polynomial_instance(char name){ // ���ο� �Լ� ���� 
	Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial *body){  // cx^e �߰� 
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













