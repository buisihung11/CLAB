#include <stdio.h>

typedef struct {
		int x;
		float y;
	}number;
void input(number *p)
{
	printf("Nhap\n");
	scanf("%d ",p->x);
	scanf("%f",p->y);
}
int main()
{
	
	number h;
	printf("x la %d\n y la %f \n",h.x,h.y);
	printf("Nhap\n");
	fflush(stdin);
	scanf("%d ",&(h.x));
	scanf("%f",&(h.y));
	printf("x la %d\n y la %f \n",h.x,h.y);
	input(&h);
	printf("x la %d\n y la %f \n",h.x,h.y);
	return 0;
}