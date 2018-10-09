#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define ALIVE 1
#define DEADED 0
int main(int argc, char const *argv[])
{
	int amount;
	int deathNum;
	int peopleStillAlive;
	int* listPeople;
	printf("Enter number of people: ");
	scanf("%d",&amount);
	listPeople = (int*) malloc(amount*sizeof(int));
	peopleStillAlive = amount;
	printf("PeopleStill Alive %d\n", peopleStillAlive );
	//create people status
	for(int i=0;i<amount;i++){
		listPeople[i] = ALIVE;
	}

	printf("Enter death number: ");
	scanf("%d",&deathNum);

	//Start count
	int count = 0;

	int i=0;// count for loop
	while(peopleStillAlive >= deathNum){
		if(listPeople[i] == ALIVE){
			count++;
		}
		
		if( count == deathNum ){
			//printf("People Died At %d\n",i+1 );
			count = 0;
			listPeople[i] = DEADED;
			--peopleStillAlive;
		}
		//printf("PeopleStill Alive %d\n", peopleStillAlive );
		i++;
		if(i==amount){
			i=0;
		}
	}

	printf("People Still alive\n");
	for(int i=0;i<amount;i++){
		if(listPeople[i]==ALIVE){
			printf("%d\t",i+1 );
		}
	}

	free(listPeople);
	return 0;
}