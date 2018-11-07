#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0


typedef struct{
	char* id;
	char* name;
	char* category;
	double price;
}Food;
Food* createItem(char* idItem,char* nameItem,char * categoryItem,double priceItem){
	
	Food* item;
	char *newId, *newName,*newCategory;
	newId = (char*) malloc(strlen(idItem)*sizeof(char));
	newName = (char*) malloc(strlen(nameItem)*sizeof(char));
	newCategory = (char*) malloc(strlen(categoryItem)*sizeof(char));

	strcpy(newId,idItem);
	strcpy(newName,nameItem);
	strcpy(newCategory,categoryItem);

	item = malloc(sizeof(Food));
	item -> id = newId;
	item -> name = newName;//Phai strdup neu khong con tro name sau khi ra khoi ham addStudent se mat va gia tri o vi tri do se mat di
	item -> category = newCategory;
	item -> price = priceItem;
	return item;
}


int getAnIntegerInRange(int low,int high){
	//when high =-1 => vo cung
	int result;
	char buf[30];
	int choice;
	do{
		result = TRUE;
		fflush(stdin);
		printf("Nhap mot so tu %d-%d: ",low,high );
		gets(buf);
		//check xem co ki tu character hay kh
		for (int i = 0; buf[i]!='\0' && result ==TRUE; ++i)
	 	{
	 		char c = buf[i];
	 		if(c<'0' || c > '9'){
	 			printf("YOu enter wrong\n");
	 			result = FALSE;
	 		}
	 	} 	

		choice = atoi(buf);
		if(high!=-1){
			if(choice<low || choice > high){
				printf("Please enter from %d to %d.\n",low,high);
				result= FALSE;
			}
		}else{
			if(choice<low ){
				printf("Please enter from %d to %d.\n",low,high);
				result= FALSE;
			}
		}
		

	}while(result == FALSE);

	return choice;
}

void readFile(Food** FoodStorage,int* length,char *fileName){
	FILE *f =fopen(fileName,"r");
	char id[50];
	char name[50];
	char category[50];
	double price;
	int i =0;
	// while(fscanf(f,"#%50[^;];%50[^;];%50[^;];%lf\n",&name,&code,&dob,&score)==4){
	// 	studentList[i] = createStudent(name,code,dob,score);
	// 	i++;
	// }
	while(fscanf(f,"%s%s%lf%s",&id,&name,&price,&category)==4){
		FoodStorage[i] = createItem(id,name,category,price);
		i++;
	}
	*length = i;
	fclose(f);
}

int searchItemInStock(char* idInput,char * nameInput,Food** FoodStorage,int length){

	char* id,*name;
	for (int i = 0; i<length; ++i)
	{
		id = FoodStorage[i]->id;
		name = FoodStorage[i]->name;
		if(strlen(idInput) == strlen(id)&&strstr(id,idInput)!=NULL){
			return i;
			
		}
		if(strlen(nameInput) == strlen(name) && strstr(name,nameInput)!=NULL){

			return i;
		}
	}
	return -1;
}

void addItem(Food** FoodStorage,int* length){
	char id[50];
	char name[50];
	char category[50];
	double price;
	char *name1,*code1,*dob1;
		fflush(stdin);
		printf("What is the ID of the item to add: \n");
		fflush(stdin);
		scanf("%s",&id);
		printf("What is the name of the item to add: \n");
		fflush(stdin);
		scanf("%s",&name);
		printf("What is the category of the item to add: \n");
		fflush(stdin);
		scanf("%s",&category);
		printf("What is the price of the item to add: \n");
		fflush(stdin);
		scanf("%lf",&price);
		if(searchItemInStock(id,name,FoodStorage,*length)==-1){
			FoodStorage[*length] = createItem(id,name,category,price);
		(*length)++;
			printf("!!!!Item added\n");
		}
		else{
			printf("Sorry the item you add is in the stock.\n");
			printf("No item added\n");
		}

}

void deleteItem(Food** FoodStorage,int* length){
		char id[50];
		fflush(stdin);
		printf("What is the ID of the item to add: \n");
		fflush(stdin);
		scanf("%s",&id);
		int pos = searchItemInStock(id,"",FoodStorage,*length);
		if(pos==-1){
			printf("Soorry the item you want to delete not it stock\n");
			return;
		}
		for (int i = pos; i < *length; ++i)
		{
			FoodStorage[i]= FoodStorage[i+1];

		}
		FoodStorage[*length]=NULL;
		(*length)--;
}


