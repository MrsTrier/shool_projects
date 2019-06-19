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

int		f_conversions(t_params ft, va_list *args, t_list **lst)
{
	char	*arg_val;
	int		spaces;
	int		tmp;
	char	space_char;
	long	str_len;
	char	*str;

	tmp = 0;
	arg_val = get_float(ft, args);
	str_len = ft_strlen(arg_val);
	space_char = (ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG) ? '0' : ' ';
	spaces = ft.field_width - ((str_len > ft.precision) ? str_len : ft.precision);
	spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	if (!(str = (char *)malloc(sizeof(char) * spaces + 1)))
		free(str);
	else
	{
		str[spaces + 1] = '\0';
		while (spaces >= 0)
			str[spaces--] = space_char;
		if ((tmp = create_node(str, ft_strlen(str), lst)) == -1)
			return (tmp);
	}
	create_node(arg_val, str_len, lst);
	if (ft.flags & MINUS_FLAG)
	{
		spaces = ft.field_width - ((str_len > ft.precision) ? str_len : ft.precision);
		if (!(str = (char *)malloc(sizeof(char) * spaces + 1)))
			free(str);
		else
		{
			str[spaces + 1] = '\0';
			while (spaces >= 0)
				str[spaces--] = space_char;
			if ((tmp = create_node(str, ft_strlen(str), lst)) == -1)
				return (tmp);
		}
	}
	return (tmp);
}
