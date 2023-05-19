#pragma once

#include <Windows.h>
#include <conio.h>

typedef enum keys
{
	up_arrow = 296,
	down_arrow = 304,
	enter = 13
} e_keys;

typedef enum colors
{
	f_white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	f_black = 0,
	b_white = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	b_black = 0
} e_colors;

int u_get_key();
int u_goto_xy(short x, short y);
void u_inverse_color(short inverse);
void u_red_color(short active);
void u_green_color(short active);