#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "a.txt"

typedef struct 
{
	char *fromPlace;
	char *toPlace;
	//int dayAndSeat[NB_OF_DAY+1];
	int seat;
}flight;

flight* creatFlight(char *from,char *to, int seat1){
	//flight makeFly;
	flight* flightObj;
	flightObj = malloc(sizeof(flight));
	//flightObj = makeFly;
	flightObj -> fromPlace = strdup(from);
	flightObj -> toPlace = strdup(to);
	flightObj -> seat = seat1;
	// for(int i=0 ;i<NB_OF_DAY + 1; i++ ){
	// 	flightObj -> dayAndSeat[i] = seat;
	// }
	//free(flightObj);
	return flightObj;
}

flight** writeData(int *length1){
	FILE *f = fopen(FILE_NAME,"r");
	int length ;
	char from[30],to[30];
	int seat;
	flight** data ;
	if(!f){
		printf("Cannot open the file. Please check the file!\n");
	}else{
		//scanf number
		fscanf(f,"%d",&length);
		data = malloc(length*sizeof(flight *));
		//wirte the data
		for(int i=0 ;i<length;i++){
			fscanf(f,"%s %s %d",&from,&to,&seat);
			data[i] = creatFlight(from,to,seat);
		}
		*length1 = length;
		printf("Your data is uploaded!\n");
	}
	//free(data);
	fclose(f);
	return data;
}


int main(int argc, char const *argv[])
{
	
	flight ** allFlight;
	int numberOfFlight = 0;

	
	//save data to allFlight

	allFlight = writeData(&numberOfFlight);

	printf("%d\n", numberOfFlight );
	for(int i=0;i<numberOfFlight;i++){
		printf("%d. ",i );
		printf("From %s\n",(allFlight[i]) -> fromPlace );
		printf("To %s\n",(allFlight[i]) -> toPlace );
		printf("Seat %d\n",(allFlight[i]) -> seat );
	}

	// FILE *f = fopen(FILE_NAME,"r");
	// allFlight = (flight**) malloc(2*sizeof(flight*));
	// int total;
	// int seat,seat1;
	// char from[30],from1[30];
	// char to[30],to1[30];
	// fscanf(f,"%d",&total);
	// flight *fly1;
	// flight *fly2;
	// fscanf(f,"%s %s %d",&from,&to,&seat);
	// fly1 = creatFlight(from,to,seat);
	// fscanf(f,"%s %s %d",&from1,&to1,&seat1);
	// fly2 = creatFlight(from1,to1,seat1);


	// allFlight[0] = fly1;
	// allFlight[1] = fly2;
	// printf("Total: %d\n",  total);
	// // printf("From: %s\n",**allFlight -> fromPlace );
	// // printf("To: %s\n",**allFlight -> toPlace );
	// printf("From: %s==\n",(allFlight[0]) -> fromPlace );
	// printf("From: %s==\n",allFlight[1] -> fromPlace );
	// fclose(f);
	return 0;
	
}