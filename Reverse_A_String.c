#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// Mang chua cac word trong string
	char s[30][30]={};
	int length = 0;
	char c[30];
	printf("Nhap vao ten: ");
	gets(c);
	printf("\nChuoi truoc khi reverse la: %s\n",c);

	const char dim[2] = " ";
	char *token;
	token = strtok(c,dim);

	while(token!= NULL){
		//printf("%s\n", token);
		strcpy(s[length],token);
		length++;
		token = strtok(NULL,dim);
		
	}

	printf("\nChuoi sau khi reverse la: ");
	for(int i= length - 1 ;i>=0;i--){
		printf("%s ", s[i]);
	}
	



	return 0;
}