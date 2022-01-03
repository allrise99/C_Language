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
		printf("\n\n입력한 %lld초는 %d일 %d시간 %d분 %d초입니다.", time, days, hours, minutes, seconds); 
	}
	else {
		printf("\n\n입력한 %lld초는 %d시간 %d분 %d초입니다.", time, hours, minutes, seconds); 
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
