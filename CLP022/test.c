#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char s[50],s1[50];
	// FILE *f = fopen("a.txt","r");
	int x;
	printf("Nhap\n");
	x = scanf("%[^#]s %[^#]s",&s,&s1);

	printf("%s = %s =\n %d", s,s1,x);
	return 0;
}
while( fscanf(f , "#%40[^;];%40[^;];%40[^;];%lf\n",code[*pn],name[*pn],DoB[*pn],&point[*pn])==4)
			(*pn)++;