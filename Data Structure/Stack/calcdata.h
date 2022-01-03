#ifndef CALC_DATA_H // 해당 헤더파일이 정의 안되어있으면
#define CALC_DATA_H // 매크로 정의

typedef struct _CALC_DATA {
	int operand1;
	int operand2;
	char operator;
	int result;
}CALC_DATA;

#endif