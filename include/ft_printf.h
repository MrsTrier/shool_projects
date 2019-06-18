//
// Created by Jasper Leann on 2019-05-22.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "misc.h"
#include "ft_list.h"

# define HASH_FLAG 1
# define PLUS_FLAG 2
# define MINUS_FLAG 4
# define SPACE_FLAG 8
# define ZERO_FLAG 16
# define l_FLAG 32
# define ll_FLAG 64
# define h_FLAG 128
# define hh_FLAG 256
# define L_FLAG 512

typedef struct		s_params
{
	int				precision;
	int				field_width;
	unsigned		flags;
	char			conversion;
}					t_params;

int			get_field_width(const char **format, va_list *args);
int			get_flags(const char **format);
int			get_precision(const char **format, va_list *args);
unsigned	get_conv_flags(const char **format);
char		get_conversion(const char **format);
int			ft_printf(const char *format, ...);
int			print_conversion(t_params formating, va_list *args, t_list **lst);
int			ft_before_num(t_params ft, int str_len, int hash, t_list **lst);
int			ft_after_num(t_params ft, int str_len, t_list **lst, int hash);


#endif //FT_PRINTF_FT_PRINTF_H
