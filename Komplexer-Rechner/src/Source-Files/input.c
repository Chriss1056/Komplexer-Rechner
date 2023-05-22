#include "../Header-Files/input.h"
#include "../Header-Files/utility.h"
#include <stdio.h>

void input_comp(struct comp* z)
{
	system("cls");
	printf("Bitte die komplexe Zahl in folgendem Format eingeben: RE{z} IM{z}\n");
	u_goto_xy(0, 5);
	printf("This menu is flagged for remake!");
	u_goto_xy(0, 1);
	printf("%c ", (char)175);
	scanf_s("%f %f", &z->f_re, &z->f_im);
}

void input_polar(struct polar* z)
{
	system("cls");
	printf("Bitte die komplexe Zahl in folgendem Format eingeben: BE{z} WI{z}\n");
	u_goto_xy(0, 5);
	printf("This menu is flagged for remake!");
	u_goto_xy(0, 1);
	printf("%c ", (char)175);
	scanf_s("%f %f", &z->f_be, &z->f_wi);
}
