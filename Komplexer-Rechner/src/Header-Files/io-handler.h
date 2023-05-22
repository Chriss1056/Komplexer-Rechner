#pragma once

#include "../Header-Files/main.h"
#include "../Header-Files/calculate.h"
#include "../Header-Files/input.h"

void input_one(struct comp* z1_k, struct polar* z1_p);
void input_two(struct comp* z2_k, struct polar* z2_p);

void calc_and_output(struct comp z1_k, struct polar z1_p, struct comp z2_k, struct polar z2_p);

void draw_input_outlines();
void draw_output_outlines(int max_len_param);