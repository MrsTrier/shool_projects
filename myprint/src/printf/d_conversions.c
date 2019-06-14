/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:45:25 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 14:33:19 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "libft.h"

int		before_num(t_params ft, int res, long long arg_val, int *out)
{
	char	space_char;
	int		spaces;
	int		tmp;

	space_char = (ft.flags & ZERO_FLAG) ? '0' : ' ';
	spaces = ft.field_width - ((res > ft.precision) ? res : ft.precision)
			- ((ft.flags & PLUS_FLAG) || (arg_val < 0) ||
			(ft.flags & SPACE_FLAG));
	spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	if ((tmp = fill_with_chars(spaces, space_char)) == -1)
		return (tmp);
	*out += tmp;
	if (((ft.flags & PLUS_FLAG) || (arg_val < 0)) && !(ft.flags & ZERO_FLAG))
	{
		if ((tmp = write(1, (arg_val < 0) ? "-" : "+", 1)) == -1)
			return (tmp);
		*out += tmp;
	}
	if ((tmp = fill_with_chars(ft.precision - res, '0')) == -1)
		return (tmp);
	*out += tmp;
	return (spaces);
}

int		ft_dconversion(t_params ft, int res, long long arg_val)
{
	int		tmp;
	int		out;
	int		spaces;

	tmp = 0;
	out = 0;
	spaces = before_num(ft, res, arg_val, &out);
	((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_putnbr(arg_val);
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
	{
		spaces = (ft.field_width - ((ft.precision > res) ?
				ft.precision : res) - ((ft.flags & PLUS_FLAG)
				|| (arg_val < 0) || (ft.flags & SPACE_FLAG)));
		if ((tmp = fill_with_chars(spaces, ' ')) == -1)
			return (tmp);
		out += tmp;
	}
	return (out);
}

int		ft_print_sign(int flags, intmax_t arg_val)
{
	int		tmp;

	tmp = 0;
	if (((flags & PLUS_FLAG) || (arg_val < 0)) && (flags & ZERO_FLAG))
		if ((tmp = write(1, (arg_val < 0) ? "-" : "+", 1)) == -1)
			return (tmp);
	if ((flags & SPACE_FLAG) && !((flags & PLUS_FLAG) || (arg_val < 0)))
		if ((tmp = write(1, " ", 1)) == -1)
			return (tmp);
	return (tmp);
}

int		d_conversions(t_params ft, va_list *args, t_list **lst)
{
	long long int		arg_val;
	int					res;
	int					tmp;

	arg_val = convert_flags(ft.flags, args);
	res = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_numlgh_long(arg_val);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
				ft.flags &= ~ZERO_FLAG : ft.flags;
	if ((tmp = ft_print_sign(ft.flags, arg_val)) == -1)
		return (tmp);
	res += tmp;
	if ((tmp = ft_dconversion(ft, res - tmp, arg_val)) == -1)
		return (tmp);
	res += tmp;
	return (res);
}
