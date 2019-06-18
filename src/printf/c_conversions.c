#include "ft_printf.h"
#include "misc.h"

int	c_conversions(t_params ft, va_list *args, t_list **lst)
{
	char	arg_val;
	int		res;
	int		tmp;
	char	space_char;

	res = 0;
	arg_val = va_arg(*args, int);
	ft_before_num(ft, 1, 0, lst);
	create_node(arg_val, 2, lst);
	ft_after_num(ft, 2, lst, 0);
// 	if ((ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG))
// 		space_char = '0';
// 	else
// 		space_char = ' ';
// 	if (!(ft.flags & MINUS_FLAG))
// 	{
// 		if ((tmp = fill_with_chars(ft.field_width - 1, space_char)) == -1)
// 			return (tmp);
// 		res += tmp;
// 	}
// 	res += write(1, &arg_val, 1);
// 	if (ft.flags & MINUS_FLAG)
// 	{
// 		if ((tmp = fill_with_chars(ft.field_width - 1, space_char)) == -1)
// 			return (tmp);
// 		res += tmp;
// 	}
// 	return (res);
// }
