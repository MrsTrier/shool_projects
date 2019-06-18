/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:31 by jleann            #+#    #+#             */
/*   Updated: 2019/06/12 20:18:49 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "ft_list.h"
#include "ft_string.h"


void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

void	print_arg(const char **format, va_list *args, t_list **lst)
{
	t_params	formating;

	(*format)++;
	formating.flags = get_flags(format);
	formating.field_width = get_field_width(format, args);
	formating.precision = get_precision(format, args);
	formating.flags |= get_conv_flags(format);
	formating.conversion = get_conversion(format);
	print_conversion(formating, args, lst);
}



void	main_loop(const char *format, va_list *args, t_list *res_lst)
{
	const char	*tmp;
	t_list		*last_lst;

	last_lst = res_lst;
	while (*format)
	{
		tmp = format;
		while (*tmp && *tmp != '%')
			tmp++;
		create_node(ft_strsub(format, 0, tmp - format), tmp - format + 1,
				&last_lst);
		format = tmp;
		if (*tmp == '%')
			print_arg(&format, args, &last_lst);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*res_lst;
	char 		*tmp_str;
	int 		res;

	va_start(args, format);
	res_lst = ft_lstnew(NULL, 0);
	main_loop(format, &args, res_lst);
	tmp_str = ft_lst_to_str(res_lst);
	res = write(1, tmp_str, ft_strlen(tmp_str));
	if (res_lst->content)
		free_lst(res_lst);
	free(tmp_str);
	va_end(args);
	return (res);
}
