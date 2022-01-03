/*
실행 예시
$ add Hong   Gil-Dong
  Phone : 0101132456
  Email :
  Group : Friend
Hong Gil-Dong was added successfully.

$ find Hong Gil-Dong
Hong Gil-Dong :
	Phone : 010123456
	Email : 
	Group : Friend
	
$ save as directory.txt
$ exit

David K. #012341546# #Friend#
John Doe# # # #
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAPACITY 100
#define BUFFER_LENGTH 20

typedef struct person{
	char *name;
	char *number;
	char *email;
	char *group;
} Person;

Person directroy[CAPACITY];

int n = 0;
void add(char *name, char *number, char *email, char *group);



int main(){
	char command_line[BUFFER_LENGTH];
	char *command, *argument;
	char name_str[BUFFER_LENGTH];
	
	while(1){
		printf("$ ");
		if(read_line(stdin, command_line, BUFFER_LENGTH)<=0) 
		// 사용자가 아무것도 입력하지 않으면 다음 $ 출력 
			continue;
	
		command = strtok(command_line, " ");
		// command_line 에서 처음 읽어 드린 token을 command에 입력 
		// ex. $ read directory.txt
		if(strcmp(command, "read") == 0){
			argument = strtok(NULL, " ");
			if(argument == NULL){
				printf("Invalid arguments.\n");
				continue;
			}
			load(argument);
		}
		
		else if(strcmp(command, "add") == 0){
			if(compose_name(name_str, BUFFER_LENGTH) <= 0){
				printf("name required.\n");
				continue;
			}
			handle_add(name_str);
		}
		
		else if(strcmp(command, "find") == 0){
			if(compose_name(name_str, BUFFER_LENGTH) <= 0){
				printf("name required.\n");
				continue;
			}
			find(name_str);
		}
		
		else if(strcmp(command, "save") == 0){
			argument = strtok(NULL, " ");
			if(strcmp(argument, "as") != 0){
				printf("invalid arguments.\n");
				continue;
			}
			argument = strtok(NULL, " ");
			if(argument == NULL){
				printf("invalud arguments.\n");
				continue;
			}
			save(argument);
		}
		else if(strcmp(command, "exit") == 0)
			break;		
	}
		
	return 0;
}


int read_line(FILE *fp, char str[], int n){
	int ch, i = 0;
	while((ch = fgetc(fp) != '\n') && ch != EOF){ // 파일 읽어드릴 때 파일 끝이면 루프 끝! 
		if (i < n)
			str[i++] = ch; // str 배열에 파일에서 입력 받은 것을 하나씩 입력함 
	}
	str[i] = '\0';
	return i;
}

// read dirctory.txt
void load(char *filename){
	char buffer[BUFFER_LENGTH];
	char *name, *number, *email, *group;
		
	FILE *fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Open failed.\n");
		return;
	}
	
	while(1){
		if(read_line(fp, buffer, BUFFER_LENGTH) <= 0)
			break;
		name = strtok(buffer,"#");
		number = strtok(NULL, "#");
		email = strtok(NULL, "#");
		group = strtok(NULL, "#");
		add(name, number, email, group);
	}
	
	fclose(fp);	
}

void add(char *name, char *number, char *email, char *group){
	int i = n-1;
	while(i > 0 && strcmp(directory[i].name, name) > 0){
		directory[i+1] = directory[i]; // 배열 한 요소만 조정해주면 알아서 세부 요소들이 움직임
		i--; 
	}
	directory[i+1].name = strdup(name); // while 문으로 움직여 주었으면 이제 넣어줌 
	directory[i+1].number = strdup(number);
	directory[i+1].email = strdup(email);
	directory[i+1].group = strdup(group);
	n++;
}

int compose_name(char str[], int limit){
	// 사람 이름의 길이를 반환해줌 
	char *ptr;
	int length = 0;
	
	ptr = strtok(NULL, " ");
	// 이름의 첫번쨰 단어 ex. 'John' Doe 
	if(ptr == NULL)
		return 0;
	
	strcpy(str, ptr);
	length += strlen(ptr); 
	
	while((ptr = strtok(NULL, " ")) != NULL){
		if(length + strlen(ptr) + 1 < limit){
			str[length++] = ' ';
			str[length] = '\0';
			strcat(str, ptr);
			length += strlen(ptr);
		}
	}
	return length;	
}

void handle_add(char *name){
	char number[BUFFER_LENGTH], email[BUFFER_LENGTH], group[BUFFER_LENGTH];
	char empty[] = " ";
	
	printf("  Phone : ");
	read_line(stdin, number, BUFFER_LENGTH);
	
	printf("  Email : ");
	read_line(stdin, email, BUFFER_LENGTH);
	
	printf("  Group : ");
	read_line(stdin, group, BUFFER_LENGTH);
	
	add(name, (char *)(strlen(number)>0 ? number : empty), 
     		  (char *)(strlen(email)>0 ? email : empty), 
     		  (char *)(strlen(group)>0 ? group : empty));
}

void save(char *filename) {
	int i;
	FILE *fp = fopen(filename, "w");
	if(fp == NULL){
		printf("open failed.\n");
		return;
	}
	
	for (i = 0; i < n; i++){
		fprintf(fp, "%s#", directory[i].name);
		fprintf(fp, "%s#", directory[i].number);
		fprintf(fp, "%s#", directory[i].email);
		fprintf(fp, "%s#\n", directory[i].group);
	}
	fclose(fp);
}

int search(char *name){
	int i;
	for (i = 0; i < n; i++){
		if(strcmp(name, directory[i].name) == 0)
			return i;
	}
	return -1;
}

void print_person(Person p){
	printf("%s: \n", p.name);
	printf("   Phone : %s\n", p.number);
	printf("   Email : %s\n", p.email);
	printf("   Group : %s\n", p.group);
}

void remove(char *name){
	int i = search(name);
	if(i == -1){
		printf("no person named '%s' exists.\n", name);
		return;
	}
	
	int j = i;
	for (; j< n-1; j++){
		directory[j] = directory[j+1];
	}
	n--;
	printf("'%s' was deleted successfully.\n", name);
}

void status(){
	int i;
	for (i = 0; i < n; i++)
		print_person(directory[i]);
	printf("Total %d persons.\n", n);
}

void find(char *name){
	int index = search(name);
	if(index == -1)
		printf("no person named '%s' exists.\n", name);
	else
		print_person(directory[index]);
}
