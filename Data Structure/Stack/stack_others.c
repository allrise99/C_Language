/*
1. ������ ������ �迭 ����
2. ���� ���¸� ��Ÿ�� �Լ�
3. ���Ҹ� �ִ� �Լ�
4. ���Ҹ� �����ϴ� �Լ�
5. ������ �� �� ���� �˾Ƴ��� �Լ�
6. ������ ���Ҹ� ����� �Լ� 
*/

#include <stdio.h>
#define SIZE 5

char stack[SIZE]; // ������ 5�� �迭 ���� (���ÿ�)
int top = -1; // �� �� ���� ��Ÿ�� top ���� ����

// 2. ���� ���¸� ��Ÿ�� �Լ�
int isFull() {
	if (top >= SIZE - 1) { // ex. size = 1 top = 0 -> full
		printf("Error : Stack is FULL\n.");
		return 1; // 1 ��ȯ
	}
	return 0;
}

// 2-1. ���� ������� �˻��ϴ� �Լ�
int isEmpty() {
	if (top == -1) {
		printf("Error : Stack is empty.\n");
		return 1;
	}
	return 0;
}

// 3. ���Ҹ� �ִ� �Լ� (push)
void push(char data) { // ������ �ڷ� data�� ���ÿ� push
	if (!isFull()) {
		top++; // top �ϳ� ������Ű�� �ش� �迭 ĭ�� data ���� �־���
		stack[top] = data;
	}
}

// 4. ���Ҹ� �����ϴ� �Լ� (pop)
char pop() {
	if (!isEmpty()) {
		char temp = stack[top]; // top�� ������ temp�� �Ű� ����
		top--;
		return temp;
	}
}

// 5. ������ �� �� ���� �˾Ƴ��� �Լ� (peek)
char peek() {
	if (!isEmpty()) {
		return stack[top];
	}
}

// 6. ������ ���Ҹ� ����� �Լ� (printStack)
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