#include <stdio.h>

int main()
{
    struct nhanvien
    {
        int i;
        char name[30];
    }hung;

    printf("Nhap tuoi \n");
    gets(hung.i)
  	printf("Nhap ten\n");
  	scanf(hung.name);
    printf("%d %2s",hung.i,(hung.name)+1);
    return 0;
}
