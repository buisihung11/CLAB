#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50
#define FALSE 0
#define TRUE 1
int isExist(char *filename){
	int check = FALSE;
	FILE *f=fopen(filename,"r");
	if(f!=NULL){
		check = TRUE;
		fclose(f);
	}
	return check;
}
void writeData(char codes[][9], char names[][21],double salaries[],double allowances[], int n){
	FILE *f = fopen("data.txt","w");
	if(isExist("data.txt"))
	printf("FIle co tren disk\n");
	else printf("Khong co FIle co tren disk\n");
	fflush(stdin);
	for(int i=0;i<n;i++){
		fprintf(f,"%d\n",n);
		fprintf(f,"%s\n",codes[i]);
		fprintf(f,"%s\n",names[i]);
		fprintf(f,"%.3f\n",salaries[i]);
		fprintf(f,"%.3f\n",allowances[i]);
	}
	fclose(f);
}
void getData(char codes[][9], char names[][21],double salaries[],double allowances[], int *n){
	FILE *f = fopen("data.txt","r");
	fflush(stdin);
	if(isExist("data.txt"))
	printf("FIle co tren disk\n");
	else printf("Khong co FIle co tren disk\n");
	fflush(stdin);
	fscanf(f,"%d",n);
	for(int i=0;i<3;i++){
		
		fscanf(f,"%s",codes[i]);
		//fflush(stdin);
		fscanf(f,"%s",names[i]);
		//fflush(stdin);
		fscanf(f,"%.3f",salaries[i]);
		fscanf(f,"%.3f",allowances[i]);
	}
	fclose(f);
}
void printData(char codes[][9], char names[][21],double salaries[], int n){
	printf("\nSTT\t\tCode\t\t\t\tName\t\t\t\tSalaries\n");
	for(int i=0;i<n;i++){
		printf("%d\t\t%s\t\t\t\t%s\t\t\t\t%f\n",i+1,codes[i],names[i],salaries[i]);
	}
}

void add(char codes[][9], char names[][21],double salaries[],double allowances[], int n){
	fflush(stdin);
	printf("Nhap code: ");
	scanf("%8s",&codes[n]);
	fflush(stdin);
	printf("Nhap ten: ");
	scanf("%20[^\n]",&names[n]);
	//fflush(stdin);
	printf("Nhap so tien: ");
	scanf("%lf",&salaries[n]);
	//fflush(stdin);
	//	fflush(stdin);
	printf("Nhap so tien phu tro: ");
	scanf("%lf",&allowances[n]);
}
void swap(char codes[][9], char names[][21],double salaries[],double allowances[], int x,int y){
	//minus 1 for index
	x--;
	y--;
	char code_temp[9];
	char name_temp[21];
	double sala_temp;
	double allow_temp;
	//swap code
	strcpy(code_temp,codes[x]);
	strcpy(codes[x],codes[y]);
	strcpy(codes[y],code_temp);
	
	//swap name
	
	strcpy(name_temp,names[x]);
	strcpy(names[x],names[y]);
	strcpy(names[y],name_temp);

	//swap sala
	sala_temp = salaries[x];
	salaries[x]=salaries[y];
	salaries[y]=sala_temp;
	
	//swap allow
	allow_temp = allowances[x];
	allowances[x]=allowances[y];
	allowances[y]=allow_temp;
}
void xoaPhanTu(char codes[][9], char names[][21],double salaries[],double allowances[], int *nb,int pos){
	int n=*nb;
	for(int i= pos-1;i<n-1;i++){
		swap(codes,names,salaries,allowances,i,i+1);
	}
	
	*nb--;
}
int main(){
	char codes[MAX][9],names[MAX][21];
	double salaries[MAX];
	double allowances[MAX];
	int n=0; //number of employee
	int add_nb;
//	printf("Nhap so luong nhan vien: ");
//	scanf("%d",&add_nb);
//	for(int i=0;i<add_nb;i++){
//		add(codes,names,salaries,allowances,n);
//		n++;
//	}
	//ghi du lieu
//	write(codes,names,salaries,allowances,n);
//	printf("so nhan vien %d",n);
//	printData(codes,names,salaries,n);
	//chep du lieu tu file
	getData(codes,names,salaries,allowances,&n);
	printData(codes,names,salaries,n);
	//doi thu tu 
	swap(codes,names,salaries,allowances,1,2);
	printData(codes,names,salaries,n);
	//xoa phan tu
	xoaPhanTu(codes,names,salaries,allowances,&n,2);
	printf("\nso luong phan tu %d\n",n);
	printData(codes,names,salaries,n);
	return 0;
}
