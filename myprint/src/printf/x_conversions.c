/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:08:21 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 17:43:56 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "conversions.h"
#include "libft.h"
#include "ft_string.h"

int		ft_xconversions(t_params ft, int str_len, t_list **lst, int hash)
{
	int		res;
	char 	*str;
	int		i;
	int		spaces;

	res = 0;
	i = 0;
	spaces = ft.field_width - ((ft.precision > str_len) ? ft.precision : str_len) - hash;
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
	{
		str = (char *)malloc(sizeof(char) * (spaces + 1));
		while (i < spaces)
			str[i++] = ' ';
		str[i] = '\0';
		create_node(str, spaces + 1, lst);
	}
	return (res);
}

int		x_conversions(t_params ft, va_list *args, t_list **lst)
{
	long long	arg_val;
	int			tmp;
	char		*num;
	int			str_len;

	arg_val = convert_flags(ft.flags, args);
	if (ft.flags & l_FLAG || ft.flags & ll_FLAG)
		num = ft_itoa_base_hex_long(arg_val, 16,
		(ft.conversion == 'x') ? 0 : 1);
	else
		num = ft_itoa_base_hex(arg_val, 16, (ft.conversion == 'x') ? 0 : 1);
	(arg_val == 0) ? ft.flags &= ~HASH_FLAG : ft.flags;
	str_len = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_strlen(num);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
								ft.flags &= ~ZERO_FLAG : ft.flags;
	ft_before_num(ft, str_len, (ft.flags & HASH_FLAG) ? 2 : 0, lst);
	create_node(num, str_len + 1, lst);
	if ((tmp = ft_xconversions(ft, str_len, lst, (ft.flags & HASH_FLAG) ? 2 : 0)) == -1)
		return (tmp);
	tmp += str_len;
	return (tmp);
}
