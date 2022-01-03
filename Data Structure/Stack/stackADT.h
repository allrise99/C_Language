#ifndef STACKADT_H //헤더 파일 중복 방지
#define STACKADT_H // 헤더 파일 정의

#include <stdbool.h> // boolean type 정의
typedef int Item; // int 타입 Item으로 정의
typedef struct stack_type* Stack; // 구조체 stack_type의 포인터 Stack 정의

Stack create(); // Stack 생성
void destroy(Stack s); 
void make_empty(Stack s); // 스택 비우기
bool is_empty(Stack s); // 스택 비었는지 확인
void push(Stack s, Item i); // Item i를 스택에 push
Item pop(Stack s); 
Item peek(Stack s);

#endif // 종료