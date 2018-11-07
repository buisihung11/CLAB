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
		printf("Nhap mot so: " );
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

void sortAscending(int* ptr,int length){
	//create a copy arr
	int copyArr[length];
	for (int i = 0; i < length; ++i)
	{
		copyArr[i] = ptr[i];
	}
	for(int i=0;i<length -1;i++){
		for(int j=i+1;j<length;j++){
			if(copyArr[i]>copyArr[j]){
				int temp;
				temp = copyArr[i];
				copyArr[i]= copyArr[j];
				copyArr[j]= temp;
			}
		}
	}
	printf("Ascending Array:\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d\t", copyArr[i]);
	}
	printf("\n");
}


void sortDescending(int* ptr,int length){
	//create a copy arr
	int copyArr[length];
	for (int i = 0; i < length; ++i)
	{
		copyArr[i] = ptr[i];
	}
	for(int i=0;i<length -1;i++){
		for(int j=i+1;j<length;j++){
			if(copyArr[i]<copyArr[j]){
				int temp;
				temp = copyArr[i];
				copyArr[i]= copyArr[j];
				copyArr[j]= temp;
			}
		}
	}
	printf("Descending Array:\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d\t", copyArr[i]);
	}
	printf("\n");
}

void getInput(int* arr,int length){
	
	for (int i = 0; i < length; ++i)
	{
		printf("Enter element[%d]: ",i);
		arr[i] = getAnInteger();
	}
}

void mainFunction(){
	int *ptrArr;
	int length = 0;


	do{
		printf("Please enter number of array: \n");
		fflush(stdin);
		length = getAnInteger();
	}while(length <=0);
	ptrArr = (int*) malloc(length*sizeof(int));
	getInput(ptrArr,length);
	sortAscending(ptrArr,length);
	sortDescending(ptrArr,length);

	free(ptrArr);
}

int main(int argc, char const *argv[])
{
	int userChoice;
	do{
		mainFunction();
		
		printf("Do you want to continue\n");
		userChoice = getchar();
	}while(userChoice != '=');	
	return 0;
}