#include <stdio.h>

int fibonanci(int x){
	if(x==1 || x == 2 ){
		return 1;
	}
	return fibonanci(x - 2 ) + fibonanci(x-1);
}

int recursion(int x){
	if(x==1){
		return 1;
	}
	return recursion(x-1) + x;
}

 int main(int argc, char const *argv[])
{
	// printf("%d\n",fibonanci(5) );
	int a;
	scanf("%d",&a);
	printf("%d",recursion(a));
	return 0;
}