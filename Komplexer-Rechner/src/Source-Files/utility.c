#include <utility.h>

int u_get_key()
{
	int key = _getch();
	if (key >= 224)
	{
		key += _getch();
	}
	return key;
}

int u_goto_xy(const short x, const short y)
{
	const HANDLE h_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD c_console_cursor_pos = {x, y};
	SetConsoleCursorPosition(h_handle, c_console_cursor_pos);
	return 0;
}

void u_inverse_color(const short inverse)
{
	const HANDLE h_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD w_attr;
	if (inverse)
	{
		w_attr = f_black | b_white;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(h_handle, w_attr);
}

void u_red_color(const short active)
{
	const HANDLE h_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD w_attr;
	if (active)
	{
		w_attr = f_white | BACKGROUND_RED;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(h_handle, w_attr);
}

void u_green_color(const short active)
{
	const HANDLE h_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD w_attr;
	if (active)
	{
		w_attr = f_white | BACKGROUND_GREEN;
	}
	else
	{
		w_attr = f_white | b_black;
	}
	SetConsoleTextAttribute(h_handle, w_attr);
}