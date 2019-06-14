#include "ft_printf.h"
#include "misc.h"

int	c_conversions(t_params ft, va_list *args)
{
	char	arg_val;
	int		res;
	int		tmp;
	char	space_char;

	res = 0;
	arg_val = va_arg(*args, int);
	if ((ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG))
		space_char = '0';
	else
		space_char = ' ';
	if (!(ft.flags & MINUS_FLAG))
	{
		if ((tmp = fill_with_chars(ft.field_width - 1, space_char)) == -1)
			return (tmp);
		res += tmp;
	}
	res += write(1, &arg_val, 1);
	if (ft.flags & MINUS_FLAG)
	{
		if ((tmp = fill_with_chars(ft.field_width - 1, space_char)) == -1)
			return (tmp);
		res += tmp;
	}
	return (res);
}
