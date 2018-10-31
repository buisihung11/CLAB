#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct island
{
	char *name;
	char *open;
	char *closes;
	struct island *next1;// tao con tro tro den 1 struct
}island;
//void display(island *i);
island *creat(char *name)// creat one island
{
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->open="09:00";
	i->closes="17:30";
	i->next1=NULL;
	return i;//address of island 
}
//island *creat(char name[]);
void display(island *i){
	for (;i!= NULL;i=i->next1)
	{
		printf("Name: %s\n Open: %s-- Close: %s  ",i->name,i->open,i->closes);
		printf("\nDia chi %d\n",i );
		if (i->next1)
			printf("Go to (%d) %s\n",i->next1,(i->next1)->name ); //i->next bay gio la 1 con tro nen de tro toi ten cua dao tiep theo phai la(i->next)->name khong phai (i->next).name
		else
			printf("End\n");
        puts("--------");
	}
}
void release(island *start){
	island *i = start;
	for (;i != NULL;i=i->next1)// thuc hien vong lap khi island != null
	{// sau moi vong lap cho start  = next
		//next = start -> next;
		free(start-> name);
		free(start);
	}
}
int main()
{
	island *start = NULL ;
	island *i = NULL;
	island *next =NULL;
	char name[80];
	for (; fgets(name,80,stdin)!="EOF";i=next)
	{
		next = creat(name);	
		if (start==NULL)
			start = next;
		if (i!= NULL)
			i-> next1 = next;
		else 
			continue; 
		display(start);
	}

	//printf("Dia chi cua %d p_island0 va %d creat\n",&p_island0,&creat(name) );
	release(start);
	return 0;
}
