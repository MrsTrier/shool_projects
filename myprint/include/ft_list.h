#ifndef EXPANDABLE_STRING_FT_LIST_H
#define EXPANDABLE_STRING_FT_LIST_H

#include <stddef.h>

typedef struct		s_list
{
	void			*content;
	size_t 			content_size;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content, size_t content_size);
void	ft_lstadd(t_list **alst, t_list *new);
char	*ft_lst_to_str(t_list *lst);
int		create_node(void *str, size_t len, t_list **lst);
#endif
