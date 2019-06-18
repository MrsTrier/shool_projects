#include "ft_string.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;

	if (dst == src)
		return (dst);
	cur = 0;
	while (cur < n)
	{
		((unsigned char *)dst)[cur] = ((unsigned char *)src)[cur];
		cur++;
	}
	return (dst);
}