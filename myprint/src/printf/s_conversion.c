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
#include "ft_string.h"

int	create_node(void *str, size_t len, t_list **lst);


void	s_conversions(t_params ft, va_list *args, t_list **lst)
{
	char	*arg_val;
	char	*res;
	size_t	str_len;

	if (!(arg_val = va_arg(*args, char *)))
		arg_val = "(null)";
	str_len = ft_strlen(arg_val);
	str_len = ft.precision != -1 && ft.precision < str_len ? ft.precision : str_len;
	if (!(res = ft_strsub(arg_val, 0, str_len)))
		return ;
	create_node(res, str_len + 1, lst);
}
