#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int main(int argc, char const *argv[])
{
	// char c[20] = "a1230478";
	// int strLen = strlen(c);
	// char *str = (char *) malloc(strLen*sizeof(char));
	// strcpy(str,c);
	// printf("Strlen %d\n", strLen);
	// int x = atoi(c);
	// printf("%s", str);
	// printf("x la %d\n",x );
	// for (int i = 0; i < strLen; ++i)
	// {
	// 	/* code */
	// 	if(str[i] < 48 || str[i] > 55){
	// 		printf("FALSE %c\n",str[i] );
	// 	}else{
	// 		printf("TRUE\n");.
	// 	}
	// }
	// char c='0';
	// int check = (c>=48 && c<= 57 ) ? TRUE : FALSE ;
	// printf("check %d\n", check);
	// char c = 'B';
	// int x = c -'A';
	// printf("%d\n",x );
	char exit;
	do{
		fflush(stdin);
		printf("Haha\n");
		exit = getchar();
		printf("%d\n",exit );
	}while(exit!=27);
	return 0;
}