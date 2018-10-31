#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct det {
	unsigned int win;
	unsigned int lose;
	unsigned int draw;
	int total;
	
}det;
	     
typedef struct      
{     
	char name[30];     
	det detail;     
	     
}soccer;
void input(soccer x[],int in)
{
	for (int i=0;i<in;++i){
		printf("Nhap ten doi bong thu %d\n",i+1 );
		fgets(x[i].name,sizeof(x[i].name),stdin);
		printf("So tran thang,tran thua,tran hoa:");
		
		scanf("%d %d %d",&x[i].detail.win,&x[i].detail.lose,&x[i].detail.draw);
		fflush(stdin);
		puts("--------------\n");
		x[i].detail.total=3*(x[i].detail.win) + 1*(x[i].detail.draw);
	}
}
void output(soccer x[],int in)
{
	puts("\t\t Win \t Draw \t Lose\n");
	for (int i = 0; i < in; ++i)
	{
		printf("\nTeam %s\t\t %d \t %d \t %d \t %d\n",x[i].name,x[i].detail.win,x[i].detail.draw,x[i].detail.lose,x[i].detail.total);
	}
	
}
void sort(soccer x[],int in)
{
    puts("----------");
    for (int i = 0; i < in; ++i)
	{
		printf("\nTeam %s \t\t %d \t %d \t %d \t %d\n",x[i].name,x[i].detail.win,x[i].detail.draw,x[i].detail.lose,x[i].detail.total);
	}
    int max=x[0].detail.total,nb_max=0;
    int min=x[0].detail.total,nb_min=0;
    for(int i=0;i<in-1;i++){
        for(int j=i+1;j<in;j++)
        {
            if(x[j].detail.total>max)
            {
                max=x[j].detail.total;
                nb_max=j;
            }
           else if(x[j].detail.total<min)
            {
                min=x[j].detail.total;
                nb_min=j;
            }
        }
    }
    printf("Team co hieu so lon nhat la team %d - %s voi so diem %d",nb_max+1,x[nb_max].name,max);
    printf("\nTeam co hieu so nho nhat la team %d -%s voi so diem %d",nb_min+1,x[nb_min].name,min);
}
int main(int argc, char const *argv[])
{
	int in=3;
	soccer x[10];
	input(x,in);
	output(x,in);
	sort(x,in);
	return 0;
}