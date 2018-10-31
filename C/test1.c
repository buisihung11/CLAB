#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main()
{

    char name[5][30], tname[5][30], temp[30];
    int i, j, n;

    printf("Enter the value of n \n");
    scanf("%d", &n);
    printf("Enter %d names \n", n);
//nhap ten
    for (i = 0; i < n; i++)
    {
        gets(name[i]);
        strcpy(tname[i], name[i]);//tname khong lam gi chi copy de hien thi
    }
// sap xep ten
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("\n-------------------------------\n");
    printf("Input Namest\tSorted names\n");
    printf("---------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%s\n", tname[i], name[i]);

    }
    printf("----------------------------------\n");
    return 0;

}