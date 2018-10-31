	#include <stdio.h>
	typedef struct 
	{
		const char name[80];
		const char specices[80];
		int age;
	}turtle;
	void hpbd(turtle *t);

	//con tro t tro den struct bien cua turtle
	void hpbd(turtle *t)
	{
		t->age=t->age +1;
		printf("Happy birthday %s, you got to %d year old\n",t->name,t->age );
		(*t).age=(*t).age +1;
	}

	int main()
	{
		turtle myturtle;
		printf("Enter your turtle name , specices and age :\n");
		scanf("%79s%s%d",myturtle.name,myturtle.specices,&(myturtle.age));
		hpbd(&myturtle);//dua dia chi cua bien struct vao ham hpbd
		printf("Xin chao cu %d\n", myturtle.age);
		return 0;
	}