#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
	{
		unsigned int day;
		unsigned int month;
		unsigned int year;
	}birt;

typedef struct
	{
		unsigned int math;
		unsigned int physic;
		unsigned int chemis;
	}mar;

typedef struct
{
	char name[30];
	birt birth;
	char truong[30];
	char sbd[30];
	mar mark;
	int total;
}detail;
void input(detail det[],int in)
{
	for (int i = 0; i < in; ++i)
	{
		printf("Thi sinh thu %d:\n", i+1);
		fflush(stdin);
		printf("\tNhap ten:");
		fgets(det[i].name,sizeof(det[i].name),stdin);
		printf("\tNhap ngay\\thang\\nam:");
		scanf("%d %d %d",&det[i].birth.day,&det[i].birth.month,&det[i].birth.year);
		printf("\tNhap ten truong:");
		fflush(stdin);
		fgets(det[i].truong,sizeof(det[i].truong),stdin);
		printf("\tNhap so bao danh:");
		fflush(stdin);
		gets(det[i].sbd);
		printf("\tNhap diem Toan,Ly,Hoa");
		scanf("%d %d %d",&det[i].mark.math,&det[i].mark.physic,&det[i].mark.chemis);
		puts("-----------");
		det[i].total=det[i].mark.math + det[i].mark.physic + det[i].mark.chemis;
	}
}
void output(detail x[],int in)
{
	for (int i = 0; i < in; ++i)
	{
		printf("Thi sinh thu %d\n",i+1 );
		printf("\tName: %s\n",x[i].name );
		printf("\tSo bao danh%s\n",x[i].sbd );
		printf("\tDiem thi: Toan %d \t Ly %d \t Hoa %d\n",x[i].mark.math,x[i].mark.physic,x[i].mark.chemis );
		puts("----------\n");
	}
}
int main(int argc, char const *argv[])
{
	int in;
	printf("Nhap so thi sinh (<10)\n");
	scanf("%d",&in);
	detail det[in];
	input(det,in);
	output(det,in);
	return 0;
}
