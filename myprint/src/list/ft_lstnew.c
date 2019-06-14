#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list *res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	res->content = content;
	res->content_size = content_size;
	res->next = NULL;
	return (res);

}