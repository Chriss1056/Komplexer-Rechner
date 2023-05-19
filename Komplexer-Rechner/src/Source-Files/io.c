#include <io.h>

void input_one(struct comp* z1_k, struct polar* z1_p)
{
	int auswahl, tick, terminate;

	auswahl = 1;
	tick = 1;
	terminate = 1;

	system("cls");

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
	u_goto_xy(1, 0);
	printf("Eingabeart");
	u_goto_xy(0, 8);

	do
	{
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
				if (key == down_arrow && auswahl < 2)
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
						//TODO Implement Function Input Komponentensystem
						tick = 0;
						break;
					}
					case 2:
					{
						//TODO Implement Function Input Polarsystem
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
}

void input_two(struct comp* z2_k, struct polar* z2_p)
{
	//
}

void calc_and_output(struct comp* z1_k, struct polar* z1_p, struct comp* z2_k, struct polar* z2_p)
{
	//
}