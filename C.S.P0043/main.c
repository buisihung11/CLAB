#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_ELEMENT 100

void addItem(int *ptr,int* length){
	int number;
	printf("Enter a number: ");
	fflush(stdin);
	scanf("%d", &ptr[*length]);
	//*(ptr+*length) = number;
	(*length)++;
	printf("Lenght %d\n", *length);
}
void displayArr(int *ptr,int length){
	printf("The array %d length: \n",length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\t",*(ptr+i) );
	}
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
}
int searchPositionValue(int * ptr,int length,int value){
	int index = -1;
	
	for (int i = 0; i < length; ++i)
	{
		if(value == ptr[i]){
			index = i;
			break;
		}
	}
	return index;
}
void removeFirstExistElement(int *ptr, int* length,int value){
	int lengthTemp = *length;
	for(int i=searchPositionValue(ptr,lengthTemp,value);i<lengthTemp-1 && i!= -1;i++){
		ptr[i]=ptr[i+1];
	}
	(*length)--;
}



void menu(){
	int userChocie;
	int *ptrArr;
	ptrArr = (int*) malloc(MAX_ELEMENT* sizeof(int));
	int length = 0;

	do{
		printf("\n=========\n");
		printf("Menu:\n");
		printf("1.Add value\n");
		printf("2.Search value\n");
		printf("3.Remove first element\n");
		printf("4.Remove all elements\n");
		printf("5.Print out the array\n");
		printf("6.Sort the array in ascending order  \n");
		printf("7.Sort the array in descending order \n");
		printf("Other Quit.\n");
		printf("=========\n");
		printf("Your choice: ");
		scanf("%d",&userChocie);
		int value;
		switch(userChocie){
			case 1: 
				addItem(ptrArr,&length);
				break;
			case 2:
				
				printf("Enter your value you want to search: ");
				fflush(stdin);
				scanf("%d",&value);
				int check = searchPositionValue(ptrArr,length,value);
				if(check!= -1)
					printf("Your value is in %d position\n",check );
				else
					printf("Cannot find the value\n");
				break;
			case 3:
				
				printf("Enter your value you want to remove: ");
				fflush(stdin);
				scanf("%d",&value);
				removeFirstExistElement(ptrArr,&length,value);
				break;
			case 4:
				free(ptrArr);
				ptrArr = (int*) malloc(MAX_ELEMENT* sizeof(int));
				length = 0;
				break;
			case 5: 
				displayArr(ptrArr,length);
				break;
			case 6:
				sortAscending(ptrArr,length);
				break;
			case 7:
				sortDescending(ptrArr,length);
				break;		
		}



	}while(userChocie>=1 && userChocie <=7);
}


int main(int argc, char const *argv[])
{
	menu();
	return 0;
}