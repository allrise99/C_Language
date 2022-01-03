#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Info {
	char name[10];
	int id;
	float cgpa;
	int sem;
};

struct Apply{
	char univ[100];
	int toefl;
};

typedef struct {
	struct Info info;
	struct Apply apply;
} student;

int filecheck(FILE *p);

int main(){
	int s_num, res, i, menu, count, check;
	FILE *ifp, *ofp;
	
	printf("서강대학교 교환학생 조회 및 선정 프로그램입니다\n");
	printf("1. 교환학생 신청자 수 조회 2. 교환학생 선발 결과\n"); 
	printf("원하시는 정보의 번호를 입력해주세요 : ");
	scanf("%d", &menu);

	ifp = fopen("input.txt", "r");
	filecheck(ifp);
	ofp = fopen("output.txt", "w");
	filecheck(ofp);
	
	fscanf(ifp, "%d", &s_num);
	student *ps = malloc(sizeof(student) * s_num);
    i = 0;
	while(1){
		res = fscanf(ifp, "%49[^;]%*c%s%d%d%f%d", ps[i].apply.univ, ps[i].info.name, 
        &ps[i].info.id, &ps[i].info.sem, &ps[i].info.cgpa, &ps[i].apply.toefl);
		if(res == EOF)
			break;
		++i;
	}

	switch(menu){
		case 1 :
			count = 0;
            char temp[50];
            printf("\n\n지원자 수를 알고자 하는 대학 이름을 세미 콜론과 함께 입력하세요 : \n");
            printf("ex. Berlin 1960 University;\n");
            scanf("%[^;]s", temp);
            
            for (i = 0; i < s_num; i++){
            	check = strcmp(temp, ps[i].apply.univ);
            	if(check == 0)
                	count++;
			}
            fprintf(ofp, "%s에 지원한 사람은 %d명입니다.\n", temp, count);
            fprintf(stdout, "\n%s에 지원한 사람은 %d명입니다.\n", temp, count);
			break;
			
		case 2 :		
			fprintf(ofp, "선발 결과 : \n\n");
			fprintf(ofp, "학번\t 이름\t학기수  학점\tTOEFL\n\n");
			fprintf(stdout, "\n\n선발 결과 : \n\n");
			fprintf(stdout, "학번\t 이름\t학기수  학점\tTOEFL\n\n");
			for (i = 0; i < s_num; i++){
				if(ps[i].info.sem >= 2 && ps[i].info.sem <= 7){
					if(ps[i].info.cgpa >= 2.70){
						if(ps[i].apply.toefl >= 79){
							fprintf(ofp, "%8d %s\t%3d \t%-8.2f%3d\n", ps[i].info.id, ps[i].info.name, 
							ps[i].info.sem, ps[i].info.cgpa, ps[i].apply.toefl);
							fprintf(stdout, "%8d %s\t%3d \t%-8.2f%3d\n", ps[i].info.id, ps[i].info.name, 
							ps[i].info.sem, ps[i].info.cgpa, ps[i].apply.toefl);
						}
					}
				}
			}
			break;
		
		default : 
			printf("\n지원하지 않는 기능입니다\n");
			break;
	}
	free(ps);
	fclose(ifp);
	fclose(ofp);
	return 0;
}

int filecheck(FILE *p){
	if(p == NULL){
		printf("file not opened!\n");
		return 1;
	}
}
