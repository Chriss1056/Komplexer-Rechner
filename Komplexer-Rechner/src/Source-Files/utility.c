#include "../Header-Files/utility.h"
#include <conio.h>
#include <math.h>

int u_get_key()
{
	int key = _getch();
	if (key >= 224)
	{
		key += _getch();
	}
	return key;
}

int u_get_number_length(const float number)
{
	return (int)ceilf(log10f(number));
}

void u_goto_xy(const unsigned short x, const unsigned short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){ x, y });
}

void u_inverse_color(const unsigned char inverse)
{
	WORD w_attr;
	if (inverse)
	{
		w_attr = f_black | b_white;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), w_attr);
}

void u_red_color(const unsigned char active)
{
	WORD w_attr;
	if (active)
	{
		w_attr = f_white | BACKGROUND_RED;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), w_attr);
}

void u_green_color(const unsigned char active)
{
	WORD w_attr;
	if (active)
	{
		w_attr = f_white | BACKGROUND_GREEN;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), w_attr);
}

void u_yellow_color(const unsigned char active)
{
	WORD w_attr;
	if (active)
	{
		w_attr = f_white | BACKGROUND_RED | BACKGROUND_GREEN;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), w_attr);
}