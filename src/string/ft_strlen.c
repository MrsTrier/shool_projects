//
// Created by Jasper Leann on 2019-05-24.
//

#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
