#include <stdio.h>
float add_with_tax(float f);

float total=0.0;
short count=0;
short tax_percent = 6;

float add_with_tax(float f)
{
	float tax_rate = 1+ (float)(tax_percent/100.0);
	total =total + (f*tax_rate);
	count++;
	return total;
}
int main()
{
	float val;
	printf("Price of item:");
	while (scanf("%f",&val)==1){
		printf("Total so far: %.2f\n",add_with_tax(val) );
		printf("Price of item\n");
	}
	printf("\nfinal total: %.2f\n",total );
	printf("Number of item: %d\n",count );
	return 0;
}