#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

 union det
{
	 int win;
	 int lose;
	 int draw;
	int total;

};

void input(union det x[],int i)
{
	for(int i=0;i<3;i++){
		printf("Nhap %d\n",i+1 );
		scanf("%d %d %d",&(x[i].win),&(x[i].lose),&(x[i].draw));
		x[i].total= x[i].total + 3*(x[i].win) - x[i].lose ;
	}
}

void output(union det detail[])
{
	for (int i = 0; i < 3; ++i)
	{
		printf("detail %d \t %d \t %d \t %d \t %d \n",i+1,detail[i].win ,detail[i].lose,detail[i].draw,detail[i].total);
	}
}

int main(int argc, char const *argv[])
{
	union det detail;
	union det *point;
	point=&detail;
	/*for(int i=0;i<3;i++){
		printf("Nhap %d\n",i+1 );
		scanf("%f %d %d",&(detail[i].win),&(detail[i].lose),&(detail[i].draw));
		detail[i].total= detail[i].total + 3*(detail[i].win) - detail[i].lose ;
	}*/
	printf("Nhap detail \n");
	scanf("%d %d %d",point->win,point->lose,point->draw);
	point->total=point->total +3 ;
	for (int i = 0; i < 3; ++i)
	{
		printf("detail %d \t %d \t %d \t %d \t %d \n",i+1,detail.win ,detail.lose,detail.draw,detail.total);
	}

	/*input(detail,3);
	for (int i = 0; i < 3; ++i)
	{
		printf("detail %d \t %d \t %d \t %d \t %d \n",i+1,detail[i].win ,detail[i].lose,detail[i].draw,detail[i].total);
	}

	output(detail);*/
	return 0;
}
