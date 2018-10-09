#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void inc(int *a){
	*a = *a +1;
}
int main(int argc, char const *argv[])
{
	int a=0;
	inc(&a);
	printf("%d\n",a );
	return 0;
}