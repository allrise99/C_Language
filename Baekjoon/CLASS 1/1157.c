#include <stdio.h>

int main(){
	int i;
	char ch;
	int cnt[26] = {0, };
	char str[1000001];
	scanf("%s", str);
	
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= 32;
		}
		cnt[str[i]-65]++;
	}
		
	int max = 0;
	for (i = 0; i < 26; i++){
		if(max < cnt[i]){
			max = cnt[i];
			ch = i+65;
		}
		
		else if(max == cnt[i] && cnt[i] != 0){
			ch = '?';
		}
	}
	
	printf("%c", ch);
	
	return 0;
}

/* 
ó�� �����ϴ� for���� �׳� strlen �Ἥ �Ϸ��� 
�ð� �ʰ��� ���� �ٸ� ��� �ڵ� ����
string.h ���� str[i] != '\0'���� �ٲٴ� ����..
*/ 
