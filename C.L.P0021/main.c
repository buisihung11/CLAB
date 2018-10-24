#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define FORMAT 3

int getDayOfMonth(int mm,int yy){
	int number;
	switch(mm){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
			
			number = 31;
			break;
		case 4 : case 6: case 9: case 11: 
			number = 30;
			break;
		case 2: 
			if(yy % 4 ==0 ){
				number = 29;
			}else{
				number = 28;
			}	
			break;
	}
	return number;
}

int isValidDate(int yy,int mm,int dd){
	int result = FALSE;
	
	int isValidYear = (yy<1900 || yy > 2999 ) ? FALSE : TRUE;
	int isValidMonth = ( mm<1 || mm > 12 ) ? FALSE : TRUE;
	int isValidDay = (dd>0 && dd<=getDayOfMonth(mm,yy)) ? TRUE : FALSE;
	
	if((isValidDay && isValidMonth && isValidYear)){
		// printf("Valid date\n");
		result = TRUE;
	}
	return result;
}

void convertToNumber(int *yy,int* mm,int * dd,char data[3][30]){
	*yy = atoi(data[2]);
	*mm = atoi(data[1]);
	*dd = atoi(data[0]);
}
// int* convertToNumberV2(char data[3][30]){
// 	int* ptrTemp;
// 	int arrTemp[3];
// 	arrTemp[0] = atoi(data[2]);
// 	arrTemp[1] = atoi(data[1]);
// 	arrTemp[2] = atoi(data[0]);
// 	ptrTemp = arrTemp;
// 	return ptrTemp;
// }


int calculateDOY(int yy,int mm,int dd){
	int result = dd;
	for(int i=1;i<mm;i++){
		result  = result+ getDayOfMonth(i,yy);
		
	}
	return result;
}
double calculateWOY(int yy,int mm,int dd ){
	double doy = (double) calculateDOY(yy,mm,dd);
	return ceil(doy/7);
}
int isValidInput(char data[3][30]){
	int result = TRUE;
	for (int i = 0; i< 3 && result == TRUE; ++i)
	 {
	 	for (int j = 0; j < strlen(data[i]); ++j)
	 	{
	 		char c = data[i][j];
	 		if(c<'0' || c > '9'){
	 			result = FALSE;//FALSE
	 		}
	 	}
	 } 
	 return result;
}


int calculateDOW(int yy,int mm,int dd){
	//Apply Schwerdtfeger's method
	int eArray[12] = {0,3,2,5,0,3,5,1,4,6,2,4};
	int fArray[4] = {0,5,3,1};
	int c,g;
	if(mm<3){
		c = (yy-1)/100;
		g = yy - 1 -100*c;
		
	}else{
		c = yy/100;
		g = yy-100*c;
	}

	int w;
	w = dd + eArray[mm-1] + fArray[c%4] + g + g/4;
	
	return w%7;

}

void displayResult(int yy,int mm,int dd ){
	printf("Day of Year %d \n",calculateDOY(yy,mm,dd) );
	printf("Week of Year %d \n",(int)calculateWOY(yy,mm,dd) );
	switch(calculateDOW(yy,mm,dd) ){
		case 0:
			printf("Day of Week Sunday\n");
			break;
		case 1:
			printf("Day of Week Monday\n");
			break;
		case 2:
			printf("Day of Week Tuesday\n");
			break;
		case 3:
			printf("Day of Week Wednessday\n");
			break;
		case 4:
			printf("Day of Week Thursday\n");
			break;
		case 5:
			printf("Day of Week Friday\n");
			break;
		case 6:
			printf("Day of Week Saturday\n");
			break;
							
	}
}

void mainFunction(){
	char stringInput[3][30];
	int yy,mm,dd;
	// int *ptr;
	do{
		char input[10];	
		printf("Please enter date with format is dd/mm/yy: ");
		scanf("%s",&input);

		const char* dim = "/";
		char* token;
		token = strtok(input,dim);
			
		int length = 0;
		while(token){
			char* temp;
			temp = (char* ) malloc (strlen(token)*sizeof(char));
			strcpy(temp,token);
			// stringInput[length] = temp;
			strcpy(stringInput[length],temp);
			token=strtok(NULL,dim);
			length++;
		}

		//check is valid input
		if(isValidInput(stringInput)){
			
			//convert to interger and check
			convertToNumber(&yy,&mm,&dd,stringInput);
			
			// ptr = convertToNumberV2(stringInput);
			
		}else{
			printf("Sorry please enter data again follow with the format\n");

		}
	}while(!isValidDate(yy,mm,dd));
	//Show result


	displayResult(yy,mm,dd);
}


int main(int argc, char const *argv[])
{
	
	// int data[3];
	int exit;
	do{
		mainFunction();
		printf("DO you want to continue\n");
		fflush(stdin);
		exit = toupper(getchar());
	}while(exit!='?');
	
	

	
	return 0;
} 