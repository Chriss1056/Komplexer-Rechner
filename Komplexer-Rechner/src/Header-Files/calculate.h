#pragma once

#include <main.h>

struct results
{
	struct comp* z1_kr;
	struct comp* z2_kr;

	struct polar* z1_pr;
	struct polar* z2_pr;

	struct comp* add_z1_z2_kr;
	struct polar* add_z1_z2_pr;

	struct comp* sub_z1_z2_kr;
	struct polar* sub_z1_z2_pr;
	struct comp* sub_z2_z1_kr;
	struct polar* sub_z2_z1_pr;

	struct comp* mul_z1_z2_kr;
	struct polar* mul_z1_z2_pr;

	struct comp* div_z1_z2_kr;
	struct polar* div_z1_z2_pr;
	struct comp* div_z2_z1_kr;
	struct polar* div_z2_z1_pr;
};

struct results s_calc_all(struct comp* z1_k, struct polar* z1_p, struct comp* z2_k, struct polar* z2_p);

void c_add(struct results* results);
void c_sub(struct results* results);
void c_mul(struct results* results);
void c_div(struct results* results);

void to_comp(struct polar* out, struct comp* in);
void to_polar(struct comp* out, struct polar* in);

void default_init(struct results* results);