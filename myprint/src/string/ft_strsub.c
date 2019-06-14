#include "ft_string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (0);
	res = ft_strnew(len);
	if (!res)
		return (0);
	ft_strncpy(res, s + start, len);
	return (res);
}