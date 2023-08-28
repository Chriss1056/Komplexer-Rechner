#pragma once

#include <Windows.h>

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
int u_get_number_length(float number);
void u_goto_xy(unsigned short x, unsigned short y);
void u_inverse_color(unsigned char inverse);
void u_red_color(unsigned char active);
void u_green_color(unsigned char active);
void u_yellow_color(unsigned char active);