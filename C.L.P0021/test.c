#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int * getArr(){
	int arr[]= {4,33,1};
	int *ptr2;
	// ptr= (int* ) malloc(3*sizeof(int));
	ptr2 = arr;
	return ptr2;
}
int * getArrPre(){
	int * ptr1;
	ptr1  = getArr();
	return ptr1;
}
int main(int argc, char const *argv[])
{
	int arr[]= {4,33,1};
	int (*ptr0)[3];
	// ptr0 = getArrPre();
	// //printf("Arr %d %d %d\n", arr[0],arr[1],arr[2]);
	// printf("PtrArr %d %d %d\n", *ptr0,*(ptr0+1),ptr0[2]);
	int *ptr;
	ptr = arr;
	ptr0 = &arr;
	printf("PtrArr %d %d %d\n", *ptr,*(ptr+1),ptr[2]);
	printf("PtrArr0 %d %d %d\n", *ptr0,*(ptr0+1),ptr0[2]);
	
	
	return 0;
}