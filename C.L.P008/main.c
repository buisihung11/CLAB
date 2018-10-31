#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define INC_STEP 100
#define MAX_LENGTH_WORD 30
#define FILE_NAME "textmsg.txt"

char ** getDataFromFile(FILE* f,int* length){
	
	long numberOfWord = 0;
	
	//alocate chunk of memoruy
	char ** source = NULL;
	char buf[MAX_LENGTH_WORD];
	int i = 0;
	int step = 0;
	int track;
	char temp;
	fscanf(f,"%d",&track);
	printf("Track %d\n",track );

	while(fgets(buf,MAX_LENGTH_WORD,f) && i<track){
		if(i==step){
			step += INC_STEP;
			//Cap phat them cho data them 100 vung nho
			char **newSource = (char **) realloc(source,step*sizeof(char *));
			if(!newSource){
				//when ptr newSource return NULL
				printf("Sorry cann't allocate. \n");
				return NULL;
			}
			source = newSource;
		}

		int strLen = strlen(buf);
		//Do fgets se lay luon ki tu newline nen ta se thay \n bang \o
		buf[strLen-1]='\0';
		char *str = (char *) malloc(strLen * sizeof(char));
		// copy buf to str
		strcpy(str,buf);
		source[numberOfWord] = str;

		numberOfWord++;
		
		i++;
	}

	
	*length = numberOfWord;
	printf("CHieu dai la %d\n", numberOfWord);
	printf("Welcome to the Spell Checker!\n");
	printf("The dictionary has been loaded.\n");
	
	return source;
}


void getDataFromFile(FILE* f,char** data1,int *length1, ){
	
	long numberOfWord = 0;
	
	//alocate chunk of memoruy
	char ** source = NULL;
	char buf[MAX_LENGTH_WORD];
	int i = 0;
	int step = 0;
	int track;
	char temp;
	fscanf(f,"%d",&track);
	printf("Track %d\n",track );

	while(fgets(buf,MAX_LENGTH_WORD,f) && i<track){
		if(i==step){
			step += INC_STEP;
			//Cap phat them cho data them 100 vung nho
			char **newSource = (char **) realloc(source,step*sizeof(char *));
			if(!newSource){
				//when ptr newSource return NULL
				printf("Sorry cann't allocate. \n");
				return NULL;
			}
			source = newSource;
		}

		int strLen = strlen(buf);
		//Do fgets se lay luon ki tu newline nen ta se thay \n bang \o
		buf[strLen-1]='\0';
		char *str = (char *) malloc(strLen * sizeof(char));
		// copy buf to str
		strcpy(str,buf);
		source[numberOfWord] = str;

		numberOfWord++;
		
		i++;
	}

	
	*length = numberOfWord;
	printf("CHieu dai la %d\n", numberOfWord);
	printf("Welcome to the Spell Checker!\n");
	printf("The dictionary has been loaded.\n");
	
	return source;
}




void sendMessage(){
	FILE* f = fopen(FILE_NAME,"r");
	char** dictionary;
	int lengthDictionary = 0;
	char** forbiddenList;
	int lengthForbidden = 0;
	char** forbiddenList1;
	int lengthForbidden1 = 0;
	dictionary = getDataFromFile(f,&lengthDictionary);
	for (int i = 0; i < lengthDictionary; ++i)
	{
		printf("===%s=\t",dictionary[i] );
	}
	forbiddenList = getDataFromFile(f,&lengthForbidden);
	for (int i = 0; i < lengthForbidden; ++i)
	{
		printf("===%s=\t",forbiddenList[i] );
	}
	forbiddenList1 = getDataFromFile(f,&lengthForbidden1);
	for (int i = 0; i < lengthForbidden1; ++i)
	{
		printf("===%s=\t",forbiddenList1[i] );
	}
}

int main(int argc, char const *argv[])
{
	FILE* f = fopen(FILE_NAME,"r");
	if(!f){
		printf("Sorry cannot open file\n");
		return 1;
	}else{
		fclose(f);
		//Start sendMessage
		sendMessage();
	}


	return 0;
}