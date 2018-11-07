#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int getAnInteger(){
	//when high =-1 => vo cung
	int result;
	char buf[30];
	int choice;
	do{
		result = TRUE;
		fflush(stdin);
		printf("\nNhap mot so: " );
		gets(buf);
		//check xem co ki tu character hay kh
		for (int i = 0; buf[i]!='\0' && result ==TRUE; ++i)
	 	{
	 		char c = buf[i];
	 		if(c<'0' || c > '9'){
	 			printf("YOu enter wrong\n");
	 			result = FALSE;
	 			continue;
	 		}
	 	} 	

		choice = atoi(buf);
		if(choice <0)
			result= FALSE;

	}while(result == FALSE);

	return choice;
}

void function1(){
	int x;
	int arr[100];
	int length=0;
	printf("Enter a positive number: ");
	x = getAnInteger();
	
	while(x!=0){
		int surplus;
		surplus = x%10;
		arr[length] = surplus;
		x /=10;
		length++;
		
	}
	printf("Digits: ");
	for (int i = length-1; i >=0; --i)
	{
		printf("%d\t", arr[i]);
	}

}
void function2(){
	int x;
	int sum = 0;
	printf("Enter a positive number: ");
	x = getAnInteger();
	for (int i = 1; i < x; ++i)
	{
		if(x%i==0)
			sum+=i;
	}
	printf("Sum digits: %d\n", sum);
}
void menu(){
	int userChoice;
	do{
		printf("\n1.Function1\n");
		printf("2.Function2\n");
		printf("3.Quit\n");
		printf("Your choice: ");
		scanf("%d",&userChoice);
		switch(userChoice){
			case 1 :
				function1();
				break;
			case 2:
				function2();
				break;	
		}
	}while(userChoice!=3);
	
}

int main(int argc, char const *argv[])
{
	menu();
	return 0;
}