#include <stdio.h>
int main()
{
	float longitude;
	float latitude;
	char info[80];
	while(scanf("%f,%f,%79[^\n]",&longitude,&latitude,info)==3)
		if (latitude>24 && latitude<34)
			if (longitude>-76 && longitude<-64)
				printf("%f,%f,%s\n",latitude,longitude,info );
	return 0;	
}