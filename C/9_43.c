#include <stdio.h>
#include <string.h>

//char *place={"Canada","England","France","Germany","India","Isrel","Italy","Japan"};
int main()
{
	char c[80];
	while (c!=".")
	{
		puts(c);
		puts("Enter your country u want:");
		scanf("%79s",c);
		if (strstr(c,"end"))
			break;
		if (strstr(c,"Canada"))
			puts("Ottaws is thu do");
		else 
			printf("Again\n");
	}
	return 0;
}