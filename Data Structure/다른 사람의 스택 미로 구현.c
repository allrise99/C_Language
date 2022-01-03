#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 
#define MAZE_SIZE 5 

typedef struct Pos{ 
    short x; 
    short y; 
}Pos;

typedef struct Stack{ 
    Pos data[MAX_SIZE];
    int top;
}Stack;

char maze[MAZE_SIZE][MAZE_SIZE]={{'1','1','1','1','1'}, 
                                 {'e','0','1','0','1'}, 
                                 {'1','0','0','0','1'}, 
                                 {'1','1','1','0','x'}, 
                                 {'1','1','1','1','1'}}; 

void Init(Stack *p){ 
    p->top = -1;
}

int Is_full(Stack *p){ 
    return (p->top == MAX_SIZE-1);
}

int Is_empty(Stack *p){
    return (p->top == -1); 
}

void Push(Stack *p, Pos data){ 
    if(Is_full(p)){ 
        printf("������ ��á���ϴ�\n"); return ; 
    } 
    else { 
        p->top++; 
        p->data[p->top].x=data.x; 
        p->data[p->top].y=data.y;  
    }
} 

Pos Pop(Stack *p) { 
    if(Is_empty(p)) { 
        printf("������ ����ֽ��ϴ�\n");  
        exit(1); 
    }
     
    return p->data[(p->top)--]; 
} 

void Push_Loc(Stack *s, int x, int y){ 
    if(x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) return;  

    if(maze[x][y] != '1' && maze[x][y] != '.') { 
        Pos tmp; 
        tmp.x=x; 
        tmp.y=y; 


        Push(s,tmp); 
    }
}

int main() 
{ 
    Stack s; 
    Pos here; 
    int i, j, x, y;

    Init(&s); 

    // ������ Ž�� 
    for(i=0; i<MAZE_SIZE; i++){ 
        for(j=0; j<MAZE_SIZE; j++){
            if(maze[i][j]=='e'){
                here.x=i;
                here.y=j;
            }
        }
    }

    printf("������ (%d,%d) \n",here.x,here.y); 

    while(maze[here.x][here.y] != 'x') 
    {
        x=here.x; 
        y=here.y; 

        maze[x][y]='.'; // �湮�� ���� ǥ�� 

        // ��,��,��,�Ʒ��� �̵� ������ ���� Ž�� 
        Push_Loc(&s,x+1,y);  
        Push_Loc(&s,x-1,y); 
        Push_Loc(&s,x,y+1); 
        Push_Loc(&s,x,y-1); 
         
        if(Is_empty(&s)) {
            printf("����\n"); 
            return 0; 
        } 
        else { 
            here=Pop(&s); // ���� ��ǥ�� ���� 
            printf("(%d,%d)\n",here.x,here.y); 
        }
    }

    printf("���� �� (%d,%d)\n",here.x,here.y); 
    printf("Ž�� ����\n"); 

    return 0; 
}
