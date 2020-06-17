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
printf("\nenter 1 to search the state details!");

switch(getch())
{
    case '1':

                searchstate();
    break;
    case 'a':
                addstate();
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
    printf("\n error in opening\a\a\a\a");
    exit(1);

}

printf("\nEnter state name\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tCovid-19 impact in %s",name);
        printf("\nlast updated on : 16/06/2020");
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

