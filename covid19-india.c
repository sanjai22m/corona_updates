//Team 10
//Corona update tracker (in India)
//done by: Sanjai M, Indra Shekar G, Manoj S, Gowtham T
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct particulars
{

    char name[100];
    long int active;
    long int cured;
    long int deaths;
    long int total;

    };
void menu();
void got();
void start();
void back();
void searchstate();
void addstate();
void updatestate();
void prevention_guidelines();

int main()
{
    system("color 8f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t**********CORONA VIRUS UPDATES (in India)*************");
printf("\nsource: mohfw.gov.in            brought to you by: Sanjai M, Indra Shekar G, Manoj S and Gowtham\n");
printf("\nlast updated on : 20/06/2020");
printf("\nenter the key:\n");
printf(" <1> Guidelines to prevent Covid-19 infection.\n");
printf(" <2> Search covid-19 infection on a particular state.\n");
printf(" <3> Update state information.\n");
printf(" <4> Exit the program.\n");

switch(getch())
{
    case '2':

                searchstate();
    break;
    case 'a':
                addstate();
    break;
    case '3':
                updatestate();
    break;
    case '1':
                prevention_guidelines();
    break;
    case '4':
                system("cls");
                exit(1);
    break;
    default:
                system("cls");
                printf("\nwrong key entered !");
                printf("\n Enter any key");
                getch();

menu();
}
}
 void addstate()
{
        system("cls");
        FILE *f;
        struct particulars p;
        f=fopen("E:/covid19-india","ab+");

        printf("\nEnter state name: ");
        got(p.name);
        printf("\nEnter no. of active cases: ");
        scanf("%ld",&p.active);
        printf("\nEnter no. of cured cases: ");
        scanf("%ld",&p.cured);
        printf("\nEnter no. of deaths:");
        scanf("%ld",&p.deaths);
        printf("Enter total no. of cases:");
        scanf("%ld",&p.total);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\ndetails saved");
fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}

void searchstate()
{
    struct particulars p;
FILE *f;
char name[100];

f=fopen("E:/covid19-india","rb");
if(f==NULL)
{
    printf("\n error in opening the file\a\a\a\a");
    exit(1);

}
printf("\nType <All India> to display the total spread in India (or)");
printf("\nEnter state name\n");
got(name);
system("cls");
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tCovid-19 impact in %s",name);
        printf("\nState name:%s\nActive cases:%ld\nCured / Migrated:%ld\nDeaths:%ld\nTotal:%ld\n",p.name,p.active,p.cured,p.deaths,p.total);
    }
    else{
        printf(" ... ");
    }

}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }

                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}

void updatestate()
{
    int c;
    FILE *f;
    int flag=0;
    struct particulars p,s;
	char  name[50];
	f=fopen("E:/covid19-india","rb+");
	if(f==NULL)
		{

			printf("state name not found.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter the name of the state to update:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter state name:");
                    got(s.name);
                    printf("\nEnter no. of active cases:");
                    scanf("%ld",&s.active);
                    printf("\nEnter no. of cured:");
                    scanf("%ld",&s.cured);
                    printf("\nEnter no. of deaths:");
                    scanf("%ld",&s.deaths);
                    printf("\nEnter total no. of cases:");
                    scanf("%ld",&s.total);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n new state details are updated.");

            }
            else
            {
                    printf(" \n state data not updated");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}

void prevention_guidelines()
{
    system("cls");
    printf("Guidelines to prevent covid-19 infection:\n");
    printf("1) Wash your hands often with soap and use a sanitizer.\n");
    printf("2) Avoid touching your eyes, nose, and mouth with unwashed hands.\n");
    printf("3) Avoid close contact with people who are sick.\n");
    printf("4) Cover coughs and sneezes.\n");
    printf("5) Clean and disinfect frequently touched surfaces daily.\n");
    printf("6) Monitor your health and be alert for the symptoms.\n");
    printf("\n\n Enter any key.");
    getch();
    system("cls");
    menu();
}

