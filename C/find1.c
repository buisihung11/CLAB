#include <stdio.h>
#include <string.h>
char *ADS[] = {
"William: SBM GSOH likes sports, TV, dining",
"Matt: SWM NS likes art, movies, theater",
"Luis: SLM ND likes books, theater, art",
"Mike: DWM DS likes trucks, sports and bieber",
"Peter: SAM likes chess, working out and art",
"Josh: SJM likes sports, movies and theater",
"Jed: DBM likes theater, books and dining"
};
int sports_no_bieber(char *s)
{
	return strstr(s,"sports")&& !strstr(s,"bieber");
}
int sports_or_workout(char *s )
{
	return strstr(s,"sports")||strstr(s,"workout");
}
int ns_theater(char *s)
{
	return strstr(s,"NS")&&strstr(s,"theater");
}
void find(int (*x)(char*) )
{
	for (int i=0;i<6;i++){
		if((*x)(ADS[i])){
			printf("%s\n",ADS[i] );
		}
	}
	puts("-------");
}
int main()
 {
 	find(&sports_or_workout);
 	find(&sports_no_bieber);
 	return 0;
 }
