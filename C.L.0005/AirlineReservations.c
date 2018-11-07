#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NB_OF_DAY 7
#define FILE_NAME "a.txt"
#define TRUE 1
#define FALSE 0



//Data Structure
typedef struct 
{
	char *fromPlace;
	char *toPlace;
	//nt seat;
	int dayAndSeat[NB_OF_DAY+1];
}flight; 


//define function
// flight* creatFlight(char *from,char *to, int seat);
// flight** writeData(int *count);

flight* creatFlight(char *from,char *to, int seat){
	flight* flightObj;
	flightObj = malloc(sizeof(flight));
	//thay strdup bang malloc mot char* 
	flightObj -> fromPlace = strdup(from);//make a copy of from because we use ptr to fromPlace
	flightObj -> toPlace = strdup(to);
	//flightObj -> seat = seat1;
	for(int i=0 ;i<NB_OF_DAY + 1; i++ ){
		flightObj -> dayAndSeat[i] = seat;
	}
	
	return flightObj;
}
flight** writeData(int *count){
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
		data = malloc(length*sizeof(flight *));//tra ve kieu void
		
		//wirte the data
		for(int i=0 ;i<length;i++){
			fscanf(f,"%s %s %d",&from,&to,&seat);
			data[i] = creatFlight(from,to,seat);
		}
		*count = length;
		printf("Your data is uploaded!\n");
	}
	

	fclose(f);
	return data;
}

int hasFlight(char *from,char *to,char userGoFrom[30],char userGoTo[30]){
	int check = FALSE;
	//neu nhu truon ghop so sanh ignore case thi phai lopp tung ki tu 
	
	if(strstr(userGoFrom,from)>0 && strstr(userGoTo,to)>0){
			check = TRUE;
		}
	
	return check;
}

int isValidDay(int dayleave, int dayreturn){
	int check = TRUE;
	if( dayleave<0 || dayleave >NB_OF_DAY){
		check =FALSE;
		
	}
	if( dayreturn<0 || dayreturn >NB_OF_DAY || dayreturn < dayleave){
		check =FALSE;
		
	}
	return check;
}



//, int dayleave, int dayreturn, int nbOfSeat
void updateData(flight** data,int totalFlight){
	
		char firstName[30],lastName[30];
		char goFrom[30], goTo[30];
		int dayleave,dayreturn;
		int nbOfSeat;

			printf("Enter your firstname and lastname follow\n");
			scanf("%s %s",&firstName,&lastName);
			printf("From which city do you want to fly?\n");
			scanf("%s",&goFrom);
			printf("Where is your destination?\n");
			scanf("%s",&goTo);
			printf("Which day do you want to leave\n");
			scanf("%d",&dayleave);
			printf("Which day do you want to comeback\n");
			scanf("%d",&dayreturn);
			printf("How many seat do you want.\n");
			scanf("%d",&nbOfSeat);

	char *from,*to;
	int check = FALSE;
	for (int i = 0; i < totalFlight; ++i){
		from = data[i] -> fromPlace;
		to = data[i] -> toPlace;
		if(hasFlight(from,to,goFrom,goTo)){
			check = TRUE;
			if(isValidDay(dayleave,dayreturn)){
					int seatRestLeave =  data[i] -> dayAndSeat[dayleave-1];
					int seatRestReturn = data[i] -> dayAndSeat[dayreturn-1];
					if(seatRestReturn<nbOfSeat || seatRestLeave<nbOfSeat){
						printf("Sorry that reservation could not be made.\n");
						printf("There aren't enought seat for your flights\n" );
					}else{
						
						//Start Change Data
						data[i] -> dayAndSeat[dayleave-1] -= nbOfSeat;
						data[i] -> dayAndSeat[dayreturn-1] -= nbOfSeat;
						printf("Thanks your resevation has been made.\n");
						}
				}else{
					printf("Sorry that reservation could not be made.\n");
					printf("The day of flights are not valid\n" );
					break;
			}
			
		}

	}
	if(!check){
			printf("Sorry that reservation could not be made.\n");
			printf("We don't have flights from %s to %s \n",goFrom,goTo );
			
		}
}

void printList(flight** data,int totalFlight){
	char *from,*to;
	for (int j = 0; j < NB_OF_DAY; ++j)
	{
		printf("Day %d\n",j+1);
		for (int i = 0; i < totalFlight; ++i)
		{
			from = data[i] -> fromPlace;
			to = data[i] -> toPlace;
			int availableSeat = data[i] -> dayAndSeat[j];
			
			printf("To %s from %s Available Seats %d\n",to,from,availableSeat);
		}
	}
	
}

void menu(flight** data,int length){
	int userChoice;
	do{
		
		
		printf("Which of these following choices do you want?\n");
		printf("1. Make a reservation\n");
		printf("2. Print out the listing of all flights\n");
		printf("3. Quit\n");
		fflush(stdin);
		scanf("%d",&userChoice);
		if(userChoice<0 || userChoice > 3){
			printf("Please enter number from 1-3\n");
			continue;
		}
		if(userChoice==3){
			break;
		}else{
			//get user input
			switch(userChoice){
				case 1: updateData(data,length);
					break;
				case 2: printList(data,length);
					break;
			}
			
			

			
		}
	}while(userChoice!=3);
}

int main(int argc, char const *argv[])
{
	flight ** allFlight ;
	int numberOfFlight = 0;
	//save data to allFlight
	allFlight = writeData(&numberOfFlight);

	menu(allFlight,numberOfFlight);


	return 0;
}