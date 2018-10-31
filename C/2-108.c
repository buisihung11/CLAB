#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct
{
	char name[20];
	char address[30];
}location;
//Nhap du lieu
void input(location x[],int in)
{
	for (int i=0;i<in;i++){
		printf("Nguoi thu %d:\n",i+1 );
		printf("Nhap ten :");
		gets(x[i].name);
		printf("Nhap dia chi: ");
		gets(x[i].address);
		puts("------");
	}
}
location copy[30];
//Sapxep
void change(location x[],int in)
{

	location temp;
	//saochep
	for(int i=0;i<in;i++){
        copy[i]=x[i];
	}
	for (int i = 0; i < in; ++i)
	{

		for (int j=i+1;j<in;j++)
			if (strcmp(x[i].name,x[j].name)>0)
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
	}
}
//Xuat du lieu
void output(location x[],int in)
{
	puts("Danh sach chua sap xep:\t\t Danh sach da sap xep:\n");
	for (int i = 0; i < in; ++i)
	{
		printf("%s at %s \t\t\t\t %s at %s\n",copy[i].name,copy[i].address,x[i].name,x[i].address );
	}
}
int main(int argc, char const *argv[])
{
	location x[10];
	char ctam[10];
	int in=4;
	/*printf("Nhap vao so nguoi:  ");
	scanf("%s",ctam);
	in = atoi(ctam);*/
	input(x,in);
	change(x,in);
	output(x,in);
	return 0;
}
