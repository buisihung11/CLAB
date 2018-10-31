#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct 
	{
		char h1[10];
		char h2[10];
	}name;
void input(name x){
	puts("Nhap h1,h2");
	gets(x.h1);
	gets(x.h2);
	printf("-----h1 %s \t h2 %s\n",x.h1,x.h2 );
}
int main(int argc, char const *argv[])
{
	
	name get;
	input(get);
	printf("h1 %s \t h2 %s\n",get.h1,get.h2 );
	return 0;
}