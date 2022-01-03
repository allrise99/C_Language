#include <stdio.h>
#define LENGTH 100

int main(){
	int i, cnt1 = 0; int cnt2 = 0;
	char str[LENGTH];
	char ch; char brac1 = '('; char brac2 = '[';
	char brac3 = ')'; char brac4 = ']';
		
	scanf("%[^\n]s", str);
	for(i = 0; str[i] != '.'; i++){
		if(str[i] == brac1)
			cnt1++;
		
		if(str[i] == brac2)
			cnt2++;
				
		if(str[i] == brac3){
			if(cnt1 > 0)
				cnt1--;
			else{
				cnt1--;
				break;
			}
		}
		
		if(str[i] == brac4){
			if(cnt2 > 0)
				cnt2--;
			else{
				cnt2--;
				break;
			}		
		}
	}
	
	if(cnt1 == 0 && cnt2 == 0)
		printf("yes\n");
	else
		printf("no\n");
}
