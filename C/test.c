#include <stdio.h>
int main()
{
	char s[80];
	char *name=s;
	printf("Your name:\n");
	scanf("%s",s);
	printf("Your name is : %s",*name);
	return 0;
}