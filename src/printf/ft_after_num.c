
#include <stdlib.h>
#include "conversions.h"
#include "libft.h"
#include "ft_list.h"

int		ft_after_num(t_params ft, int str_len, t_list **lst, int hash)
{
    char 	*str;
	int		i;
	int		spaces;

	i = 0;
	spaces = ft.field_width - ((ft.precision > str_len) ? ft.precision : str_len) - hash;
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
	{
		if (!(str = (char *)malloc(sizeof(char) * (spaces + 1))))
            return (-1);
		while (i < spaces)
			str[i++] = ' ';
		str[i] = '\0';
		create_node(str, spaces + 1, lst);
	}
	return (i);
}
