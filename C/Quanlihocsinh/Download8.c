#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main(){

	typedef struct {
		char name[50];
		float fToan,fLy,fHoa;

		}Hocsinh;
		
		Hocsinh hs[50];
		int nb_hs;
    void Menu1(){
		char temp_name[50];
		 fflush(stdin);
		int hstimduoc;
		puts("Nhap ten nguoi muon tim: ");
		gets(temp_name);// co bo ki tu enter

		//fgets(temp_name,50,stdin);// lay ki tu enter
		 
		fflush(stdin);
		
		for(int i=0;i<nb_hs;i++)
		{
			
		    //fflush(stdin);
			if(strstr(hs[i].name,temp_name))
			{
				hstimduoc++;
				printf("Ten: %s",hs[i].name);
				printf("\nCo so diem toan la %f, diem Ly la %f, diem Hoa la %f\n",hs[i].fToan,hs[i].fLy,hs[i].fHoa);
			}
		}
		if(!hstimduoc)
			  printf("khong co hoc sinh nay\n\a");
	}
	void Menu2(){
		int x;
		int i;
		puts("Nhap so diem chuan ban muon: ");
		scanf("%d",&x);
		for(i=0;i<nb_hs;i++){ //gia su co 50 hoc sinh
			if( hs[i].fToan>=x || hs[i].fLy>=x || hs[i].fHoa>=x ){
				printf("Ten: %s",hs[i].name);
				printf("\nCo so diem toan la %f, diem Ly la %f, diem Hoa la %f\n",hs[i].fToan,hs[i].fLy,hs[i].fHoa);
			}
			}
		}

	void Menu3()
	{
	    int i;
		for( i=0;i<nb_hs;i++)
		{
			if(hs[i].fToan>=8.0&& hs[i].fHoa >= 8.0)
                {
				printf("Ten: %s",hs[i].name);
				printf("\nCo so diem toan la %f, diem Ly la %f, diem Hoa la %f\n",hs[i].fToan,hs[i].fLy,hs[i].fHoa);
                }
        }
    }
	// cac buoc nhap tu them code :V
	//code tim kiem
	//char s[255];

		FILE *f=fopen("file_test.txt","r");
			//fscanf(f,"%s",s);
			if(f==NULL)
				{
				 printf("\nLoi doc file.");
					return 0;

				}
 			else
				{
				 for(nb_hs=0;!feof(f);nb_hs++)
					{
                    char tx[5];
					 fgets(tx,5,f);
					 fgets(hs[nb_hs].name,50,f);
					 fscanf(f,"%f",&hs[nb_hs].fToan);
					 fscanf(f,"%f",&hs[nb_hs].fLy);
					 fscanf(f,"%f",&hs[nb_hs].fHoa);
					 //puts(s);
				}
				 //nb_hs--;
						fclose(f);
	//code tao menu
	//int Menutimkiem;
	//float Menu1,Menu2,Menu3;
	for (int i=0;i<nb_hs;i++){
        printf("Hoc sinh %d la %s\n",i+1,hs[i].name);
	}
	printf("Menu: ");
	printf("1.Tim hoc sinh\n");
	printf("2. Diem chuan de tim hoc sinh.\n");
	printf("3.Toan va Hoa tren 8 diem\n");
	printf("Nhap hanh dong: ");
	int menu;

	do {
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
			    Menu1(); break;
			case 2:
			     Menu2(); break;
			case 3:
			     Menu3(); break;
		}
	}while(menu>3||menu<0);


		return 0;
	}
}
