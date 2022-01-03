#include <stdio.h>

int main() {
	int a;
	int ndigit[10] = { 0, }; 
	int space = 0; // 빈칸, 줄바꿈, 탭 입력할 때의 변수 space 
	int other = 0; // 나머지 그 이외의 문자 입력할때의 변수 other 
		
	while (a = getchar())
	{
		if (a == 'E')  // Sentinel Value 'E' 설정 
			break;
		
		if (a >= '0' && a <= '9') 
			++ndigit[a - 48]; // 0의 ASCII 코드 : 48
		else { 
			if (a == ' ' || a == '\n' || a == '\t')
				++space; 
			else 
				++other;
		}
	}
	
	printf("\t# of each digit : ");
	int i;
	for(i = 0; i < 10; i++){
		printf("\n\tndigit[%d] = %d", i, ndigit[i]);
 	}
	printf("\n\n\twhite space= %d, other= %d\n", space, other);
	
	return 0;
}
