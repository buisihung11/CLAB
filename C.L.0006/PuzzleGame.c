#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_INCORRET_GUESS 5
#define INC_STEP 10
#define MAX_LENGTH_WORD 30
#define TRUE 1
#define FALSE 0
#define PLAYING 0
#define LOSE -1
#define WIN 1
#define GUESSED -1
char* getAPuzzle(char **data, long length,int *strLen){
	srand((unsigned)time(NULL));

	int random = (rand()%(length ));
	
	int lenStr = strlen(data[random]);
	*strLen = lenStr;
	char *randomPuzzle ;
	randomPuzzle = (char *) malloc(lenStr*sizeof(char));
	strcpy(randomPuzzle,data[random]);
	
	return randomPuzzle;
}

void checkGame(char *puzzle,int *hasGuess,char userGuess,int *incorrectGuess,int strLen,int *status,int *correctLetter){
	//Check is in puzzle
	int check = FALSE;
	for(int i=0 ; i < strLen ; i++){
		if(puzzle[i] == userGuess){
			check = TRUE;
			if(hasGuess[i]>=0){
				
				hasGuess[i]= GUESSED;//-1 show that the letter was guessed
				*correctLetter = *correctLetter + 1;
				
				if(*correctLetter==strLen){
					*status = WIN;
					break;
				}
				
			}else{
				
				printf("Sorry, you has guessed that letter already.\n");
				printf("Now count as a miss.\n");
				*incorrectGuess = *incorrectGuess + 1; 
				
				break;
			}
		}
	}

	if(!check){
		*incorrectGuess = *incorrectGuess + 1; 
		printf("Sorry that letter is NOT in the puzzle\n");
	}else{
		printf("Congratulations! You guessed a letter in the puzzle\n");
	}
	if(*incorrectGuess == MAX_INCORRET_GUESS){
					*status = LOSE;
	}
}	

void printfGameBoard(char *puzzle,int *hasGuess, int strLen,int incorrectGuess){
	printf("You currently have  %d incorrect guess\n",incorrectGuess);
	printf("Here is your puzzle\n");
	for(int i=0;i<strLen;i++){
		if(hasGuess[i]!=GUESSED){
			printf("_ ");
		}else{
			printf("%c ",puzzle[i] );
		}
	}
	printf("\n");
}

void gameOverStatus(char *puzzle,int status){
	if(status == WIN){
		printf("\nCongratulations! You got the word, %s\n",puzzle);
	}
	if(status == LOSE){
		printf("Sorry you have made %d incorrect guesses, you lose\n",MAX_INCORRET_GUESS);
		printf("The correct word was %s\n",puzzle);
	}
}
void playGame(char **data, long length){
	int incorrectGuess = 0;
	int correctLetter = 0;
	char *puzzle;
	//char *copyPuzzle;
	int *hasGuess;
	int strLen;
	//Set Up Game
	//puzzle = getAPuzzle(data,length);
	puzzle = getAPuzzle(data,length,&strLen);
	// printf("Test %s\n", puzzle);
	// printf("StrLen %d\n",strLen);
	hasGuess = (int *) malloc(strLen*sizeof(int));
	*hasGuess = 0;
	int status = PLAYING  ;
	char userGuess;
	while(incorrectGuess < MAX_INCORRET_GUESS && status == PLAYING){
		//Print 	
		// printf("correct Letter %d\n",correctLetter);
		// printf("incorrect Letter %d\n",incorrectGuess);
		// printf("Status %d\n",status );
		printfGameBoard(puzzle,hasGuess,strLen,incorrectGuess);
		
		fflush(stdin);
		printf("Enter your guess\n");
		scanf("%c",&userGuess);
		if(!(userGuess>=65 && userGuess <=91)){
			printf("Please enter UpperCase Letter\n");
			continue;
		}else{
			checkGame(puzzle,hasGuess,userGuess,&incorrectGuess,strLen,&status,&correctLetter);
		}
		//checkGame(puzzle,hasGuess,userGuess,incorrectGuess,strLen);
	}
	//print the Status
	gameOverStatus(puzzle,status);
}


char ** writeDataToDictionary(char *filename,long *length){
	
	FILE *f = fopen(filename,"r");

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
	
	printf("The data has been loaded.\n");
	fclose(f);
	return source;
}

int main(int argc, char const *argv[])
{
	char filename[30];
	char **data;
	long totalPuzzle;
	printf("Enter your file stores puzzle.\n");
	scanf("%s",&filename);
	FILE *f = fopen(filename,"r");
	if(!f){
		printf("Cannot access the file\n");
	}else{
		data = writeDataToDictionary(filename,&totalPuzzle);
	}
	char exit;
	do{
		fflush(stdin);
		printf("Would you like to Play Hangman Game (Y/N)\n");
		exit = toupper(getchar());
		if(exit=='Y'){
			playGame(data,totalPuzzle);
		}
	}while(exit!='N');
	printf("\nThanks for playing Game!\n");
	return 0;
}