#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define TRUE 1
#define FALSE 0
#define BINARY 2
#define OCTAL 8
#define HEX 16

char* getInput(){
	char c[50];
	scanf("%s",&c);
	int strLen = strlen(c);
	char *str = (char *) malloc(strLen*sizeof(char));
	strcpy(str,c);
	return str;
}

int isBinary(char *str){
	int result = TRUE;
	for(int i=0;str[i]!='\0';i++){
		if(str[i] !='0' && str[i]!='1'){
			
			result = FALSE;
			break;
		}
	}
	return result;
}

int isOctal(char *str){
	int result = TRUE;
	for(int i=0;str[i]!='\0';i++){
		if(str[i] < 48 || str[i] > 55){ // 48 = '0' 55 = '7'
			//printf("FALSE %c\n",str[i] );
			result = FALSE;
			break;
		}
	}
	return result;
}

int isHexa(char *str){
	int result = TRUE;
	for(int i=0;str[i]!='\0';i++){
		char c = str[i];
		int isInNumberRange = (c>=48 && c<= 57 ) ? TRUE : FALSE ;
		int isInAToFRange = ( (c>=65 && c<=70) || (c>=97 && c<=102)) ? TRUE : FALSE;

		if(!(isInNumberRange || isInAToFRange)){
			result = FALSE;
			printf("FALSE %c\n",c);
			break;
		}
	}
	return result;
	
}
int convertToDecimal(int heCoSo,char* str){
	int result = 0;
	int surplus; //sodu
	int index = 0;
	int value;
	//truong hop tu binary,octal
	if(heCoSo == BINARY || heCoSo == OCTAL){

		value = atoi(str);
		while(value!=0){
		surplus = value %10;
		result += surplus * pow((double)heCoSo,index);
		value /= 10;
		index++;
		}
	}
	//Truong hop la hexa
	if(heCoSo == HEX){
		for(int i= strlen(str)-1;i>=0;--i){
			
			char c = str[i];
			int isInNumberRange = (c>=48 && c<= 57 ) ? TRUE : FALSE ;
			int isInAToFUpperRange = ( (c>=65 && c<=70) ) ? TRUE : FALSE;
			int isInaTofLowerRange = (c>=97 && c<=102) ? TRUE : FALSE;

			int currentNumber;

			if(isInNumberRange){
				currentNumber = c - '0' ;
				
			}
			if(isInAToFUpperRange){
				currentNumber = c - 'A' + 10;
			}
			if(isInaTofLowerRange){
				currentNumber = c - 'a' + 10;
			}
			printf("Current Number %d\n",currentNumber );
			result += currentNumber * pow((double)heCoSo,index);
			index++;
		}
	}
	
	return result;
}


void menu1(){
	char *str;
	do{
		printf("Enter binary number: ");
		str = getInput();
		if(!isBinary(str)){
			printf("NOT Binary\n");
			printf("Please enter again!\n");
		}
	}while(!isBinary(str));
	
	
	printf("Decimal number is %d\n",convertToDecimal(BINARY,str) );
	
}

void menu2(){
	char *str;
	do{
		printf("Enter octal number: ");
		str = getInput();
		if(!isOctal(str)){
			printf("NOT Octal\n");
			printf("Please enter again!\n");
		}
	}while(!isOctal(str));
	
	
	printf("Decimal number is %d\n",convertToDecimal(OCTAL,str) );
}

void menu3(){
	char *str;
	do{
		printf("Enter hexa number: ");
		str = getInput();
		if(!isHexa(str)){
			printf("NOT Hexa\n");
			printf("Please enter again!\n");
		}else{
			printf("is Hexa %s\n",str );
			
			printf("Decemal number is %d\n", convertToDecimal(HEX,str));
		}
	}while(!isHexa(str));
	
	// int value = atoi(str);
	// printf("Decimal number is %d\n",convertToDecimal(OCTAL,value) );
}

void menu(){
	int choice;
	char exit;
	int x;
	do{
		printf("1.	Convert binary number to decimal number\n");
		printf("2.	Convert octal number to decimal number\n");
		printf("3.	Convert hexadecimal number to decimal number\n");
		printf("4.	Exit\n");
		printf("Please choice number (1-4): ");
		fflush(stdin);
		x = scanf("%d",&choice);
		if(x==0){
			printf("Please enter a number\n");
			continue;
		}
		if(choice<0 || choice > 4){
			printf("Please choice number (1-4)!\n");
			continue;
		}
		switch(choice){
			case 1: 
				menu1();
				// do{
					
				// 	printf("Press enter to continue, Esc to return the main menu\n" );
				// 	fflush(stdin);
				// 	scanf("%c",&exit);
				// }while( exit != 27);
				
				break;
			case 2:
				menu2();
				break;	
			case 3: 
				menu3();
				break;	

		}
		
		
	}while(x==0 || choice != 4);
}

int main(int argc, char const *argv[])
{
	/* code */
	menu();
	return 0;
}