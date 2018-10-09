#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIST_FALSE 1
#define TRUE 1
#define FALSE 0
#define NUMBER_OF_GAME 3
#define COST_FOR_A_ROUND 0.25
#define SMALL_BONUS 0.5
#define	BIG_BONUS 10.0
#define FILE_NAME "money.txt"
//function
void menuGame();
void playGame();
float getUserMoney();
void adjuctUserMoney( float value);
void playGame();
void saveGame();
void exitGame();

void menuGame(){
	int userChoice;
	//Print Menu and get userChoice
	do{
		printf("Menu:\n");
		printf("1.Play Game\n");
		printf("2.Save Game\n");
		printf("3.Cash Out\n");
		printf("=========\n");
		printf("Your choice: ");
		scanf("%d",&userChoice);
		if(userChoice>3 && userChoice<=0){
			printf("Please enter number from 1-3\n");
		}
	}while(userChoice>3&&userChoice<=0);
	//Go to function
	switch(userChoice){
		case 1: 
			//Check the money Player
			if(getUserMoney()==0){
				printf("Oh! You are run out of cash!!\n");
			}else{
				playGame();
			}
			break;
		case 2: 
			saveGame();
			break;
		case 3: 
			exitGame();
			break;

	}
}

float getUserMoney(){
	FILE *f = fopen(FILE_NAME,"r");
	float money ;
	fscanf(f,"%f",&money);
	//printf("Get user money %f\n",money);//test
	fclose(f);
	return money;
}

void adjuctUserMoney( float value){
	FILE *f = fopen(FILE_NAME,"w");
	fprintf(f, "%f\n", value);
	fclose(f);
}

void playGame(){
	int randomArr[NUMBER_OF_GAME]={0};
	int repeat = 0;
	float bonus;
	float userMoney;
	userMoney = getUserMoney();
	//SET UP Gamee
	//random number from 0-9
	userMoney -= COST_FOR_A_ROUND;

	for(int i=0;i<NUMBER_OF_GAME;i++){
		randomArr[i] = (rand()%10);
	}
	//CHECK number of repeated
	for (int i = 0; i < NUMBER_OF_GAME; ++i){
		for (int j = i+1; j < NUMBER_OF_GAME; ++j)
		{
			if(randomArr[i]==randomArr[j]){
				repeat++;
			}
		}
		if(repeat==2){
			break;
		}
	}
	//END GAME 
	//Calculate the Bonus
	switch(repeat){
		case 1: 
			bonus = SMALL_BONUS;
			break;
		case 2: 
			bonus = BIG_BONUS;
			break;
		default: 
			bonus = 0;

	}
		userMoney += bonus;
		//print the 3 number and result for this game 
		printf("The Splot Machine were %d%d%d\n", randomArr[0],randomArr[1],randomArr[2] );
		printf("Your bonus is %.2f\n", bonus );
		printf("Your cash now is %.2f\n",userMoney);
		adjuctUserMoney(userMoney);
		menuGame();
}

void saveGame(){
	adjuctUserMoney(getUserMoney());
	printf("Your Game has saved!\n");
}

void exitGame(){
	printf("Your case is %f\n", getUserMoney());
	printf("Thank for playing the game!\n");
}

int main(int argc, char const *argv[])
{
	/* code */
	FILE *f = fopen("money.txt","r");
	if(!f){
		printf("File doesn't exist.Please creat file!\n");
		
	}else{
		fclose(f);
		menuGame();
	}	
	
	return 0;
}