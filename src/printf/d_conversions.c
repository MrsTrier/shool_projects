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

int		before_num(t_params ft, int str_len, long long arg_val, t_list **lst)
{
	char	space_char;
	int		spaces;
	char	*str;
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	space_char = (ft.flags & ZERO_FLAG) ? '0' : ' ';
	spaces = ft.field_width - ((str_len > ft.precision) ? str_len : ft.precision)
			- ((ft.flags & PLUS_FLAG) || (arg_val < 0) ||
			(ft.flags & SPACE_FLAG));
	spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	if (!(str = (char *)malloc(sizeof(char) * spaces + 1)))
		free(str);
	else
	{
		while (i < spaces)
			str[i++] = space_char;
		str[i] = '\0';
		if ((tmp = create_node(str, spaces + 1, lst)) == -1)
			return (tmp);
		i--;
	}
	if (((ft.flags & PLUS_FLAG) || (arg_val < 0)) && !(ft.flags & ZERO_FLAG))
		if ((tmp = create_node((arg_val < 0) ? "-" : "+", 2, lst)) == -1)
			return (tmp);
	return (((i + tmp) > 0) ? (i + tmp) : 0);
}

int		ft_dconversion(t_params ft, int str_len, long long arg_val, t_list **lst)
{
	int		tmp;
	char	*str;
	int		spaces;
	int		i;

	tmp = 0;
	i = 0;
	spaces = before_num(ft, str_len, arg_val, lst);
	if (ft.precision - str_len > 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft.precision - str_len + 1))))
			free(str);
		while (i < ft.precision - str_len)
			str[i++] = '0';
		str[i] = '\0';
		if ((tmp = create_node(str, ft.precision - str_len + 1, lst)) == -1)
			return (tmp);
	}
	return (spaces + i);
}

int		ft_print_sign(int flags, intmax_t arg_val, t_list **lst)
{
	int		tmp;

	tmp = 0;
	if (((flags & PLUS_FLAG) || (arg_val < 0)) && (flags & ZERO_FLAG))
		if ((tmp = (arg_val < 0) ? create_node("-", 2, lst) :
			create_node("+", 2, lst) == -1))
				return (tmp);
	if ((flags & SPACE_FLAG) && !((flags & PLUS_FLAG) || (arg_val < 0)))
		if ((tmp = create_node(" ", 2, lst) == -1))
			return (tmp);
	return (tmp);
}

int		d_conversions(t_params ft, va_list *args, t_list **lst)
{
	long long int		arg_val;
	int					str_len;
	int					tmp;
	int					res;
	char				*num;

	res = 0;
	str_len = 0;
	arg_val = convert_flags(ft.flags, args);
	if ((arg_val != 0) && (ft.precision != 0))
		num = ft_itoa_base(arg_val, 10, 0);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
				ft.flags &= ~ZERO_FLAG : ft.flags;
	if ((arg_val != 0) && (ft.precision != 0))
		str_len = ft_strlen(num);
	if ((tmp = ft_print_sign(ft.flags, arg_val, lst) == -1))
		return (tmp);
	res += tmp;
	if ((tmp = ft_dconversion(ft, str_len, arg_val, lst) == -1))
		return (tmp);
	res += tmp;
	((arg_val == 0) && (ft.precision == 0)) ? 0 : create_node(num, str_len + 1, lst);
	res += str_len;
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
		if ((tmp = ft_after_num(ft, str_len, lst, ((ft.flags & PLUS_FLAG) || (arg_val < 0) || (ft.flags & SPACE_FLAG)))) == -1)
			return (tmp);
	res += (tmp > 0) ? tmp - 1 : 0; 
	return (res);
}
