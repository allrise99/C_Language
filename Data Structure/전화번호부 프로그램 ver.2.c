#include <stdio.h>
#include <string.h>
#define CAPACITY 100
#define BUFFER_SIZE 20

char *names [CAPACITY];
char *numbers [CAPACITY];
int n = 0;

void load();
void add();
void find();
void status();
void removes();
void save();

int main(){
	char command[BUFFER_SIZE];
	while(1){
		printf("$ ");
		scanf("%s", command);
		if(strcmp(command, "read") == 0)
			load();
		else if(strcmp(command, "add") == 0)
			add();
		else if(strcmp(command, "find") == 0)
			find();
		else if(strcmp(command, "status") == 0)
			status();
		else if(strcmp(command, "delete") == 0)
			removes();
		else if(strcmp(command, "save") == 0)
			save();	
		else if(strcmp(command, "exit") == 0)
			break;		
	}
	return 0;
}

// read dirctory.txt


void load(){
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];
	
	scanf("%s", fileName);
	FILE *fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("open failed\n");
		return;
	}
	
	while((fscanf(fp, "%s", buf1) != EOF)){
		fscanf(fp, "%s", buf2);
		names[n] = strdup(buf1);
		numbers[n] = strdup(buf2);
		n++;
	}
	fclose(fp);
}

// save as directory.txt

void save(){
	int i;
	char fileName[BUFFER_SIZE];
	char temp[BUFFER_SIZE];
	scanf("%s", temp);
	scanf("%s", fileName);
	
	FILE *fp = fopen(filename, "w");
	if(fp == NULL){
		printf("file not opened.\n");
		return;
	}
	for (int i = 0; i < n; i++){
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
}

// add James 0120321456, 이때 정렬해줘야 함 

void add(){
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);
	
	int i = n-1;  // 4
	 // 앞에 문자열이 크면 양수 반환
	while(i > 0 && strcmp(names[i], buf1) > 0){
		names[i+1] = names[i]; // 
		numbers[i+1] = numbers[i]; 
		i--;
	}
	names[i+1] = strdup(buf1);	
}

// find John
void find(){
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	for (int i = 0; i < n; i++)
		if(strcmp(buf, names[i]) == 0){
			printf("%s\n", numbers[i]);
			return;
		}
	printf("no person named '%s' exists.\n", buf);
}

void status(){
	int i;
	for (i = 0; i < n; i++)
		printf("%s	%s\n", names[i], numbers[i]);
	printf("Total %d person.\n", n);
	return;
}

int search(char *name){
	int i;
	for (i = 0; i < n; i++){
		if(strcmp(name, names[i]) == 0)
			return i; // 몇번째에 저장되었는지 그 순번을 보내줌 
	}
	return -1;
}

void removes(){
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	
	int index = search(buf);
	if(index == -1){
		printf("no person named '%s' exists.\n", buf);
		return;
	}
	
	int j = index; // 아까 받은 j번째 
 	for (; j < n-1; j++){
		names[j] = names[j+1];
		numbers[j] = numbers[j+1];
	}
	n--;
	printf("'%s' was deleted successfully.\n");
}
