#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define START_MONEY 1000
#define COST_FOR_BUY_CHIP 11
#define COST_FOR_SELL_CHIP 10
#define WIN 1
#define LOSE -1


void buyChips(int *userWallet, int* userChips){
	int cashToBuy;
	int x;
	
		printf("How much cash do you want to spend for chips?\n");
		x = scanf("%d",&cashToBuy);
		//Check whether the purchase is succes
		if(cashToBuy>*userWallet ){
			printf("Sorry you do not have that much money. No chips bought.\n");
		}else if(x==0 || cashToBuy < COST_FOR_BUY_CHIP){
			printf("Sorry you enter wrong amount. No chips bought.\n");
		}
		else{
			*userChips += cashToBuy/COST_FOR_BUY_CHIP;
			*userWallet -= *userChips * COST_FOR_BUY_CHIP;
		}
}


void sellChips(int *userWallet, int* userChips){
	int chipsToSell;
	int x;
	
		printf("How many chips do you want to sell?\n");
		x = scanf("%d",&chipsToSell);
		//Check whether the purchase is succes
		if(chipsToSell>*userChips ){
			printf("Sorry you do not have that much chips. No chips sell.\n");
		}else if(x==0 ){
			printf("Sorry you enter wrong amount. No chips bought.\n");
		}
		else{
			*userChips -= chipsToSell;
			*userWallet += chipsToSell* COST_FOR_SELL_CHIP;
		}
}
void showInfo(int userWallet, int userChips ){
	printf("You currently have $%d left and %d chips. \n",userWallet,userChips );
}

void crapsGame( int* userChips){
	int random;
	int chipsBet;
	int status;
	int x;
	printf("How many chips do you want to sell?\n");
	x = scanf("%d",&chipsBet);
	if(chipsBet>*userChips || chipsBet<=0 || x==0){
		printf("Sorry, that is not allowed. No game played\n");
		
	}else{


	//First roll4
	int rollTrigger;
	do{
		printf("Press 'r' and hit enter for your first roll.\n");
		fflush(stdin);
		rollTrigger = toupper(getchar());
	}while(rollTrigger!='R');
	random = (rand()%11 + 2 );
	printf("You roll a %d \n", random);
	if(random == 7 || random == 11){
		status = WIN;
	}else if(random == 2 || random == 3 || random == 12){
		status = LOSE;
	}else{
		int k = random;
		do{
			do{
				printf("Press 'r' and hit enter for your next roll.\n");
				fflush(stdin);
				rollTrigger = toupper(getchar());
			}while(rollTrigger!='R');

			random = (rand()%11 + 2 );
			printf("You roll a %d \n", random);
			if(random == k)
				status = WIN;
			if(random == 7)
				status = LOSE;
		}while(random != k && random != 7);
	}
	//Check the status
	switch(status){
		case WIN:
			printf("You win!\n" );
			*userChips += chipsBet;
			break;
		case LOSE:
			printf("You lose!\n" );
			*userChips -= chipsBet;
			break;	
	}
	}
}


void arupGame( int* userChips){
	int random;
	int chipsBet;
	int status;
	int x;
	printf("How many chips do you want to sell?\n");
	x = scanf("%d",&chipsBet);
	if(chipsBet>*userChips || chipsBet<=0 || x==0){
		printf("Sorry, that is not allowed. No game played\n");
		
	}else{


	//First roll4
	int rollTrigger;
	do{
		printf("Press 'r' and hit enter for your first roll.\n");
		fflush(stdin);
		rollTrigger = toupper(getchar());
	}while(rollTrigger!='R');
	random = (rand()%11 + 2 );
	printf("You roll a %d \n", random);
	if(random == 12 || random == 11){
		status = WIN;
	}else if(random == 2 ){
		status = LOSE;
	}else{
		int k = random;
		do{
				printf("Press 'r' and hit enter for your next roll.\n");
				fflush(stdin);
				rollTrigger = toupper(getchar());
			}while(rollTrigger!='R');

			random = (rand()%11 + 2 );
			printf("You roll a %d \n", random);
			if(random > k)
				status = WIN;
			if(random <= k)
				status = LOSE;
	}
	//Check the status
	switch(status){
		case WIN:
			printf("You win!\n" );
			*userChips += chipsBet;
			break;
		case LOSE:
			printf("You lose!\n" );
			*userChips -= chipsBet;
			break;	
	}
	}
}

void sellAllChips(int *userWallet, int* userChips){
	
	*userWallet += *userChips * COST_FOR_SELL_CHIP;
	*userChips = 0;
	printf("After selling your chips, you have $%d. Thanks for playing\n", *userWallet );
}

void menu(){
	int userChoice;
	int userWallet = START_MONEY;
	int userChips = 0;
	//Print Menu and get userChoice
	do{
		printf("\n=========\n");
		printf("Menu:\n");
		printf("1.Buy Chips\n");
		printf("2.Sell chips\n");
		printf("3.Play Craps\n");
		printf("4.Play Arup's Game of Dice\n");
		printf("5.Status Report\n");
		printf("6.Quit\n");
		printf("=========\n");
		printf("Your choice: ");
		scanf("%d",&userChoice);
		if(userChoice>6 || userChoice<=0){
			printf("Please enter number from 1-6\n");
		}

		switch(userChoice){
			case 1:
				buyChips(&userWallet,&userChips);
				break;
			case 2:

				sellChips(&userWallet,&userChips);
				break;
			case 3:
				crapsGame(&userChips);
				break;	
			case 4:
				arupGame(&userChips);
				break;
			case 5: 
				showInfo(userWallet,userChips);
				break;	
			case 6: 
				//sell All chips
				sellAllChips(&userWallet,&userChips);
				break;

		}


	}while(userChoice!=6);


	

}

int main(int argc, char const *argv[])
{
	menu();

	return 0;
}