#include <stdio.h>
#include <string.h>
int main()
{
	char name[][80]={"Bui Si Hung",
					"Ly Thi Thu",
					"Tran Khanh Bang",
					"Le THu Huong"};
	char find[10];
			int y=0;
	puts("Nhap vao ho ban muon tim:");
	scanf("%s",find);
	puts("Nhung nguoi co ho ban can tim la :");
	for(int i=0;i<4;i++){
		if (strstr(name[i],find)){
			y++;
			printf("%s\n",name[i] );
			continue;
		}
	}
	if (y==0)
			printf("Khong co ai co ho ban can tim\n");
	return 0;
}