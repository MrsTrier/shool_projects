/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:18:58 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/03 19:33:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "misc.h"

char	*get_float(t_params params, va_list *args);

void	f_conversions(t_params ft, va_list *args, t_list **lst)
{
	char	*arg_val;
	int		res;
	int		tmp;
	char	space_char;
	long	str_len;

	res = 0;
	arg_val = get_float(ft, args);
	space_char = (ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG) ? '0' : ' ';
	str_len = ft_strlen(arg_val);
	if (!(ft.flags & MINUS_FLAG))
	{
//		if ((tmp = fill_with_chars(ft.field_width - str_len, space_char)) == -1)
//			return (tmp);
		res += tmp;
	}
//	if ((tmp = write(1, arg_val, str_len)) == -1)
//		return (tmp);
	res += tmp;
	if (ft.flags & MINUS_FLAG)
	{
//		if ((tmp = fill_with_chars(ft.field_width - str_len, space_char)) == -1)
//			return (tmp);
		res += tmp;
	}
//	return (res);
}
