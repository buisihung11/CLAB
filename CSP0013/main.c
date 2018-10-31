#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_NUMBER 100

void sortAscending(int* ptr,int length){
	for(int i=0;i<length -1;i++){
		for(int j=i+1;j<length;j++){
			if(ptr[i]>ptr[j]){
				int temp;
				temp = ptr[i];
				ptr[i]= ptr[j];
				ptr[j]= temp;
			}
		}
	}

}


int getPositiveInRange(){
	int x;
	int value;
	do{
		fflush(stdin);
		x = scanf("%d",&value);
		if(value == -999)
			return value;
	}while(x==0 || value< 0 ||value>100);
	return value;
}


void removeElement(int* arr, int*length , int pos){
	for (int i = pos; i < *length - 1; ++i)
	{
		arr[i] = arr[i+1];
	}
	(*length)--;
}


void calculateDeviation(int* arr,int length){
	double avg = 0;
	for (int i = 0; i < length; ++i)
	{
		avg+=arr[i];
	}
	avg /= length;

	double deviation = 0;
	for (int i = 0; i < length; ++i)
	{
		deviation += pow((double) arr[i]-avg,2);
	}
	deviation = sqrt(deviation/length);
	printf("The adjucted mean is %.2lf\n",avg );
	printf("The adjucted standard deviation is %.2lf\n",deviation );
}


void printTheHistogram(int * arr,int length){
	int i = 0;
	int start = 0;
	while(start<=100){
		if(start!=100)
			printf("%2d-%2d|",start,start+4);
		else
			printf("%5d|",start);
		if(i<length){
			while(arr[i]<=start+4){
				printf("*");
				i++;
			}
		}
		start+=5;
		printf("\n");
	}
}

int* getInput(int*length){
	int *data;
	int arr[MAX_NUMBER];
	int lengthTemp = 0;
	int maxValue ;
	int minValue ;
	//input data and find max min value
	printf("Please enter number:\n");
	for (int i = 0; i < MAX_NUMBER; ++i)
	{
		// arr[i] = getPositiveInRange();
		arr[i] = (rand()%100);
		// printf("arr[%d] %d\n",i,arr[i] );
		if(i==0){
			minValue = arr[i];
			minValue = arr[i];
		}
		if(arr[i] == -999 && i<=3){
			printf("Sorry please enter at least 3 number\n");
			i--;
			continue;
		}
		if(arr[i] == -999 && i>3)
			break;
		if(arr[i]>maxValue)
			maxValue = arr[i];
		if(arr[i]< minValue)
			minValue = arr[i];
		lengthTemp++;
		
	}

	

	printf("\nThe array:\n");
	for (int i = 0; i < lengthTemp; ++i)
	{
		printf("%d\n",arr[i] );
	}
	printf("Min value %d \nMax value %d \n",minValue,maxValue );
	//remove Min and Max value
	for (int i = 0; i < lengthTemp; ++i)
	{
		if (arr[i] == minValue || arr[i] == maxValue){

			removeElement(arr,&lengthTemp,i);
			i--;
		}

	}
	sortAscending(arr,lengthTemp);
	*length = lengthTemp;
	data = (int*) malloc((lengthTemp+1)*sizeof(int));
	for (int i = 0; i < lengthTemp; ++i)
	{
		data[i] = arr[i];
	}
	
	

	
	return data;
}

void mainFunction(){
	int * data;
	int length = 0;
	//getInput
	data = getInput(&length);
	printf("\nOut Array %d :\n",length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\t",data[i] );
	}
	printf("\n");
	calculateDeviation(data,length);
	printTheHistogram(data,length);
}

int main(int argc, char const *argv[])
{
	mainFunction();
	return 0;
}