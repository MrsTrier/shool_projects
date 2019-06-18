#include "ft_string.h"

char	*ft_strnew(size_t size)
{
	if (size == (size_t)(-1))
		return (NULL);
	return (malloc(size + 1));
}