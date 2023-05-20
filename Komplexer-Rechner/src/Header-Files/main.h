#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include <utility.h>
#include <io-handler.h>

struct comp
{
	float f_re;
	float f_im;
};

struct polar
{
	float f_be;
	float f_wi;
};

void draw_main_menu_frame();