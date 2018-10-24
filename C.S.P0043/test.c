#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int* ptr;
	ptr= (int*) malloc(6*sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		*(ptr+i)= i+ 1;
	}
	for (int i = 0; i < 5; ++i)
	{
		printf("===%d\t", ptr[i]);
	}
	int * ptr2;
	ptr2 = (int*) malloc(6*sizeof(int));
	ptr = &ptr[1];
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\t", *(ptr+i));
	}
	ptr =NULL;
	
	return 0;
}