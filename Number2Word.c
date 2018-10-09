#include<stdio.h>
#include <string.h>

void docHangLe(int num);
void docHangChuc(int num);

void docHangLe(int num){
	switch(num){
		case 1: 
		printf("One");
		break;
		case 2: 
		printf("Two");
		break;
		case 3: 
		printf("Three");
		break;
		case 4: 
		printf("Four");
		break;
		case 5: 
		printf("Five");
		break;
		case 6: 
		printf("Six");
		break;
		case 7: 
		printf("Seven");
		break;
		case 8: 
		printf("Eight");
		break;
		case 9: 
		printf("Nine");
		break;
		default: break;
	}
}

void docHangChuc(int num){
	switch(num){
		case 1: 
		printf("Ten");
		break;
		case 2: 
		printf("Twenty");
		break;
		case 3: 
		printf("Thirty");
		break;
		case 4: 
		printf("Fourty");
		break;
		case 5: 
		printf("Fifty");
		break;
		case 6: 
		printf("Sixty");
		break;
		case 7: 
		printf("Seventy");
		break;
		case 8: 
		printf("Eighty");
		break;
		case 9: 
		printf("Ninety");
		break;
		default: break;
	}
}

int main(int argc, char const *argv[])
{
	
	int cont;
	do{
		int amount;
		fflush(stdin);
		printf("\nNhap so tien:");
		scanf("%d",&amount);
		int arr[10];
		int length = 0;
		//truyen cac chu so vao arr[]
		for(int i=0;amount!=0;i++){
			arr[i]=amount%10;
			amount/=10;
			length++;				
		}
		//bat dau convert
		printf("Your bill are totally : ");
		for(int i= length;i>0;i--){
			int a = i%3;
			if(a==1 || a==0){
				docHangLe(arr[i-1]);
				if(a==0){
					printf(" Hundred ");
				}
				printf(" ");
				if(i==4){
					printf(" Thousand ");
				}
			} else {
				printf(" ");
				docHangChuc(arr[i-1]);	
			}
		}
		fflush(stdin);
		printf("\nPress any key to continue. ESC to exit: ");
		
		cont = getchar();
		// fflush(stdin);
		printf("exit %d\n",cont );
	}while(cont!=27);
	

	return 0;
}