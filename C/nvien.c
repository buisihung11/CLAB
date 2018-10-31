#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct nhanvien
{
	int manv;
	char hoten[30];
}nhanvien;
/*void input(nhanvien nbnv[],int in);
void output(nhanvien nbnv[],int in);*/
void input(nhanvien nbnv[],int in)
{
	char ctam[10];
	for(int i=0;i<in;i++){
		printf("Nhap vao ma nhan vien thu %d\n",i+1 );
		gets(ctam);
		nbnv[i].manv= atoi(ctam);
		printf("Nhap vao ho ten:\n");
		gets(nbnv[i].hoten);
	}
}
void output(nhanvien nbnv[],int in)
{
	for (int i = 0; i < in; ++i)
	{
	    //if (nbnv[i].hoten)
		printf("%5d   %5s\n",nbnv[i].manv,nbnv[i].hoten );
		//else break;
	}

}
void change(nhanvien x[],int in)
{
	nhanvien old;
	for(int i=0;i<in-1;i++)
		for (int j = i+1; j < in; ++j)
		{
			if(strcmp((x[i].hoten),(x[j].hoten))>0)
			{
				old=x[i];
				x[i]=x[j];
				x[j]=old;
			}
		}
}

int main()
{
	nhanvien nhap[50];
	char ctam[10];
	int in;

	printf("Nhap vao so nhan vien\n");
	gets(ctam);
	in = atoi(ctam);

	input(nhap,in);
	output(nhap,in);
	puts("-----------");
	change(nhap,in);
	output(nhap,in);
	return 0;
}
