#include <stdio.h>
#include "encryt.h"

void tang(int x)
{
	x++;
	puts("so lien sau cua x la :%d",x);
}`
int main()
{
	int x;
	puts("Nhap x:");
	scanf("%d",&x);
	void tang(x);
	return 0;
}