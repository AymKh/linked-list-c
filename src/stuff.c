#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


void color(int x)
{

	HANDLE hconsole;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole,x);
}



void header(void)
{
	system("cls");
	printf("\n\n");color(12);
	printf("\t\t\t\tD R . L i n k e d \n\n");color(15);
	printf("\t\t\tInspired by    : ");color(10);printf("KIAMOTTULLAH\n");color(15);
	printf("\t\t\tRelease by     : ");color(10);printf("AymKh\n");color(15);
	printf("\t\t\tFork on github : ");color(14);printf("https://github.com/AymKh/drlinked");color(15);
	printf("\n\n\t---------------------------------------------------------------------------------\n");


}

void menu (void)
{
	

	printf("\t\t      ADD      |       DELETE       |\n");
	printf("\t\t               |                    |\n");
	color(6);printf("\t\t1/");color(15);printf(" Add head    |   ");color(6);printf("4/");color(15);printf(" Delete head   |   ");color(6);printf("7/");color(15);printf(" Search          \n");color(15);
	printf("\t\t               |                    |\n");
	color(6);printf("\t\t2/");color(15);printf(" Add tail    |   ");color(6);printf("5/");color(15);printf(" Delete tail   |   ");color(6);printf("8/");color(15);printf(" Print list\n");color(15);
	printf("\t\t               |                    |\n");
	color(6);printf("\t\t3/");color(15);printf(" Add custom  |   ");color(6);printf("6/");color(15);printf(" Delete custom |   ");color(6);printf("9/");color(15);printf(" Reverse list\n");color(15);
	printf("\t\t               |                    |\n");
	printf("\t\t               |                    |  ");color(6);printf("10/");color(15);printf(" Max , Min\n");
	printf("\t\t               |                    |        \n");
	printf("\t\t               |                    |  ");color(6);printf("11/");color(15);printf(" Quit");

	printf("\n\t---------------------------------------------------------------------------------\n");

}

void added_success(void)
{
	color(10);
	printf("\n\t\tAddedd Successfully !");
	color(15);
}


void del_success(void)
{
	color(10);
	printf("\n\t\tDeleted Successfully !");
	color(15);
}

