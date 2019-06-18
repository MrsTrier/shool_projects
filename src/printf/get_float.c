#include "ft_printf.h"
#include "libft.h"

char		*make_double(double val, int precision);
char		*make_ldouble(long double val, int precision);
char		*make_float(float val, int precision);

char	*get_float(t_params params, va_list *args)
{
	int precision;

	precision = params.precision == -1? 6 : params.precision;
	if (params.flags & L_FLAG)
		return (make_ldouble(va_arg(*args, double), precision));
	else
		return (make_double(va_arg(*args, double), precision));
}