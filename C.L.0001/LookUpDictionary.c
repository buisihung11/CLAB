#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_IN_DICTIONARY 30000
#define FILE_NAME "data1.txt"
#define TRUE 1
#define FALSE 0
#define INC_STEP 100
#define MAX_LENGTH_WORD 30


int isSubString(char shortStr[],char longStr[]){
	int check = 0;
	if(strstr(shortStr,longStr)>0){
		check = 1;
	}
	return check;
}

int isSubsequence(char shortStr[], char longStr[]){
	int x,y;
	x = y = 0;

	while(shortStr[x]!='\0' && longStr[y]!='\0'){
			if(shortStr[x]==longStr[y]){
				x++;
				y++;
			}else{
				y++;
			}
		}

	if(shortStr[x]=='\0'){
		return 1;
	}else{
		return 0;
	}
}

int isPermutation(char firstStr[],char secondStr[]){
	int check = 1;
	for (int i = 0; i < strlen(firstStr) && check == 1; ++i)
	{
		int numberNeedToRepeat = 0;
		//calculate numberNeedToRepeat
		for(int t=0;t < strlen(firstStr);++t){
			if(firstStr[t]==firstStr[i]){
				numberNeedToRepeat++;
			}
		}

		int repeat = 0;
		for(int j=0;j<strlen(secondStr);j++){
			if(firstStr[i]==secondStr[j]){
				repeat++;
			}
			if(repeat>numberNeedToRepeat){
				check = 0;
				break;
			}
		}

		//check condition
		if(repeat<numberNeedToRepeat){
			check = 0;
			break;
		}
	}
	return check;
}

int checkMatchscore(char firstStr[],char secondStr[]){
	int notMatchScore = 0;
	int check = 0;
	int length = strlen(firstStr);//two string has same length
	for(int i=0;i<length;i++ ){
		if(firstStr[i]!=secondStr[i]){
			notMatchScore++;
		}
	}
	if(notMatchScore<2){
		check = 1;
	}

	return check;
}

char ** writeDataToDictionary(long *length){
	FILE *f = fopen(FILE_NAME,"r");
	long numberOfWord = 0;
	
	//alocate chunk of memoruy
	char ** source = NULL;
	char buf[MAX_LENGTH_WORD];
	int i = 0;
	int step = 0;

	while(fgets(buf,MAX_LENGTH_WORD,f)){
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
	fclose(f);
	return source;
}

int isInDictionary(char ** source, char str[30],int length){
	int strLength = strlen(str);
	int check = FALSE;
	for (int i = 0; i < length; ++i)
	{
		int wordLength = strlen(source[i]);
		if(wordLength == strLength ){
			if(isSubString(str,source[i])){
				
				check = TRUE;
				break;
			}
		}
	}
	return check;
}

void searchingPossible(char ** source, char str[30],int length){
	int strLength = strlen(str);
	printf("Here is possible word that you could have meant: \n" );
	for (int i = 0; i < length; ++i)
	{
		int wordLength = strlen(source[i]);

			
		if(wordLength < strLength && strLength - wordLength <=3){
			if(isSubString(source[i],str)){
				printf("check SubString\n");
				printf("%s\n",source[i]);
			}
			if(isSubsequence(source[i],str)){
				printf("check SubSequence\n");
				printf("%s\n",source[i]);
			}
		}
		if(wordLength > strLength && wordLength - strLength <=3 ){
			if(isSubString(str,source[i])){
				printf("check SubString\n");
				printf("%s\n",source[i] );
			}else if(isSubsequence(str,source[i])){
				printf("check Subsequence\n");
				printf("%s\n",source[i] );
			}
		}
		if(wordLength == strLength ){
			
			if(isSubsequence(source[i],str)){
				printf("check Subsequence\n");
				printf("%s\n",source[i] );
			}else if(isPermutation(source[i],str)){
				printf("check isPermutation\n");
				printf("%s\n",source[i] );
			}else if(checkMatchscore(source[i],str)){
				printf("check MatchScore\n");
				printf("%s\n",source[i]);
			}
		}

	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	// char dictionary[MAX_WORD_IN_DICTIONARY + 1][30];
	char ** dictionary = NULL;
	long numberOfWord;
	//Check the file
	FILE *f = fopen(FILE_NAME,"r");
	if(!f){
		printf("File does not exist! Please check the data\n");
		return 0;
	}
	//READ DATA
	dictionary = writeDataToDictionary(&numberOfWord);

	fclose(f);
	char exit;
	char userInput[30];

	do{

		fflush(stdin);
		printf("Please enter the word you would like to checked\n");
		scanf("%s",&userInput);
		int inputLength;
		inputLength = strlen(userInput);
		//check length
		if(inputLength==0){
			printf("Do you mean to find ");
			printf("%s\n",dictionary[0]);
		}
		else{
			//check is in dictionary
			if(isInDictionary(dictionary,userInput,numberOfWord)){
				printf("Great %s is in the dictionary!\n", userInput );
			}
			else{
				searchingPossible(dictionary,userInput,numberOfWord);
			}
		}

		
		
		fflush(stdin);
		printf("Would you like to enter another word? (Yes/No)\n");
		exit = toupper(getchar());
		
	}while(exit!='N');//khong the cho exit != 'n'?


	return 0;
}
