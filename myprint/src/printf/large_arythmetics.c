/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_arythmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:37:41 by jleann            #+#    #+#             */
/*   Updated: 2019/06/04 18:37:44 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_arythmetics.h"

unsigned	*init_num(unsigned num)
{
	unsigned	*res;

	if (!(res = malloc(sizeof(int) * MASS_LEN)))
		return (NULL);
	res[0] = 1;
	res[1] = num % BASE;
	if (num / BASE)
	{
		res[2] = num / BASE;
		res[0]++;
	}
	return (res);
}

void		sum_longnum(unsigned *left, unsigned *right, unsigned *dst)
{
	unsigned res;
	unsigned max_len;
	int tail;
	unsigned cur;

	tail = 0;
	cur = 1;
	max_len = left[0] > right[0] ? left[0] : right[0];
	while (cur <= max_len || tail)
	{
		res = (cur <= left[0] ? left[cur] : 0) + (cur <= right[0] ? right[cur] :
												  0) + tail;
		tail = res / BASE;
		dst[cur] = res % BASE;
		cur++;
	}
	dst[0] = cur - 1;
}

void		mul_dig_longnum(unsigned *num, unsigned char dig, unsigned *dst)
{
	unsigned long	res;
	int				tail;
	unsigned		cur;

	tail = 0;
	cur = 1;
	while (cur <= num[0] || tail)
	{
		res = (unsigned long)(cur <= num[0] ? num[cur] : 0) * dig + tail;
		tail = res / BASE;
		dst[cur] = res % BASE;
		cur++;
	}
	dst[0] = cur - 1;
}

int			calc_uint_len(unsigned num)
{
	unsigned res;

	res = 0;
	while (num != 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

void		div_10_longnum(unsigned *num)
{
	unsigned        old_tail;
	unsigned		tail;
	int				cur;

	tail = 0;
	cur = num[0];
	while (cur >= 1)
	{
		old_tail = tail;
		tail = num[cur] % 10;
		num[cur] = num[cur] / 10 + (BASE / 10) * old_tail;
		cur--;
	}
	if (!num[num[0]])
		num[0] -= 1;
}

int			get_first_dig(unsigned num)
{
	int res;

	res = 1;
	while (num / res > 9)
		res *= 10;
	return (num / res);
}

void		apply_precision(unsigned *i_part, unsigned *f_part, int precision)
{
	int cur;
	int y;
	int tmp;

	tmp = calc_uint_len(f_part[f_part[0]]);
	y = (precision + 2 - tmp) / 9 + 1 + (((precision + 2 - tmp) % 9) ? 1 : 0);
	if ((int)(f_part[0]) <= y)
		return ;
	cur = 0;
	while (++cur <= y)
		f_part[cur] = f_part[f_part[0] - y + cur];
	f_part[0] = y;
	y = (f_part[0] - 1) * 9 + tmp - precision;
	tmp = 0;
	while (tmp++ < y - 2)
		div_10_longnum(f_part);
	if ((f_part[1] % 10) > 5 || (((f_part[1] % 10) == 5) &&
								 (f_part[1] / 10 % 10 % 2) != 0))
	{
		sum_longnum(f_part, init_num(10), f_part);
		if (get_first_dig(f_part[f_part[0]]) != 1)
			sum_longnum(i_part, init_num(1), i_part);
	}
	div_10_longnum(f_part);
}
