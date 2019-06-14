#include "libft.h"
#include <stdlib.h>

int	fill_with_chars(int num, char c)
{
	char *str;
	int res;
	res = 0;
	if (num > 0)
	{
		if (!(str = ft_strnew(num)))
			return (-1);
		ft_memset(str, c, num);
		res = write(1, str, num);
		free(str);
	}
	return (res);
}
