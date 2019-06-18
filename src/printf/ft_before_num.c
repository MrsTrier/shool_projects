/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:34:14 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/13 16:48:53 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversions.h"
#include "libft.h"
#include "ft_list.h"

int		place_hash(char c, t_params ft, int *i, char *str)
{
	int hash;

	hash = (ft.flags & HASH_FLAG) ? 1 : 0;
	if (((ft.flags & ZERO_FLAG) ? '0' : ' ') == c)
	{
		if (hash)
		{
			str[*i] = '0';
			*i += 1;
		}
	}
}

void	place_zero(char c, t_params ft, int *i, char *str)
{
	int hash;

	hash = (ft.flags & HASH_FLAG) ? 2 : 0;
	if (((ft.flags & ZERO_FLAG) ? '0' : ' ') == c)
	{
		if (hash)
		{
			str[*i] = '0';
			*i += 1;
			str[*i] = (ft.conversion == 'x') ? 'x' : 'X';
			*i += 1;
		}
	}
}

char	*ft_other_flags(t_params ft, int str_len, int hash, int spaces)
{
	int		i;
	char	space_char;
	char	*str;
	int		lengh;

	i = 0;
	space_char = (ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG) ? '0' : ' ';
	lengh = ((ft.conversion == 'o') ? 0 : hash) + ((str_len > ft.precision) ?
				0 : ft.precision - str_len);
	if (!(str = (char *)malloc(sizeof(char) * (((spaces > 0) ? spaces : 0) + lengh + 1))))
		return (NULL);
	(ft.conversion == 'o') ? place_hash('0', ft, &i, str)
			: place_zero('0', ft, &i, str);
	while (i < spaces)
		str[i++] = space_char;
	(ft.conversion == 'o') ? place_hash(' ', ft, &i, str)
			: place_zero(' ', ft, &i, str);
	while (i < spaces + lengh)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

int		ft_before_num(t_params ft, int str_len, int hash, t_list **lst)
{
	int		i;
	char	*str;
	char	space_char;
	int		spaces;

	i = 0;
	space_char = (ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG) ? '0' : ' ';
	spaces = ft.field_width - ((str_len > ft.precision) ?
				str_len : ft.precision) - ((ft.conversion == 'o') ? 0 : hash);
	spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	if (ft.conversion == 's' && ft.conversion == 'c')
	{
		str = (char *)malloc(sizeof(char) * (spaces + 1));
		while (i < spaces)
			str[i++] = space_char;
		str[i] = '\0';
		create_node(str, spaces + 1, lst);
		return (0);
	}
	else
	{
		if ((str = ft_other_flags(ft, str_len, hash, spaces)))
			create_node(str, ft_strlen(str) + 1, lst);
	}
	return (i);
}
// // PPPP

//     	res = 0;
// 	tmp = 0;
// 	if (!(ft.flags & MINUS_FLAG))
// 	{
// 		if ((tmp = fill_with_chars(ft.field_width - (ft.precision > str_len ?
// 			ft.precision : str_len), (ft.flags & ZERO_FLAG) ? '0' : ' ')) == -1)
// 			return (tmp);
// 		res += tmp;
// 	}
// 	if ((tmp = fill_with_chars(ft.precision - str_len, '0')) == -1)
// 		return (tmp);


// //SSSS

// 	space_char = (ft.flags & ZERO_FLAG) && !(ft.flags & MINUS_FLAG) ? '0' : ' ';
// 	str_len = ft_strlen(arg_val);
// 	str_len = ft.precision != -1 && ft.precision < str_len ? ft.precision : str_len;
// 	if (!(ft.flags & MINUS_FLAG))
// 	{
// 		if ((tmp = fill_with_chars(ft.field_width - str_len, space_char)) == -1)
// 			return (tmp);
// 		res += tmp;
// 	}
