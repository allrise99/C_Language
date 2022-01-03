#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int secToHours(long long int time, int *hours, int *minutes, int *seconds);

int main(){
	printf("Please, input TIME in seconds : ");
	long long int time;
	int days, hours, minutes, seconds;
	int temp;
	scanf("%lld", &time);

	temp = secToHours(time, &hours, &minutes, &seconds);
	if(temp == 1){
		days = hours / 24; 
		hours = hours % 24;
		printf("\n\n�Է��� %lld�ʴ� %d�� %d�ð� %d�� %d���Դϴ�.", time, days, hours, minutes, seconds); 
	}
	else {
		printf("\n\n�Է��� %lld�ʴ� %d�ð� %d�� %d���Դϴ�.", time, hours, minutes, seconds); 
	}
	return 0;
}

int secToHours(long long int time, int *hours, int *minutes, int *seconds){
	long long int localTime;
	
	localTime = time;
	*seconds = localTime % 60;
	localTime = localTime / 60;
	
	*minutes = localTime % 60;
	
	*hours = localTime / 60;
	
	if(*hours >= 24)
		return 1;
	else 
		return 0;
}
