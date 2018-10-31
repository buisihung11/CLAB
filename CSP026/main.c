#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInput(){
	int value;
	int x;
	do{
		printf("Please enter positive number: ");
		fflush(stdin);
		x = scanf("%d",&value);
	}while(x == 0 || value<0 );
	return value;
}

int converDecimalToBinary(int value){
	int arr[50];
	int count = 0;
	//Split the value
	do{
		arr[count] = value % 2;
		value /= 2;
		count++;
	}while(value!=0);
	//Start convert
	int result = 0;
	for (int i = count -1 ; i >= 0; --i)
	{
		result = result*10 + arr[i];
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int input;
	int exit;
	do{
		printf("Convert Decimal to Binary Program\n");
		input = getInput();
		printf("Binary number %d\n",converDecimalToBinary(input) );
		fflush(stdin);
		printf("Press enter to convert new decimal, Esc to exit\n");
		exit = getchar();
	}while(exit!='=');	
	return 0;
}