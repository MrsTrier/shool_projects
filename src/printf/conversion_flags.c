/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/07 15:19:57 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include <unistd.h>

long long	convert_flags(int flags, va_list *args)
{
	long long	n;

	if (flags & l_FLAG)
		n = va_arg(*args, long);
	else if (flags & ll_FLAG)
		n = va_arg(*args, long long);
	else
		n = va_arg(*args, int);
	if (flags & h_FLAG)
		n = (short)n;
	else if (flags & hh_FLAG)
		n = (signed char)n;
	return (n);
}
