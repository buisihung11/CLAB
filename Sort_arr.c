#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void nhapMang(int a[],int n){
	
	for(int i=0;i<n;i++){
		printf("Nhap %d: ",i+1);
		scanf("%d",&a[i]);
	}
}

void xuatMang(int a[],int n){
	printf("\n");
	for(int i=0;i<n;i++){
		printf("%d\t ",*(a+i));		
	}
	printf("\n");
}

void sortAcsending(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp;
				temp=a[i];
				a[i]= a[j];
				a[j]= temp;
			}
		}
	}
}

void sortDesending(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int temp;
				temp=a[i];
				a[i]= a[j];
				a[j]= temp;
			}
		}
	}
}

// int* addValue(int a[],int *n, int value){
	
// 	*(a+*n) = value;
// 	*n++;
// 	return a;
// }
//*n++ kh duoc cong vao ngay
void addValue(int a[],int *n, int value){
	
	*(a+*n) = value;
	++*n;
	
}


int main(int argc, char const *argv[])
{
	int *a;//mang 
	int n;//chieu dai cua mang
	printf("Nhap vao so luong phan tu: ");
	scanf("%d",&n);
	a = (int*)malloc((n)*sizeof(int));
	nhapMang(a,n);
	xuatMang(a,n);
	sortAcsending(a,n);
	xuatMang(a,n);

	int addtionalValue;
	printf("Nhap vao so can them: ");
	scanf("%d",&addtionalValue);
	
	// int *ptr_a;
	// ptr_a = addValue(a,&n,addtionalValue);
	addValue(a,&n,addtionalValue);
	printf("So n la %d\n", n);
	// printf("Xuat mang ptr_a: \n");
	// xuatMang(ptr_a,n);
	// sortDesending(ptr_a,n);
	xuatMang(a,n);
	sortDesending(a,n);
	xuatMang(a,n);
	free(a);
	return 0;
}