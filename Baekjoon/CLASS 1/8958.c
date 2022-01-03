#include <stdio.h>
#include <string.h>

int main(){
    char buf[81];
    int i, j, n;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        int sum = 0;
        int add = 1;
        scanf("%s", buf);
        
        for (j = 0; j < strlen(buf); j++){
            if(buf[j] == 'O'){
                sum += add; 
                add++;
            }
            else
            	add = 1;                
        }
        printf("%d\n", sum);
    }    
}
