//
// Created by Jasper Leann on 2019-05-27.
//
#include "ft_printf.h"

int is_conv_flag(char c)
{
	return (c == 'l' || c == 'L' || c == 'h');
}


int comp_flag_ll(const char **format)
{
	if (*(*format + 1) == 'l')
	{
		(*format)++;
		return (ll_FLAG);
	}
	else
		return (l_FLAG);
}

int comp_flag_hh(const char **format)
{
	if (*(*format + 1) == 'h')
	{
		(*format)++;
		return (hh_FLAG);
	}
	else
		return (h_FLAG);
}

unsigned get_conv_flags(const char **format)
{
	int res;

	res = 0;
	while (**format && is_conv_flag(**format))
	{
		if (**format == 'l')
			res |= comp_flag_ll(format);
		else if (**format == 'h')
			res |= comp_flag_hh(format);
		else if (**format == 'L')
			res |= L_FLAG;
		(*format)++;
	}
	return (res);
}