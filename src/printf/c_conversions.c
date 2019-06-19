#include "ft_printf.h"
#include "misc.h"

int	c_conversions(t_params ft, va_list *args, t_list **lst)
{
	char	space_char;
	int		spaces;
	char	arg_val;
	int		tmp;
	char 	*str;

	tmp = 0;
	arg_val = va_arg(*args, int);
	space_char = (ft.flags & ZERO_FLAG) ? '0' : ' ';
	spaces = ft.field_width - ((1 > ft.precision) ? 1 : ft.precision)
			- ((ft.flags & PLUS_FLAG) || (arg_val < 0) ||
			(ft.flags & SPACE_FLAG));
	spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	if (!(str = (char *)malloc(sizeof(char) * spaces + 2)))
		free(str);
	else
	{
		str[spaces + 2] = '\0';
		str[spaces + 1] = arg_val;
		while (spaces >= 0)
			str[spaces--] = space_char;
		if ((tmp = create_node(str, ft_strlen(str) + 2, lst)) == -1)
			return (tmp);
	}
	tmp += ft_after_num(ft, 2, lst, 0);
	return (tmp);
}
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