void displayItemList(Food** FoodStorage,int length){
	printf("Here is the listing of all item in the stock\n");
	printf("%-10s%-20s%-12s%-20s\n","ID","Product","Price","Category" );
	char *id,*name,*category;
	double price;
	for (int i = 0; i < length; ++i)
	{
		id = FoodStorage[i]->id;
		name = FoodStorage[i]->name;
		category = FoodStorage[i]->category;
		price = FoodStorage[i]->price;
		printf("%-10s|%-20s|%-8.2lf|%-20s|\n",id,name,price,category );
	}
}

void saveData(Food** FoodStorage,int length,char *fileName){
	FILE *f = fopen(fileName,"w");
	char *id,*name,*category;
	double price;
	for (int i = 0; i < length; ++i)
	{
		id = FoodStorage[i]->id;
		name = FoodStorage[i]->name;
		category = FoodStorage[i]->category;
		price = FoodStorage[i]->price;
		fprintf(f, "%s\t%s\t%lf\t%s\n",id,name,price,category );
	}
	printf("Data saved\n");
	fclose(f);
}

void updatePrice(Food** FoodStorage,int length){
	char id[30];
	printf("Enter your id item you want to change: ");
	fflush(stdin);
	scanf("%s",&id);
	int pos = searchItemInStock(id,"",FoodStorage,length);
	if(pos==-1){
		printf("Sorry the stock doen't have that item\n");
		return;
	}
	printf("Here is the item you will change the price\n");
	printf("%-10s|%-20s|%-8.2lf|%-20s|\n",FoodStorage[pos]->id,FoodStorage[pos]->name,FoodStorage[pos]->price,FoodStorage[pos]->category );
	double newPrice;
	printf("Enter new price for that item: ");
	fflush(stdin);
	scanf("%lf",&newPrice);
	FoodStorage[pos] -> price = newPrice;
	printf("Here is the item after change the price\n");
	printf("%-10s|%-20s|%-8.2lf|%-20s|\n",FoodStorage[pos]->id,FoodStorage[pos]->name,FoodStorage[pos]->price,FoodStorage[pos]->category );
}

void findInforItem(Food** FoodStorage,int length){
	char id[30];
	printf("Enter your id item you want to search: ");
	fflush(stdin);
	scanf("%s",&id);
	int pos = searchItemInStock(id,"",FoodStorage,length);
	if(pos==-1){
		printf("Sorry the stock doen't have that item\n");
	}else{
		printf("Here is the item \n");
		printf("%-10s|%-20s|%-8.2lf|%-20s|\n",FoodStorage[pos]->id,FoodStorage[pos]->name,FoodStorage[pos]->price,FoodStorage[pos]->category );
	}
}

void menu(){
	Food** FoodStorage;
	FoodStorage = malloc (100*sizeof(Food*));
	int length = 0;
	int userChoice;
	int save;
	char fileName[30];
	char newFile[30];
	printf("Enter the file name: ");
	scanf("%s", &fileName);
	FILE *f = fopen(fileName,"r");
	if(!f){
		printf("Sorry cann't open the file\n");
		fclose(f);
		return;
	}
	fclose(f);
	readFile(FoodStorage,&length,fileName);
	displayItemList(FoodStorage,length);
	
	
	do{
		
		printf("1. Add new item\n");
		printf("2. Delete item\n");
		printf("3. Change the cost of item\n");
		printf("4. Search for Item\n");
		printf("5. Display Food list\n");
		printf("6. Exit\n");
		fflush(stdin);
		userChoice = getAnIntegerInRange(1,6);
		switch(userChoice){
			case 1: 
				addItem(FoodStorage,&length);
				break;
			case 2:
				deleteItem(FoodStorage,&length);
				break;
			case 3:
				updatePrice(FoodStorage,length);
				break;	
			case 4:
				findInforItem(FoodStorage,length);
				break;		
			case 5:
				displayItemList(FoodStorage,length);
				break;
			case 6:
				printf("Do you want to save new data(y for save, other for not save)\n" );
				fflush(stdin);
				save = toupper(getchar());
				if(save =='Y'){
					do{
						printf("Enter your file name you want to save: ");
						fflush(stdin);
						scanf("%s",&newFile);
					}while(strstr(fileName,newFile)!=NULL);
					saveData(FoodStorage,length,newFile);
				}
				else{
					printf("See you again\n");
				}
				break;
		}

	}while(userChoice!=6);

	free(FoodStorage);
}

int main(int argc, char const *argv[])
{
	menu();
	return 0;
}