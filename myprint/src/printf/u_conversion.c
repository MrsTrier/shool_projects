/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:26:13 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/13 16:21:29 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "libft.h"

int		ft_uconversion(t_params ft, int res, unsigned long long arg_val)
{
	char	space_char;
	int		spaces;
	int		tmp;
	int		out;

	tmp = 0;
	out = 0;
	// space_char = (ft.flags & ZERO_FLAG) ? '0' : ' ';
	// spaces = ft.field_width - ((res > ft.precision) ? res : ft.precision);
	// spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	// if ((tmp = fill_with_chars(spaces, space_char)) == -1)
	// 	return (tmp);
	// out += tmp;
	// if ((tmp = fill_with_chars(ft.precision - res, '0')) == -1)
	// 	return (tmp);
	// out += tmp;
	// out += (res == 0) ? 0 : ft_putnbr_u(arg_val);
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
	{
		spaces = (ft.field_width - ((ft.precision > res) ? ft.precision : res));
		if ((tmp = fill_with_chars(spaces, ' ')) == -1)
			return (tmp);
		out += tmp;
	}
	return (out);
}

int		u_conversions(t_params ft, va_list *args, t_list **lst)
{
	unsigned long long int	arg_val;
	int						res;
	int						tmp;
	char					*num;
	int						str_len;

	res = 0;
	arg_val = convert_flags_u(ft.flags, args);
	// res = (ft.flags & l_FLAG || ft.flags & ll_FLAG) ?
	// 		ft_numlgh_long(arg_val) : ft_numlgh(arg_val);
	num = ft_itoa_base_hex(arg_val, 10, (ft.conversion == 'x') ? 0 : 1);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
			ft.flags &= ~ZERO_FLAG : ft.flags;
	ft.flags &= ~HASH_FLAG;
	str_len = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_strlen(num);
	tmp = ft_before_num(ft, str_len, 0, lst);
	create_node(num, str_len + 1, lst);
//	ft_uconversion(ft, res, arg_val);t, str_len, lst, (ft.flags & HASH_FLAG) ? 2 : 0
	return (tmp);
}
