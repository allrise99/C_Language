#include "calc.h" // add, sub �Լ� �̿� (calcdata���� ����ü�� �������)
#include "print.h" // print �Լ� �̿�

int main() {
	CALC_DATA data1;
	data1.operand1 = 10;
	data1.operand2 = 20;

	add(&data1);
	printf(&data1);

	CALC_DATA data2;
	data2.operand1 = 40;
	data2.operand2 = 15;

	sub(&data2);
	printf(&data2);
}