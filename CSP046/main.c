#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


int getAnInteger(int low,int high){
	//when high =-1 => vo cung
	int result;
	char buf[30];
	int choice;
	do{
		result = TRUE;
		fflush(stdin);
		printf("Nhap mot so tu %d-%d: ",low,high );
		gets(buf);
		//check xem co ki tu character hay kh
		for (int i = 0; buf[i]!='\0' && result ==TRUE; ++i)
	 	{
	 		char c = buf[i];
	 		if(c<'0' || c > '9'){
	 			printf("YOu enter wrong\n");
	 			result = FALSE;
	 		}
	 	} 	

		choice = atoi(buf);
		if(high!=-1){
			if(choice<low || choice > high){
				printf("Please enter from %d to %d.\n",low,high);
				result= FALSE;
			}
		}else{
			if(choice<low ){
				printf("Please enter from %d to %d.\n",low,high);
				result= FALSE;
			}
		}
		

	}while(result == FALSE);

	return choice;
}

int isPrime(int number){
	int result = TRUE;
	for (int i = 2; i <= number/2; ++i)
	{
		if(number%i == 0)
		{
			result = FALSE;
			break;
		}
	}
	return result;
}

void displayPrimes(int value){
	for (int i = 2; i <= value; ++i)
	{
		if(isPrime(i))
			printf("%d\t", i);
	}
}

int isFibonanci(int value){
	int x1 = 5*value*value + 4;
	int check1 = sqrt(x1);
	int x2 = 5*value*value - 4;
	int check2 =  sqrt(x2);
	return x1 == check1*check1 || x2 == check2*check2;
}

int calcSum(int value){
	int sum = 0;
	while(value!=0){
		int surplus = value%10;
		sum+=surplus;
		value /= 10;
	}
	return sum;
}

void menu(){
	int userChocie;

	do{
		printf("\n=========\n");
		printf("Menu:\n");
		printf("1.Add value\n");
		printf("2.Search value\n");
		printf("3.Remove first element\n");
		printf("4. Quit.\n");
		printf("=========\n");
		printf("Your choice: ");
		userChocie = getAnInteger(1,4);
		int value;
		switch(userChocie){
			case 1: 
				value = getAnInteger(2,50);
				displayPrimes(value);
				break;
			case 2:
				value = getAnInteger(1,1000);
				if(isFibonanci(value))
					printf("%d is fibonanci number\n",value );
				else
					printf("Not a fibonanci number\n");
				break;
			case 3:
				value = getAnInteger(0,-1);
				printf("Sum of its digit: %d\n",calcSum(value) );
				break;
			
		}



	}while(userChocie!=4);
}

int main(int argc, char const *argv[])
{
	
	menu();
	return 0;
}