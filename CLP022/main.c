#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



typedef struct{
	char* stuName;
	char* stuCode;
	char* stuDob;
	double stuScore;
}Student;

Student* createStudent(char* name,char* code,char * dob,double score){
	
	Student* oneStudent;
	oneStudent = malloc(sizeof(Student));
	oneStudent -> stuName = strdup(name);
	oneStudent -> stuCode = strdup(code);//Phai strdup neu khong con tro name sau khi ra khoi ham addStudent se mat va gia tri o vi tri do se mat di
	oneStudent -> stuDob = strdup(dob);
	oneStudent -> stuScore = score;
	return oneStudent;
}


void addStudent(Student** studentList,int* length){
	char name[50];
	char code[50];
	char dob[50];
	double score;
	char *name1,*code1,*dob1;

	int exit;
	do{
		fflush(stdin);
		printf("Enter new student: \n");
		printf("Student code: ");
		fflush(stdin);
		scanf("%s",&code);
		printf("Student name: ");
		fflush(stdin);
		gets(name);
		printf("Day of Birth: ");
		fflush(stdin);
		scanf("%s",&dob);
		printf("Learning point: ");
		fflush(stdin);
		scanf("%lf",&score);
		name1 = (char* ) malloc(strlen(name)*sizeof(char));
		code1 = (char* ) malloc(strlen(code)*sizeof(char));
		dob1 = (char* ) malloc(strlen(dob)*sizeof(char));
		name1=name;
		code1=code;
		dob1= dob;
		studentList[*length] = createStudent(name1,code1,dob1,score);
		(*length)++;
		printf("Press enter to continue. Esc to return menu\n");
		fflush(stdin);
		exit = getchar();

	}while(exit!='=');

}

void writeDataToFile(Student** studentList,int length){
	FILE *f = fopen("data.txt","a");
	for (int i = 0; i < length; ++i)
	{
		fprintf(f, "#%s;%s;%s;%lf\n", studentList[i]->stuName, studentList[i]->stuCode, studentList[i]->stuDob, studentList[i]->stuScore);
	}
	fclose(f);
}

void readFile(Student** studentList,int* length){
	FILE *f =fopen("data.txt","r");
	char name[50];
	char code[50];
	char dob[50];
	double score;
	int i =0;
	while(fscanf(f,"#%50[^;];%50[^;];%50[^;];%lf\n",&name,&code,&dob,&score)==4){
		studentList[i] = createStudent(name,code,dob,score);
		i++;
	}
	*length = i;
	fclose(f);
}

void printList(Student** studentList,int length){
	char *name,*code,*dob;
	double score;
	for (int i = 0; i < length; ++i)
	{
		printf("Student %d\n",i+1);
		name = studentList[i]->stuName;
		code = studentList[i]->stuCode;
		dob = studentList[i]->stuDob;
		score = studentList[i]->stuScore;
			
		printf("Code: %10s| Name: %10s| DOB: %10s| Score: %5.2lf|\n",name,code,dob,score );
	}
	
}

void searchStudent(Student** studentList,int length){
	char searchName[50];
	printf("Please enter student name: ");
	fflush(stdin);
	gets(searchName);
	int index = -1;
	for (int i = 0; i < length; ++i)
	{
		char *name = studentList[i] -> stuName;
		if(strstr(name,searchName)){
			index = i;
			break;
		}
	}

	if(index>=0){
		printf("Student Code: %s\n", studentList[index] -> stuCode);
	printf("Student Name: %s\n", studentList[index] -> stuName);
	printf("Student DOB: %s\n", studentList[index] -> stuDob);
	printf("Student Score: %.2lf\n", studentList[index] -> stuScore);
	}else{
		printf("Cann't find student %s\n",searchName );
	}
	
}

void sortList(Student** studentList,int length){
	
	for (int i = 0; i < length -1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			char* name = studentList[j]->stuName;
			char* name1= studentList[j+1]->stuName;
			if(strcmp(name,name1)>0){
				Student* temp;
				temp = studentList[j];
				studentList[j] = studentList[j+1];
				studentList[j+1]=temp;
			}
		}
	}
}


void menu(){
	Student** studentList;
	studentList = malloc (100*sizeof(Student*));
	int length = 0;
	int userChoice;
	int x;

	// readFile(studentList,&length);
	// sortList(studentList,length);
	do{
		
		printf("1. Enter student list\n");
		printf("2. Look up student\n");
		printf("3. Display student list\n");
		printf("4. Exit\n");
		fflush(stdin);
		x = scanf("%d",&userChoice);
		switch(userChoice){
			case 1: 
				addStudent(studentList,&length);
				break;
			case 2:
				searchStudent(studentList,length);
				break;
			case 3:
				printList(studentList,length);
				break;	
			case 4:
				sortList(studentList,length);
				writeDataToFile(studentList,length);
				break;		
		}

	}while(x==0 || userChoice> 4 || userChoice!=4 || userChoice<1);

	free(studentList);
	// printList(studentList,length);
	// sortList(studentList,length);
	// printList(studentList,length);
	// writeDataToFile(studentList,length);

	// readFile(studentList,&length);
	// printList(studentList,length);
	// sortList(studentList,length);
	// printList(studentList,length);
}

int main(int argc, char const *argv[])
{
	
	//menu
	menu();
	return 0;
}

