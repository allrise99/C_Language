#include <stdio.h>

int main(){
    int a, b, c, buf;
    long long int num;
    scanf("%d %d %d", &a, &b, &c);
    num = a * b * c;   
    
    int digit[10] = {0, };
    while(1){
        buf = num % 10;
        digit[buf]++;
        num /= 10;
        if(num == 0)
        	break;
    }
    
    for (int i = 0; i < 10; i++){
        printf("%d\n", digit[i]);
    }
}
