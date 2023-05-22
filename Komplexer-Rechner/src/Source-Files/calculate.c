#include "calculate.h"
#include <math.h>

struct results s_calc_all(const struct comp z1_k, const struct polar z1_p, const struct comp z2_k, const struct polar z2_p)
{
	struct results results;

	default_init(&results);

	results.z1_kr = z1_k;
	results.z1_pr = z1_p;

	results.z2_kr = z2_k;
	results.z2_pr = z2_p;

	c_pre_calc(&results);

	c_add(&results);
	c_sub(&results);
	c_mul(&results);
	c_div(&results);

	return results;
}

void c_pre_calc(struct results* results)
{
	struct polar tmp_1;
	to_polar(&tmp_1, results->z1_kr);
	results->z1_pr = tmp_1;

	struct polar tmp_2;
	to_polar(&tmp_2, results->z2_kr);
	results->z2_pr = tmp_2;
}

void c_add(struct results* results)
{
	results->add_z1_z2_kr.f_re = results->z1_kr.f_re + results->z2_kr.f_re;
	results->add_z1_z2_kr.f_im = results->z1_kr.f_im + results->z2_kr.f_im;

	struct polar tmp;
	to_polar(&tmp, results->add_z1_z2_kr);
	results->add_z1_z2_pr = tmp;

	const int add_z1_z2_kr_f_re = u_get_number_length(results->add_z1_z2_kr.f_re);
	const int add_z1_z2_kr_f_im = u_get_number_length(results->add_z1_z2_kr.f_im);
	const int add_z1_z2_kr = add_z1_z2_kr_f_re + add_z1_z2_kr_f_im + 29;

	const int add_z1_z2_pr_f_be = u_get_number_length(results->add_z1_z2_pr.f_be);
	const int add_z1_z2_pr_f_wi = u_get_number_length(results->add_z1_z2_pr.f_wi);
	const int add_z1_z2_pr = add_z1_z2_pr_f_be + add_z1_z2_pr_f_wi + 38;

	const int max_length = max(add_z1_z2_pr, add_z1_z2_kr);
	if (max_length > results->max_len)
	{
		results->max_len = max_length;
	}
}

void c_sub(struct results* results)
{
	results->sub_z1_z2_kr.f_re = results->z1_kr.f_re - results->z2_kr.f_re;
	results->sub_z1_z2_kr.f_im = results->z1_kr.f_im - results->z2_kr.f_im;

	results->sub_z2_z1_kr.f_re = results->z2_kr.f_re - results->z1_kr.f_re;
	results->sub_z2_z1_kr.f_im = results->z2_kr.f_im - results->z1_kr.f_im;

	struct polar tmp12;
	to_polar(&tmp12, results->sub_z1_z2_kr);
	results->sub_z1_z2_pr = tmp12;

	struct polar tmp21;
	to_polar(&tmp21, results->sub_z2_z1_kr);
	results->sub_z2_z1_pr = tmp21;

	const int sub_z1_z2_kr_f_re = u_get_number_length(results->sub_z1_z2_kr.f_re);
	const int sub_z1_z2_kr_f_im = u_get_number_length(results->sub_z1_z2_kr.f_im);
	const int sub_z1_z2_kr = sub_z1_z2_kr_f_re + sub_z1_z2_kr_f_im + 29;

	const int sub_z2_z1_kr_f_re = u_get_number_length(results->sub_z2_z1_kr.f_re);
	const int sub_z2_z1_kr_f_im = u_get_number_length(results->sub_z2_z1_kr.f_im);
	const int sub_z2_z1_kr = sub_z2_z1_kr_f_re + sub_z2_z1_kr_f_im + 29;


	const int sub_z1_z2_pr_f_be = u_get_number_length(results->sub_z1_z2_pr.f_be);
	const int sub_z1_z2_pr_f_wi = u_get_number_length(results->sub_z1_z2_pr.f_wi);
	const int sub_z1_z2_pr = sub_z1_z2_pr_f_be + sub_z1_z2_pr_f_wi + 38;

	const int sub_z2_z1_pr_f_be = u_get_number_length(results->sub_z2_z1_pr.f_be);
	const int sub_z2_z1_pr_f_wi = u_get_number_length(results->sub_z2_z1_pr.f_wi);
	const int sub_z2_z1_pr = sub_z2_z1_pr_f_be + sub_z2_z1_pr_f_wi + 38;

	const int max_length_kr = max(sub_z1_z2_kr, sub_z2_z1_kr);
	const int max_length_pr = max(sub_z1_z2_pr, sub_z2_z1_pr);
	const int max_length = max(max_length_pr, max_length_kr);
	if (max_length > results->max_len)
	{
		results->max_len = max_length;
	}
}

void c_mul(struct results* results)
{
	results->mul_z1_z2_pr.f_be = results->z1_pr.f_be * results->z2_pr.f_be;
	results->mul_z1_z2_pr.f_wi = results->z1_pr.f_wi + results->z2_pr.f_wi;

	struct comp tmp;
	to_comp(&tmp, results->mul_z1_z2_pr);
	results->mul_z1_z2_kr = tmp;

	const int mul_z1_z2_kr_f_re = u_get_number_length(results->mul_z1_z2_kr.f_re);
	const int mul_z1_z2_kr_f_im = u_get_number_length(results->mul_z1_z2_kr.f_im);
	const int mul_z1_z2_kr = mul_z1_z2_kr_f_re + mul_z1_z2_kr_f_im + 29;

	const int mul_z1_z2_pr_f_be = u_get_number_length(results->mul_z1_z2_pr.f_be);
	const int mul_z1_z2_pr_f_wi = u_get_number_length(results->mul_z1_z2_pr.f_wi);
	const int mul_z1_z2_pr = mul_z1_z2_pr_f_be + mul_z1_z2_pr_f_wi + 38;

	const int max_length = max(mul_z1_z2_pr, mul_z1_z2_kr);
	if (max_length > results->max_len)
	{
		results->max_len = max_length;
	}
}

