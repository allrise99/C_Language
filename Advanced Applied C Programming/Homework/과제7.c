/*
������ �л��� �ּ� :
  
������ �Ǵ� �� ���� ���̸� �޾� ��, ���簢��, ���ﰢ���� ���� ��鵵���� ���̸� ���ϴ� �Լ���
�� ���ư� �̵��� ��üȭ������ ����� ��, ������ü, �����ü�� ���Ǹ� ���ϴ� �ҽ������� ®���ϴ�.
������ cm�̸�, ���� �� ������ ��°��� �Ҽ��� ��° �ڸ����� ǥ���ϵ��� �߽��ϴ�. 
*/ 

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double cal_area(int a); // ���� ���ϴ� �Լ� cal_area 
double cal_volume(int a); // ���� ���ϴ� �Լ� cal_volume 
double area; // ���� ���� area
double volume; // ���� ���� volume
int i, a;

int main() {
	printf("���ϰ��� �ϴ� ������ ��ȣ�� �Է��Ͻÿ� : \n\n\t1. ��\n\t2. ���簢��\n\t3. ���ﰢ��\n\t4. ��\n\t5. ������ü\n\t6. �����ü\n");
	scanf("%d", &i);
	if(i >= 1 && i <= 6){
		printf("�ش� ������ �� �Ǵ� �������� ���̸� ������ �Է��Ͻÿ� (���� : cm) : ");
		scanf("%d", &a);
	}
	else
		printf("\n\t�������� �ʴ� ��ȣ�Դϴ�.\n");	

	if(i >= 1 && i <= 3){
		area = cal_area(a);
		printf("\n\t�ش� ������ ���̴� %.2lfcm^2�Դϴ�.\n", area);	
	}
	else if (i >= 4 && i <= 6){
		volume = cal_volume(a);
		printf("\n\t�ش� ������ ���Ǵ� %.2lfcm^3�Դϴ�.\n", volume);	
	}
		
	return 0;
}

double cal_area (int a) {
	switch (i) {
			case 1 : // ���� ���� 
				area = M_PI * a * a;
				break;
			case 2 : // ���簢���� ���� 
				area = a * a;
				break;
			case 3 : // ���ﰢ���� ���� 
				area = sqrt(3) / 4 * a * a;
				break;
			default :
				break;
		}
	return area;
}

double cal_volume (int a){
	switch (i) {
			case 4 : // ���� ���� 
				volume = M_PI * 4 / 3 * pow(a, 3);
				break;
			case 5 : // ������ü�� ���� 
				volume = pow(a, 3);
				break;
			case 6 : // �����ü�� ���� 
				volume = sqrt(2) / 12 * pow(a, 3) ;
				break;
			default :
				break;
	}
	return volume;
}
