#include <stdio.h>

int main() {
	int a;
	int ndigit[10] = { 0, }; 
	int space = 0; // ��ĭ, �ٹٲ�, �� �Է��� ���� ���� space 
	int other = 0; // ������ �� �̿��� ���� �Է��Ҷ��� ���� other 
		
	while (a = getchar())
	{
		if (a == 'E')  // Sentinel Value 'E' ���� 
			break;
		
		if (a >= '0' && a <= '9') 
			++ndigit[a - 48]; // 0�� ASCII �ڵ� : 48
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
