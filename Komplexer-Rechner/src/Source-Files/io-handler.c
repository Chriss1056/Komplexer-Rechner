#include "io-handler.h"
#include <stdio.h>
#include <conio.h>

void input_one(struct comp* z1_k, struct polar* z1_p)
{
	int auswahl, tick, terminate;

	auswahl = 1;
	tick = 1;
	terminate = 1;

	do
	{
		system("cls");

		draw_input_outlines();

		if (auswahl == 1)
		{
			u_goto_xy(1, 1);
			u_inverse_color(1);
			printf("Komponentensystem.");
			u_inverse_color(0);
			u_goto_xy(4, 2);
			printf("Polarsystem.");
			u_goto_xy(5, 4);
			printf("Abbrechen.");
			u_goto_xy(0, 6);
		}
		else if (auswahl == 2)
		{
			u_goto_xy(1, 1);
			printf("Komponentensystem.");
			u_goto_xy(4, 2);
			u_inverse_color(1);
			printf("Polarsystem.");
			u_inverse_color(0);
			u_goto_xy(5, 4);
			printf("Abbrechen.");
			u_goto_xy(0, 6);
		}
		else if (auswahl == 3)
		{
			u_goto_xy(1, 1);
			printf("Komponentensystem.");
			u_goto_xy(4, 2);
			printf("Polarsystem.");
			u_goto_xy(5, 4);
			u_red_color(1);
			printf("Abbrechen.");
			u_red_color(0);
			u_goto_xy(0, 6);
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
				if (key == down_arrow && auswahl < 3)
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
							input_comp(z1_k);
							tick = 0;
							break;
						}
					case 2:
						{
							input_polar(z1_p);
							tick = 0;
							break;
						}
					case 3:
						{
							terminate = 0;
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
	int auswahl, tick, terminate;

	auswahl = 1;
	tick = 1;
	terminate = 1;

	do
	{
		system("cls");

		draw_input_outlines();

		if (auswahl == 1)
		{
			u_goto_xy(1, 1);
			u_inverse_color(1);
			printf("Komponentensystem.");
			u_inverse_color(0);
			u_goto_xy(4, 2);
			printf("Polarsystem.");
			u_goto_xy(5, 4);
			printf("Abbrechen.");
			u_goto_xy(0, 6);
		}
		else if (auswahl == 2)
		{
			u_goto_xy(1, 1);
			printf("Komponentensystem.");
			u_goto_xy(4, 2);
			u_inverse_color(1);
			printf("Polarsystem.");
			u_inverse_color(0);
			u_goto_xy(5, 4);
			printf("Abbrechen.");
			u_goto_xy(0, 6);
		}
		else if (auswahl == 3)
		{
			u_goto_xy(1, 1);
			printf("Komponentensystem.");
			u_goto_xy(4, 2);
			printf("Polarsystem.");
			u_goto_xy(5, 4);
			u_red_color(1);
			printf("Abbrechen.");
			u_red_color(0);
			u_goto_xy(0, 6);
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
				if (key == down_arrow && auswahl < 3)
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
						input_comp(z2_k);
						tick = 0;
						break;
					}
					case 2:
					{
						input_polar(z2_p);
						tick = 0;
						break;
					}
					case 3:
					{
						terminate = 0;
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

void calc_and_output(const struct comp z1_k, const struct polar z1_p, const struct comp z2_k, const struct polar z2_p)
{
	int tick, terminate, max_out_var;
	
	tick = 1;
	terminate = 1;
	max_out_var = 0;

	do
	{
		system("cls");

		const struct results results = s_calc_all(z1_k, z1_p, z2_k, z2_p);

		draw_output_outlines(results.max_len);

		u_goto_xy(1, 1);
		printf("Z1 in K: %.3f + j * %.3f", results.z1_kr.f_re, results.z1_kr.f_im);
		u_goto_xy(1, 2);
		printf("Z1 in P: %.3f * e ^ ( j * %.3f%c )", results.z1_pr.f_be, results.z1_pr.f_wi, (char)248);

		u_goto_xy(1, 4);
		printf("Z2 in K: %.3f + j * %.3f", results.z2_kr.f_re, results.z2_kr.f_im);
		u_goto_xy(1, 5);
		printf("Z2 in P: %.3f * e ^ ( j * %.3f%c )", results.z2_pr.f_be, results.z2_pr.f_wi, (char)248);

		u_goto_xy(1, 7);
		printf("Z1+Z2 in K: %.3f + j * %.3f", results.add_z1_z2_kr.f_re, results.add_z1_z2_kr.f_im);
		u_goto_xy(1, 8);
		printf("Z1+Z2 in P: %.3f * e ^ ( j * %.3f%c )", results.add_z1_z2_pr.f_be, results.add_z1_z2_pr.f_wi, (char)248);

		u_goto_xy(1, 10);
		printf("Z1-Z2 in K: %.3f + j * %.3f", results.sub_z1_z2_kr.f_re, results.sub_z1_z2_kr.f_im);
		u_goto_xy(1, 11);
		printf("Z1-Z2 in P: %.3f * e ^ ( j * %.3f%c )", results.sub_z1_z2_pr.f_be, results.sub_z1_z2_pr.f_wi, (char)248);
		u_goto_xy(1, 12);
		printf("Z2-Z1 in K: %.3f + j * %.3f", results.sub_z2_z1_kr.f_re, results.sub_z2_z1_kr.f_im);
		u_goto_xy(1, 13);
		printf("Z2-Z1 in P: %.3f * e ^ ( j * %.3f%c )", results.sub_z2_z1_pr.f_be, results.sub_z2_z1_pr.f_wi, (char)248);

		u_goto_xy(1, 15);
		printf("Z1*Z2 in K: %.3f + j * %.3f", results.mul_z1_z2_kr.f_re, results.mul_z1_z2_kr.f_im);
		u_goto_xy(1, 16);
		printf("Z1*Z2 in P: %.3f * e ^ ( j * %.3f%c )", results.mul_z1_z2_pr.f_be, results.mul_z1_z2_pr.f_wi, (char)248);

		u_goto_xy(1, 18);
		if (results.z2_kr.f_re != 0 || results.z2_kr.f_im != 0)
		{
			printf("Z1%cZ2 in K: %.3f + j * %.3f", (char)246, results.div_z1_z2_kr.f_re, results.div_z1_z2_kr.f_im);
		}
		else
		{
			printf("Z1%cZ2 in K: Undef.", (char)246);
		}
		u_goto_xy(1, 19);
		if (results.z2_pr.f_be != 0)
		{
			printf("Z1%cZ2 in P: %.3f * e ^ ( j * %.3f%c )", (char)246, results.div_z1_z2_pr.f_be, results.div_z1_z2_pr.f_wi, (char)248);
		}
		else
		{
			printf("Z1%cZ2 in P: Undef.", (char)246);
		}
		u_goto_xy(1, 20);
		if (results.z1_kr.f_re != 0 || results.z1_kr.f_im != 0)
		{
			printf("Z2%cZ1 in K: %.3f + j * %.3f", (char)246, results.div_z2_z1_kr.f_re, results.div_z2_z1_kr.f_im);
		}
		else
		{
			printf("Z2%cZ1 in K: Undef.", (char)246);
		}
		u_goto_xy(1, 21);
		if (results.z1_pr.f_be != 0)
		{
			printf("Z2%cZ1 in P: %.3f * e ^ ( j * %.3f%c )", (char)246, results.div_z2_z1_pr.f_be, results.div_z2_z1_pr.f_wi, (char)248);
		}
		else
		{
			printf("Z2%cZ1 in P: Undef.", (char)246);
		}

		u_goto_xy(2, 23);
		u_yellow_color(1);
		printf("Zur%cck.", (char)129);
		u_yellow_color(0);
		u_goto_xy(0, 25);

		do
		{
			if (_kbhit())
			{
				const int key = u_get_key();
				if (key == enter)
				{
					terminate = 0;
					tick = 0;
				}
			}

		} while (tick);
		tick = 1;

	} while (terminate);
}

void draw_input_outlines()
{
	u_goto_xy(0, 0);
	printf("%c", (char)201);
	for (int i = 0; i < 18; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)187);
	u_goto_xy(0, 1);
	for (int i = 0; i < 4; i++)
	{
		u_goto_xy(0, i + 1);
		printf("%c", (char)186);
		u_goto_xy(19, i + 1);
		printf("%c", (char)186);
	}
	u_goto_xy(0, 5);
	printf("%c", (char)200);
	for (int i = 0; i < 18; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)188);
	u_goto_xy(0, 3);
	printf("%c", (char)204);
	for (int i = 0; i < 18; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(1, 0);
	printf("Eingabeart");
	u_goto_xy(0, 6);
}

void draw_output_outlines(int max_len_param)
{
	if (max_len_param < 9)
	{
		max_len_param = 9;
	}
	u_goto_xy(0, 0);
	printf("%c", (char)201);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)187);
	u_goto_xy(0, 1);
	for (int i = 0; i < 23; i++)
	{
		u_goto_xy(0, i + 1);
		printf("%c", (char)186);
		u_goto_xy(max_len_param + 1, i + 1);
		printf("%c", (char)186);
	}
	u_goto_xy(0, 24);
	printf("%c", (char)200);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)188);
	u_goto_xy(0, 3);
	printf("%c", (char)204);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(0, 6);
	printf("%c", (char)204);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(0, 9);
	printf("%c", (char)204);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(0, 14);
	printf("%c", (char)204);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(0, 17);
	printf("%c", (char)204);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(0, 22);
	printf("%c", (char)204);
	for (int i = 0; i < max_len_param; i++)
	{
		printf("%c", (char)205);
	}
	printf("%c", (char)185);
	u_goto_xy(1, 0);
	printf("Ergebnise");
	u_goto_xy(0, 25);
}