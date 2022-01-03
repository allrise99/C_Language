#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INIT_CAPACITY 3
#define BUFFER_SIZE 50

char **names;
char **numbers;
int capacity = INIT_CAPACITY;
int n = 0;

char delim[] = " ";

int main(){
	init_directory();
	process_command();
	
	return 0;
}

void init_directory(){
	names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
	numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}


int read_line (char str[], int limit){
	int ch, i = 0;
	while(ch = getchar() != '\n')
		if(i < limit-1)
			str[i++] = ch;
	str[i] = '\0';		
	return i;
	// 읽은 문자의 갯수 반환함 
}

void process_command(){
	char command_line[BUFFER_SIZE];
	char *command, *arg1, *arg2;
	
	while(1) {
		printf("$ ");
		if(read_line(command_line, BUFFER_SIZE) <= 0)
			continue;
		
		command = strtok(command_line, delim);
		if(command == NULL) continue;
		
		if(strcmp(command, "read") == 0){
			arg1 = strtok(NULL, delim);
			if(arg1 == NULL){
				printf("file name required.\n");
				continue;
			}
			load(arg1);
		}
		
		else if(strcmp(command, "add") == 0){
			arg1 = strtok(NULL, delim);
			arg2 = strtok(NULL, delim);
			
			if(arg1 == NULL || arg2 == NULL){
				printf("Invalid arguments.\n");
				continue;
			}
			add(arg1, arg2);
			printf("%s was saved successfully.\n", arg1);
		}
		
		else if(strcmp(command, "save") == 0){
			arg1 = strtok(NULL, delim);
			arg2 = strtok(NULL, delim);
			
			if(arg1 == NULL || strcmp("as", arg1) != 0 || arg2 == NULL){
				printf("Invalid command format.\n");
				continue;
			}
			save(arg2);
		}
		else if(strcmp(command, "exit") == 0)
			break;
	}
}


void load(char *filename){
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];

	FILE *fp = fopen(filename, "r");
	if(fp == NULL){
		printf("file not opened\n");
		return;
	}
	while (fscanf(fp, "%s", buf1) != EOF){
		fscanf(fp, "%s", buf2);
		add(buf1, buf2);
	}
	fclose(fp);
}


void add(char *name, char *number){
	if(n >= capacity)
		reallocate();
	
	int i = n-1;
	
	while(i > 0 && strcmp(names[i], name) > 0){
		names[i+1] = names[i];
		numbers[i+1] = numbers[i];
		i--;
	}
	
	names[i+1] = strdup(name);
	numbers[i+1] = strdup(number);
	n++;
}

void reallocate(){
	int i;
	capacity *= 2;
	char **temp1 = (char **)malloc(capacity*sizeof(char *));
	char **temp2 = (char **)malloc(capacity*sizeof(char *));
	
	for (i = 0; i < n; i++){
		temp1[i] = names[i];
		temp2[i] = numbers[i];
	}
	free(names);
	free(numbers);
	
	names = temp1;
	numbers = temp2;
}


void find(){
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	for (int i = 0; i < n; i++){
		if(strcmp(names[i],buf) == 0){
			printf("%s", numbers[i]);
			return;
		}
	}
	printf("%s not found.\n", buf);
}

void status(){
	for (int i = 0; i < n; i++){
		printf("%s %s\n", names[i], numbers[i]);
	}
	printf("total %d person.\n", n);
	return;
}

int search(char *name){
	for (int i = 0; i < n; i++){
		if(strcmp(names[i], name) == 0)
			return i;
	}
	return -1;
}

//$ delete anderson
void removes(){
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	
	int index = search(buf);
	if(index == -1){
		printf("no person named %s exists.\n", buf);
		return;
	}
	int j = index;
	for (; j < n-1; j++){ // ???? ????? ???? ??? ?!! 
		names[j] = names[j+1];
		numbers[j] = numbers[j+1];
	}
	n--;
	printf("%s deleted successfully.\n", buf);
	return;
}

//$ save as directory.txt
void save(){
	char temp[BUFFER_SIZE];
	char filename[BUFFER_SIZE];
	scanf("%s", temp);
	scanf("%s", filename);

	FILE *fp = fopen(fp, "%s", "w");
	if(fp == NULL){
		printf("not opened.\n");
		return;
	}
	for (int i = 0; i < n; i++){
		fprintf(filename, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
	return;	
}
