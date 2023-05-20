#include <calculate.h>

struct results s_calc_all(struct comp* z1_k, struct polar* z1_p, struct comp* z2_k, struct polar* z2_p)
{
	struct results results;

	default_init(&results);

	return results;
}

void c_add(struct results* results)
{
}

void c_sub(struct results* results)
{
}

void c_mul(struct results* results)
{
}

void c_div(struct results* results)
{
}

void to_comp(struct polar* out, struct comp* in)
{
}

void to_polar(struct comp* out, struct polar* in)
{
}

void default_init(struct results* results)
{
	results->z1_kr->f_re = 0;
	results->z1_kr->f_im = 0;
	results->z2_kr->f_re = 0;
	results->z2_kr->f_im = 0;

	results->z1_pr->f_be = 0;
	results->z1_pr->f_wi = 0;
	results->z1_pr->f_be = 0;
	results->z1_pr->f_wi = 0;

	results->add_z1_z2_kr->f_re = 0;
	results->add_z1_z2_kr->f_im = 0;
	results->add_z1_z2_pr->f_be = 0;
	results->add_z1_z2_pr->f_wi = 0;

	results->sub_z1_z2_kr->f_re = 0;
	results->sub_z1_z2_kr->f_im = 0;
	results->sub_z1_z2_pr->f_be = 0;
	results->sub_z1_z2_pr->f_wi = 0;
	results->sub_z2_z1_kr->f_re = 0;
	results->sub_z2_z1_kr->f_im = 0;
	results->sub_z2_z1_pr->f_be = 0;
	results->sub_z2_z1_pr->f_wi = 0;

	results->mul_z1_z2_kr->f_re = 0;
	results->mul_z1_z2_kr->f_im = 0;
	results->mul_z1_z2_pr->f_be = 0;
	results->mul_z1_z2_pr->f_wi = 0;

	results->div_z1_z2_kr->f_re = 0;
	results->div_z1_z2_kr->f_im = 0;
	results->div_z1_z2_pr->f_be = 0;
	results->div_z1_z2_pr->f_wi = 0;
	results->div_z2_z1_kr->f_re = 0;
	results->div_z2_z1_kr->f_im = 0;
	results->div_z2_z1_pr->f_be = 0;
	results->div_z2_z1_pr->f_wi = 0;
}

/*
	results.z1_kr->f_re = 0;
	results.z1_kr->f_im = 0;
	results.z2_kr->f_re = 0;
	results.z2_kr->f_im = 0;

	results.z1_pr->f_be = 0;
	results.z1_pr->f_wi = 0;
	results.z1_pr->f_be = 0;
	results.z1_pr->f_wi = 0;

	results.add_z1_z2_kr->f_re = 0;
	results.add_z1_z2_kr->f_im = 0;
	results.add_z1_z2_pr->f_be = 0;
	results.add_z1_z2_pr->f_wi = 0;

	results.sub_z1_z2_kr->f_re = 0;
	results.sub_z1_z2_kr->f_im = 0;
	results.sub_z1_z2_pr->f_be = 0;
	results.sub_z1_z2_pr->f_wi = 0;
	results.sub_z2_z1_kr->f_re = 0;
	results.sub_z2_z1_kr->f_im = 0;
	results.sub_z2_z1_pr->f_be = 0;
	results.sub_z2_z1_pr->f_wi = 0;

	results.mul_z1_z2_kr->f_re = 0;
	results.mul_z1_z2_kr->f_im = 0;
	results.mul_z1_z2_pr->f_be = 0;
	results.mul_z1_z2_pr->f_wi = 0;

	results.div_z1_z2_kr->f_re = 0;
	results.div_z1_z2_kr->f_im = 0;
	results.div_z1_z2_pr->f_be = 0;
	results.div_z1_z2_pr->f_wi = 0;
	results.div_z2_z1_kr->f_re = 0;
	results.div_z2_z1_kr->f_im = 0;
	results.div_z2_z1_pr->f_be = 0;
	results.div_z2_z1_pr->f_wi = 0;
*/