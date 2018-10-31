#include <stdio.h>
#include <math.h>
int main ()
{
	double cost200, cost50;
	int inv;
	int pac200 = inv/200;
	int du1 = inv%200;
	int pac50 = du1/50;
	int du2 = du1%50;
	double pay = pac200*cost200 + pac50*cost50;
	printf("cost small\n");
	scanf("%lf",&cost50);
	printf("cost large\n");
	scanf("%lf",&cost200);
	printf("invs??\n");
	scanf("%d",&inv);
	do {
		printf("you order %d large package.", pac200);
		printf("you order %d small package.", pac50);
		if (du2 > 0) {
			pac50++;	
		}
	} while (4*cost50 <= cost200);
	printf("you cost for inv will be: %lf",&pay);	
	return 0;	
}