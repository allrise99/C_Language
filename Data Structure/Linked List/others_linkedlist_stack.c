#include <stdio.h>
#include <stdlib.h>
 
 
typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;
 
typedef struct Stack //Stack 구조체 정의
{
    Node *top;    //맨 앞 노드(가장 최근에 생성한 노드)
}Stack;
 
void InitStack(Stack *stack);//스택 초기화
int IsEmpty(Stack *stack); //스택이 비었는지 확인
void Push(Stack *stack, int data); //스택에 보관
int Pop(Stack *stack); //스택에서 꺼냄
 
int main(void)
{
    int i;
    Stack stack;
 
    InitStack(&stack);//스택 초기화
    for (i = 1; i <= 5; i++)//1~5까지 스택에 보관
    {
        Push(&stack, i+10);
    }
    while (!IsEmpty(&stack))//스택이 비어있지 않다면 반복
    {
        printf("%d ", Pop(&stack));//스택에서 꺼내온 값 출력
    }
    printf("\n");
    return 0;
}
void InitStack(Stack *stack)
{
    stack->top = NULL; //스택 초기화에서는 top을 NULL로 설정
}
 
int IsEmpty(Stack *stack)
{
    return stack->top == NULL;    //top이 NULL이면 빈 상태    
}
void Push(Stack *stack, int data)
{
    Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
    now->data = data;//데이터 설정
    now->next = stack->top;//now의 next링크를 현재 top으로 설정   
    stack->top = now;   //스택의 맨 앞은 now로 설정
}
int Pop(Stack *stack)
{
    Node *now;
    int re;
    if (IsEmpty(stack))
    {
        return 0;
    }
    now = stack->top;//now를 top으로 설정
    re = now->data;//꺼낼 값은 now의 data로 설정
 
    stack->top = now->next;//top을 now의 next로 설정
    free(now);//필요없으니 메모리 해제
    return re;
}
