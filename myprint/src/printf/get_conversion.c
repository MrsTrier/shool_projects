#include "ft_printf.h"

int is_conversion(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
			c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%' ||
			c == 'f');
}

char	get_conversion(const char **format)
{
	char res;

	res = -1;
	if (is_conversion(**format))
	{
		res = **format;
		(*format)++;
		return (res);
	}
	else
		return (res);
}