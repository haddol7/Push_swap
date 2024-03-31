/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeha <daeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:58:07 by daeha             #+#    #+#             */
/*   Updated: 2024/03/30 23:33:37 by daeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define OK 1
# define ERROR 0

# define TRUE 1
# define FALSE 0

# define ZERO '0'
# define SPACE ' '

typedef struct s_flag
{
	int		width;
	int		preci;
	short	alt;
	short	left;
	short	sign;
	short	sign_p;
	char	zero;
}	t_flag;

typedef struct s_field
{
	char	*str;
	char	type;
	int		size;
}	t_field;

int		ft_printf(const char *format, ...);
void	parse_flag(const char *format, t_flag *flag, int *i);
void	flag_priority(t_flag *flag);
int		make_conversion(t_field *field, t_flag flag, va_list *ap, char ch);
int		make_speci_c(t_field *field, t_flag flag, va_list *ap);
int		make_speci_s(t_field *field, t_flag flag, va_list *ap);
int		make_speci_p(t_field *field, t_flag flag, va_list *ap);
int		make_speci_d_i(t_field *field, t_flag flag, va_list *ap, char type);
int		make_speci_x(t_field *field, t_flag *flag, va_list *ap, char type);
int		make_speci_u(t_field *field, t_flag flag, va_list *ap);
int		make_speci_per(t_field *field, t_flag flag);
int		join_width(t_field *field, t_flag flag);
int		join_preci(t_field *field, int preci);
int		join_alt(t_field *field, int alt);
int		join_sign(t_field *field, int sign, int sign_p);
int		make_field_c_p_per(t_field *field, t_flag flag);
int		make_field_s(t_field *field, t_flag flag);
int		make_field_u(t_field *field, t_flag flag);
int		make_field_d_i(t_field *field, t_flag flag);
int		make_field_x(t_field *field, t_flag flag);
int		error_free(t_field *field);
void	swap(char *ch1, char *ch2);
void	*my_memmove(void *dst, const void *src, size_t len);
char	*my_strdup(const char *str, int *size);
void	*my_memset(void *b, int c, size_t len);

#endif
