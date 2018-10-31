#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInput(){
	int value;
	int x;
	do{
		printf("Please enter number from (1-9): ");
		fflush(stdin);
		x = scanf("%d",&value);
	}while(x == 0 || value<1 || value > 9);
	return value;
}

void displayTable(int x){
	printf("Multiplication table for %d number: \n", x );
	for (int i = 0; i <= 10; ++i)
	{
		printf("%2d x %2d = %2d\n",x,i,x*i );
	}
}

int main(int argc, char const *argv[])
{
	int input;
	int exit;
	do{
		input = getInput();
		displayTable(input);
		fflush(stdin);
		printf("Press enter to continue, Esc to exit\n");
		exit = getchar();
	}while(exit!='=');	
	return 0;
}