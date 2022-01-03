#include <stdio.h>

int main(){
	int i;
	char str[101];
	int alpha[26];
	for(i = 0; i < 26; i++)
		alpha[i] = -1;
	
	scanf("%s", str);
		
	for(i = 0; str[i] != '\0'; i++){
		if(alpha[str[i]-97] != -1)
			continue;
		alpha[str[i]-97] = i;
		
	}
	
	for(i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
}
