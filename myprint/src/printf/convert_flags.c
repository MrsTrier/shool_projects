/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:06:52 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/05 16:08:12 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include <unistd.h>

unsigned long long int	convert_flags_u(int flags, va_list *args)
{
	unsigned long long int	n;

	if (flags & l_FLAG)
		n = va_arg(*args, unsigned long);
	else if (flags & ll_FLAG)
		n = va_arg(*args, unsigned long long);
	else
		n = va_arg(*args, unsigned int);
	if (flags & h_FLAG)
		n = (unsigned short)n;
	else if (flags & hh_FLAG)
		n = (unsigned char)n;
	return (n);		
}