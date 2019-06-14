/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlgh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:24:46 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/05 15:44:20 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_numlgh(unsigned int arg_val)
{
	int res;

	if (arg_val == 0)
		return (1);
	res = 0;
	while (arg_val)
	{
		arg_val /= 10;
		res++;
	}
	return (res);
}
