#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int main(){
	int sophantu;
	int mang[sophantu];
	printf("Nhap so phan tu:");
	scanf("%d",&sophantu);
	int mangphantu[sophantu];
	int *p=mangphantu;
	p=malloc(sizeof(sophantu));
	for(int i=0;i<sophantu;i++){
		printf("Nhap phan tu thu %d:",i+1 );
		scanf("%d",&mangphantu[i]);
		scanf("%d",p[i]);
	}
	for (int i = 0; i < sophantu; ++i)
	{
		printf("Phan tu thu %d la %d\n",i+1,mangphantu[i]);
		printf("C2: Phan tu thu %d la %d\n",i+1,p+i );
	}
	return 0;
}