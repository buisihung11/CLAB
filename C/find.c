#include <stdio.h>
#include <string.h>
char *s[]={
		"Hung: 1,2,3",
		"Bui: 1,4,5",
		"Si: 2,3,4"};
int Hung(char *a)
{
	
	return strstr(a,"Hung")|| strstr(a,"4");
}

void find(int (*name)(char *))
{
	for(int i=0;i<3;i++){
		if (name(s[i]))
			printf("%s\n",s[i] );
	}
}
int main()
{
	
	
	find(Hung);
	
	return 0;
}