#include <stdio.h>
#define MAX 50

void printData(char codes[][9], char names[][21],double salaries[],double allowances[], int n){
	printf("\nSTT\t\tCode\t\t\t\tName\t\t\t\tSalaries\n");
	for(int i=0;i<n;i++){
		printf("%d\t\t%s\t\t\t\t%s\t\t\t\t%f\n",i+1,codes[i],names[i],salaries[i]);
	}
}

void add(char codes[][9], char names[][21],double salaries[],double allowances[], int n){
	printf("Nhap code: ");
	scanf("%8s",codes[n]);
	printf("Nhap ten: ");
	scanf("%20[^\n]",names[n]);
	printf("Nhap so tien: ");
	scanf("%f",salaries[n]);
	printf("Nhap so tien phu tro: ");
	scanf("%f",allowances[n]);
	printData(codes,names,salaries,allowances,n);
}

int main(){
	char codes[MAX][9],names[MAX][21];
	double salaries[MAX];
	double allowances[MAX];
	int n=0; //number of employee
	int add_nb;
	printf("Nhap so luong nhan vien: ");
	scanf("%d",&add_nb);
	for(int i=0;i<add_nb;i++){
		add(codes,names,salaries,allowances,n);
		n++;
	}


	return 0l;
}
