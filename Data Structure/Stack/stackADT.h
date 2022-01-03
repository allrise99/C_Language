#ifndef STACKADT_H //��� ���� �ߺ� ����
#define STACKADT_H // ��� ���� ����

#include <stdbool.h> // boolean type ����
typedef int Item; // int Ÿ�� Item���� ����
typedef struct stack_type* Stack; // ����ü stack_type�� ������ Stack ����

Stack create(); // Stack ����
void destroy(Stack s); 
void make_empty(Stack s); // ���� ����
bool is_empty(Stack s); // ���� ������� Ȯ��
void push(Stack s, Item i); // Item i�� ���ÿ� push
Item pop(Stack s); 
Item peek(Stack s);

#endif // ����