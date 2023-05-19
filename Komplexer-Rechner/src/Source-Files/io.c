#include <io.h>

void input_one(struct comp* z1_k, struct polar* z1_p)
{
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
}

void input_two(struct comp* z2_k, struct polar* z2_p)
{
	//
}

void calc_and_output(struct comp* z1_k, struct polar* z1_p, struct comp* z2_k, struct polar* z2_p)
{
	//
}