void c_div(struct results* results)
{
	results->div_z1_z2_pr.f_be = results->z1_pr.f_be / results->z2_pr.f_be;
	results->div_z1_z2_pr.f_wi = results->z1_pr.f_wi - results->z2_pr.f_wi;

	results->div_z2_z1_pr.f_be = results->z2_pr.f_be / results->z1_pr.f_be;
	results->div_z2_z1_pr.f_wi = results->z2_pr.f_wi - results->z1_pr.f_wi;

	struct comp tmp12;
	to_comp(&tmp12, results->div_z1_z2_pr);
	results->div_z1_z2_kr = tmp12;

	struct comp tmp21;
	to_comp(&tmp21, results->div_z2_z1_pr);
	results->div_z2_z1_kr = tmp21;

	const int div_z1_z2_kr_f_re = u_get_number_length(results->div_z1_z2_kr.f_re);
	const int div_z1_z2_kr_f_im = u_get_number_length(results->div_z1_z2_kr.f_im);
	const int div_z1_z2_kr = div_z1_z2_kr_f_re + div_z1_z2_kr_f_im + 29;

	const int div_z2_z1_kr_f_re = u_get_number_length(results->div_z2_z1_kr.f_re);
	const int div_z2_z1_kr_f_im = u_get_number_length(results->div_z2_z1_kr.f_im);
	const int div_z2_z1_kr = div_z2_z1_kr_f_re + div_z2_z1_kr_f_im + 29;

	const int div_z1_z2_pr_f_be = u_get_number_length(results->div_z1_z2_pr.f_be);
	const int div_z1_z2_pr_f_wi = u_get_number_length(results->div_z1_z2_pr.f_wi);
	const int div_z1_z2_pr = div_z1_z2_pr_f_be + div_z1_z2_pr_f_wi + 38;

	const int div_z2_z1_pr_f_be = u_get_number_length(results->div_z2_z1_pr.f_be);
	const int div_z2_z1_pr_f_wi = u_get_number_length(results->div_z2_z1_pr.f_wi);
	const int div_z2_z1_pr = div_z2_z1_pr_f_be + div_z2_z1_pr_f_wi + 38;

	const int max_length_kr = max(div_z1_z2_kr, div_z2_z1_kr);
	const int max_length_pr = max(div_z1_z2_pr, div_z2_z1_pr);
	const int max_length = max(max_length_pr, max_length_kr);
	if (max_length > results->max_len)
	{
		results->max_len = max_length;
	}
}

void to_comp(struct comp* out, const struct polar in)
{
	out->f_re = in.f_be * cosf(in.f_wi);
	out->f_im = in.f_be * sinf(in.f_wi);
}

void to_polar(struct polar* out, const struct comp in)
{
	if (in.f_re != 0)
	{
		out->f_be = sqrtf(powf(in.f_re, 2) + powf(in.f_im, 2));
		out->f_wi = atanf(in.f_im / in.f_re);
	}
	else
	{
		out->f_be = 0;
		out->f_wi = 0;
	}
}

void default_init(struct results* results)
{
	results->max_len = 38;

	results->z1_kr.f_re = 0;
	results->z1_kr.f_im = 0;
	results->z2_kr.f_re = 0;
	results->z2_kr.f_im = 0;

	results->z1_pr.f_be = 0;
	results->z1_pr.f_wi = 0;
	results->z2_pr.f_be = 0;
	results->z2_pr.f_wi = 0;

	results->add_z1_z2_kr.f_re = 0;
	results->add_z1_z2_kr.f_im = 0;
	results->add_z1_z2_pr.f_be = 0;
	results->add_z1_z2_pr.f_wi = 0;

	results->sub_z1_z2_kr.f_re = 0;
	results->sub_z1_z2_kr.f_im = 0;
	results->sub_z1_z2_pr.f_be = 0;
	results->sub_z1_z2_pr.f_wi = 0;
	results->sub_z2_z1_kr.f_re = 0;
	results->sub_z2_z1_kr.f_im = 0;
	results->sub_z2_z1_pr.f_be = 0;
	results->sub_z2_z1_pr.f_wi = 0;

	results->mul_z1_z2_kr.f_re = 0;
	results->mul_z1_z2_kr.f_im = 0;
	results->mul_z1_z2_pr.f_be = 0;
	results->mul_z1_z2_pr.f_wi = 0;

	results->div_z1_z2_kr.f_re = 0;
	results->div_z1_z2_kr.f_im = 0;
	results->div_z1_z2_pr.f_be = 0;
	results->div_z1_z2_pr.f_wi = 0;
	results->div_z2_z1_kr.f_re = 0;
	results->div_z2_z1_kr.f_im = 0;
	results->div_z2_z1_pr.f_be = 0;
	results->div_z2_z1_pr.f_wi = 0;
}