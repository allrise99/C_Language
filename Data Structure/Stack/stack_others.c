/*
1. 스택을 구현할 배열 생성
2. 스택 상태를 나타낼 함수
3. 원소를 넣는 함수
4. 원소를 제거하는 함수
5. 스택의 맨 위 원소 알아내는 함수
6. 스택의 원소를 출력할 함수 
*/

#include <stdio.h>
#define SIZE 5

char stack[SIZE]; // 사이즈 5인 배열 생성 (스택용)
int top = -1; // 맨 위 값을 나타낼 top 변수 생성

// 2. 스택 상태를 나타낼 함수
int isFull() {
	if (top >= SIZE - 1) { // ex. size = 1 top = 0 -> full
		printf("Error : Stack is FULL\n.");
		return 1; // 1 반환
	}
	return 0;
}

// 2-1. 스택 비었는지 검사하는 함수
int isEmpty() {
	if (top == -1) {
		printf("Error : Stack is empty.\n");
		return 1;
	}
	return 0;
}

// 3. 원소를 넣는 함수 (push)
void push(char data) { // 문자형 자료 data를 스택에 push
	if (!isFull()) {
		top++; // top 하나 증가시키고 해당 배열 칸에 data 문자 넣어줌
		stack[top] = data;
	}
}

// 4. 원소를 제거하는 함수 (pop)
char pop() {
	if (!isEmpty()) {
		char temp = stack[top]; // top의 스택을 temp에 옮겨 놓음
		top--;
		return temp;
	}
}

// 5. 스택의 맨 위 원소 알아내는 함수 (peek)
char peek() {
	if (!isEmpty()) {
		return stack[top];
	}
}

// 6. 스택의 원소를 출력할 함수 (printStack)
void printStack() {
	if (!isEmpty()) {
		for (int i = 0; i <= top; i++) {
			printf("%c ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	printStack();
	push('a');
	push('b');
	push('c');
	printStack();
	pop(); // c pop
	push('d');
	push('e');
	push('f');
	printStack(); // a b d e f
	pop(); // e pop
	pop(); // f pop
	printStack(); //a b d
}