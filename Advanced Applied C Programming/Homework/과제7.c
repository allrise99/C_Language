/*
조진우 학생의 주석 :
  
반지름 또는 한 변의 길이를 받아 원, 정사각형, 정삼각형과 같은 평면도형의 넓이를 구하는 함수와
더 나아가 이들을 입체화했을때 생기는 구, 정육면체, 정사면체의 부피를 구하는 소스파일을 짰습니다.
단위는 cm이며, 넓이 및 부피의 출력값은 소수점 둘째 자리까지 표현하도록 했습니다. 
*/ 

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double cal_area(int a); // 넓이 구하는 함수 cal_area 
double cal_volume(int a); // 부피 구하는 함수 cal_volume 
double area; // 넓이 변수 area
double volume; // 부피 변수 volume
int i, a;

int main() {
	printf("구하고자 하는 도형의 번호를 입력하시오 : \n\n\t1. 원\n\t2. 정사각형\n\t3. 정삼각형\n\t4. 구\n\t5. 정육면체\n\t6. 정사면체\n");
	scanf("%d", &i);
	if(i >= 1 && i <= 6){
		printf("해당 도형의 변 또는 반지름의 길이를 정수로 입력하시오 (단위 : cm) : ");
		scanf("%d", &a);
	}
	else
		printf("\n\t지원하지 않는 번호입니다.\n");	

	if(i >= 1 && i <= 3){
		area = cal_area(a);
		printf("\n\t해당 도형의 넓이는 %.2lfcm^2입니다.\n", area);	
	}
	else if (i >= 4 && i <= 6){
		volume = cal_volume(a);
		printf("\n\t해당 도형의 부피는 %.2lfcm^3입니다.\n", volume);	
	}
		
	return 0;
}

double cal_area (int a) {
	switch (i) {
			case 1 : // 원의 넓이 
				area = M_PI * a * a;
				break;
			case 2 : // 정사각형의 넓이 
				area = a * a;
				break;
			case 3 : // 정삼각형의 넓이 
				area = sqrt(3) / 4 * a * a;
				break;
			default :
				break;
		}
	return area;
}

double cal_volume (int a){
	switch (i) {
			case 4 : // 구의 부피 
				volume = M_PI * 4 / 3 * pow(a, 3);
				break;
			case 5 : // 정육면체의 부피 
				volume = pow(a, 3);
				break;
			case 6 : // 정사면체의 부피 
				volume = sqrt(2) / 12 * pow(a, 3) ;
				break;
			default :
				break;
	}
	return volume;
}
