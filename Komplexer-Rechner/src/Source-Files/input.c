#include "input.h"
#include <stdio.h>

void input_comp(struct comp* z)
{
	system("cls");

	printf("Bitte die Komplexe Zahl im folgendem Format eingeben: RE{z} IM{z}\n");
	printf("%c ", (char)175);
	scanf_s("%f %f", &z->f_re, &z->f_im);

	printf("\n\n\nThis Menu is Flagged for remake!\n");
}

void input_polar(struct polar* z)
{
	system("cls");

	printf("Bitte die Komplexe Zahl im folgendem Format eingeben: BE{z} WI{z}\n");
	printf("%c ", (char)175);
	scanf_s("%f %f", &z->f_be, &z->f_wi);

	printf("\n\n\nThis Menu is Flagged for remake!\n");
}
