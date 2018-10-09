#include <stdio.h>
#include <string.h>
#include <ctype.h>
int	main(int argc, char const *argv[])
{
	// 2d arr 1d -  is character in number
	//		  2d -  is number that character exit in the String
	char characterByNum[2][52]={0}; // we have 26 character from a - b , and A-B
	int length = 0;//length for above arr
	
	char str[30];
	printf("Nhap chuoi: ");
	gets(str);
	printf("%s\n",str );
	
	int a=0;
	while(str[a]!='\0'){
		printf("%c\n", str[a]);
		int letter = str[a];
		if(letter >=97 && letter <=122){ // convert a-z to number
			letter = letter - 'A' - 6;
		}
		if(letter>= 65 && letter <=90){
			letter = letter - 'A';
		}
		printf("%d\n", letter);
		if(characterByNum[1][letter]==0){ // check wherethe the character repeat
			characterByNum[0][length]=letter;
		}
		
		characterByNum[1][letter]++;

		a++;
		length++;
	}
	//Print the character
	printf("\n=======\n");
	for (int i = 0; i < length; ++i)
		{
			int index = characterByNum[0][i];
			int value; 
			if(index>=0 && index <=25){
				value = index + 'A';
			}else{
				value = index + 'A' + 6;
			}
			printf("%c\t", value);
		}
	//Print The number that character exist
		printf("\n");
	for(int i = 0 ; i<length;i++){
		int index = characterByNum[0][i];
		printf("%d\t", characterByNum[1][i]);
	}
	//find the max value 
	// int maxVal = 0;
	// for(int i=0 ; i<length; i++){
	// 	int index = characterByNum[0][i];
	// 	if(characterByNum[1][index] > maxVal){
	// 		maxVal = characterByNum[1][index];
	// 	}
	// }
	return 0;
}