//
// Created by fellum on 6/8/19.
//

#ifndef FT_PRINTF_LIBFT_H
#define FT_PRINTF_LIBFT_H
#include "ft_string.h"


//OLD
# include <stdlib.h>
# include <unistd.h>
char	*ft_itoa_base(long long int n, int base, int uppercase);
char	*ft_itoa_base_hex(unsigned int n, int base, int uppercase);
char	*ft_itoa_base_hex_long(unsigned long long n, int base, int uppercase);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putnbr(long long int n);
int		ft_putnbr_u(unsigned long long n);
int		ft_numlgh(long long arg_val);
int		ft_numlgh_long(unsigned long long arg_val);
void	ft_memdel(void **ap);
#endif //FT_PRINTF_LIBFT_H
