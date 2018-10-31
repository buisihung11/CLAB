#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInteger(){
	int x;
	int value;
	do{
		fflush(stdin);
		x = scanf("%d",&value);
	}while(x == 0 );
	return value;
}

int* getInput(int* lengthArr){
	int *arr;
	int length;
	printf("Enter a number of element: ");
	length = getInteger();
	arr = (int*) malloc(length * sizeof(int));
	printf("Input Elemens:\n");
	for (int i = 0; i < length; ++i)
	{
		printf("\tElement %d = ",i+1);
		arr[i] = getInteger();
	}
	*lengthArr = length;
	return arr;
}

void displayResult(int* arr,int length){
	int odd =0;
	int even =0;
	for (int i = 0; i < length; ++i)
	{
		if(arr[i]%2 == 0)
			even += arr[i];
		else
			odd += arr[i]; 
	}	
	printf("Sum of Even %d\n",even );
	printf("Sum of Odd %d\n",odd );
}

int main(int argc, char const *argv[])
{
	int *arr = NULL;
	int length =0;
	int exit;
	do{
		printf("Sum Even Odd Program\n");
		arr = getInput(&length);
		displayResult(arr,length);

		fflush(stdin);
		printf("Press enter to convert new decimal, Esc to exit\n");
		exit = getchar();
	}while(exit!='=');
	
	

	return 0;
}