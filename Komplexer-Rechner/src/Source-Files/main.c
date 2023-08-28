#include "../Header-Files/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void draw_main_menu_frame()
{
	u_goto_xy(0, 0);
	printf("%c", (char)201);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)187);
	u_goto_xy(0, 1);
	for (int i = 0; i < 6; i++)
	{
		u_goto_xy(0, i + 1);
		printf("%c", (char)186);
		u_goto_xy(31, i + 1);
		printf("%c", (char)186);
	}
	u_goto_xy(0, 7);
	printf("%c", (char)200);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)188);
	u_goto_xy(0, 3);
	printf("%c", (char)204);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(0, 5);
	printf("%c", (char)204);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(1, 0);
	printf("Main Menue");
	u_goto_xy(0, 8);
}

int main()
{
	struct comp z1_k, z2_k;
	struct polar z1_p, z2_p;

	z1_k.f_re = 0;
	z1_k.f_im = 0;
	z1_p.f_be = 0;
	z1_p.f_wi = 0;

	z2_k.f_re = 0;
	z2_k.f_im = 0;
	z2_p.f_be = 0;
	z2_p.f_wi = 0;

	int auswahl, tick, terminate;

	auswahl = 1;
	tick = 1;
	terminate = 1;

	SetConsoleTitle(L"Komplexer Rechner");

	do
	{
		system("cls");

		draw_main_menu_frame();

		if (auswahl == 1)
		{
			u_inverse_color(1);
			u_goto_xy(1, 1);
			printf("Erste Komplexe Zahl eingeben.");
			u_inverse_color(0);
			u_goto_xy(1, 2);
			printf("Zweite Komplexe Zahl eingeben.");
			u_goto_xy(11, 4);
			printf("BERECHNEN");
			u_goto_xy(12, 6);
			printf("BEENDEN");
			u_goto_xy(0, 8);
		}
		else if (auswahl == 2)
		{
			u_goto_xy(1, 1);
			printf("Erste Komplexe Zahl eingeben.");
			u_inverse_color(1);
			u_goto_xy(1, 2);
			printf("Zweite Komplexe Zahl eingeben.");
			u_inverse_color(0);
			u_goto_xy(11, 4);
			printf("BERECHNEN");
			u_goto_xy(12, 6);
			printf("BEENDEN");
			u_goto_xy(0, 8);
		}
		else if (auswahl == 3)
		{
			u_goto_xy(1, 1);
			printf("Erste Komplexe Zahl eingeben.");
			u_goto_xy(1, 2);
			printf("Zweite Komplexe Zahl eingeben.");
			u_goto_xy(11, 4);
			u_green_color(1);
			printf("BERECHNEN");
			u_green_color(0);
			u_goto_xy(12, 6);
			printf("BEENDEN");
			u_goto_xy(0, 8);
		}
		else if (auswahl == 4)
		{
			u_goto_xy(1, 1);
			printf("Erste Komplexe Zahl eingeben.");
			u_goto_xy(1, 2);
			printf("Zweite Komplexe Zahl eingeben.");
			u_goto_xy(11, 4);
			printf("BERECHNEN");
			u_goto_xy(12, 6);
			u_red_color(1);
			printf("BEENDEN");
			u_red_color(0);
			u_goto_xy(0, 8);
		}

		do
		{
			if (_kbhit())
			{
				const int key = u_get_key();
				if (key == up_arrow && auswahl > 1)
				{
					auswahl--;
					tick = 0;
				}
				if (key == down_arrow && auswahl < 4)
				{
					auswahl++;
					tick = 0;
				}
				if (key == enter)
				{
					switch (auswahl)
					{
					case 1:
						{
						input_one(&z1_k, &z1_p);
						tick = 0;
						break;
						}
					case 2:
						{
						input_two(&z2_k, &z2_p);
						tick = 0;
						break;
						}
					case 3:
						{
						calc_and_output(z1_k, z1_p, z2_k, z2_p);
						tick = 0;
						break;
						}
					case 4:
						{
						system("cls");
						printf("Are you Sure? [Enter]");
						const int validate = u_get_key();
						if (validate == enter)
						{
							terminate = 0;
						}
						tick = 0;
						break;
						}
					default:
						{
						system("cls");
						fprintf(stderr, "Ups, something went wrong...");
						Sleep(1000);
						system("cls");
						tick = 0;
						}
					}
				}
			}
			
		} while (tick);
		tick = 1;
		
	} while (terminate);

	system("cls");
	printf("Bye, bye...\n\n");
	system("pause");
	return 0;
}