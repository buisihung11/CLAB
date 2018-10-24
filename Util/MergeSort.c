#include <stdio.h>
#include <string.h>
void mergeSort(int arr[], int l, int m , int r){

	printf("\n\nLeft %d Mid %d Right %d\n",l,m,r );

	
	

	//First make a copy of tow subarr left and right

	int leftLength = m - l + 1;
	int rightLength = r - m ;
	int L[leftLength];
	int R[rightLength];
	
	
	printf("\nLeft Item: ");
	for (int i = 0; i <leftLength; ++i)
	{
		L[i] = arr[l+i];
		
		printf("%d   ",L[i]); 
	}
	printf("\nRight Item: ");
	for (int i = 0; i <rightLength; ++i)
	{
		R[i] = arr[m+1+i];
		 printf("%d   ",R[i]); 
	}
	printf("\nArray before swap from %d to %d : ", l ,r - l + 1);
	//from l to r
	for (int i = 0; i < leftLength; ++i)
	{
		printf("%d    ", L[i]);
	}
	for (int i = 0; i < rightLength; ++i)
	{
		printf("%d    ", R[i]);
	}
	//Start compair L[] aand R[] and change the value of array 
	int leftIterator = 0;
	int rightIterator = 0 ;
	int arrIterator = l;//Use for all case
	while(leftIterator < leftLength && rightIterator < rightLength){
		if(L[leftIterator] <= R[rightIterator]){
			//printf("Swap left %d for right %d\n",L[leftIterator],R[rightIterator] );
			arr[arrIterator] = L[leftIterator];
			leftIterator++;
		}else{
			//printf("Swap right %d for left %d\n",R[rightIterator], L[leftIterator]);
			arr[arrIterator] = R[rightIterator];
			rightIterator++;
		}
		arrIterator++;
	}
	//After that we continuely do for the rest of the subarr (one of these)
	while(leftIterator < leftLength){
		arr[arrIterator] = L[leftIterator];
		leftIterator++;
		arrIterator++;
	}

	while(rightIterator < rightLength){
		arr[arrIterator] = R[rightIterator];
		rightIterator++;
		arrIterator++;
	}


	
	

	printf("\nThe origanal Array: ");//from 0 to r
	for (int i = 0; i < r +1; ++i)
	{
		printf("%d   ",arr[i] );
	}

}

void mergeDevide(int arr[],int l,int r){
	if(l<r){

		int m = (l + r)/2;
		//Devide the orginal arr into two subarr
		mergeDevide(arr,l,m);//arr1
		mergeDevide(arr,m+1,r);//arr2

		//Then we will sort this two subarr
		mergeSort(arr,l,m,r);

	}

}

int main(int argc, char const *argv[])
{
	/* code */
	int a[7] = { 38 ,27,43,3,9,82,10};
	printf("Before:\n");
	for (int i = 0; i < 7; ++i)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	mergeDevide(a,0,6);
	printf("\nAfter:\n");
	for (int i = 0; i < 7; ++i)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}