/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:29:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/31 16:28:19 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>

typedef struct		s_prf
{
	int			cpt[4];
	char		*top;
	char		*tmp;
	char		*tmp2;
}					t_prf;

typedef struct		s_fmt
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			hash;
	int			width;
	int			acy;
	char		*size;
	char		conv;
	int			len;
}					t_fmt;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_get_arg_nb(const char *fmt);
long long			ft_get_stype(va_list ap, t_fmt *para);
unsigned long long	ft_get_unstype(va_list ap, t_fmt *para);
int					ft_only_fmt(int fd, const char *fmt);
void				ft_init_fmt(t_fmt *current);
void				ft_init_prf(t_prf *prf);
void				ft_del_prf(t_prf *prf, t_fmt *arg);
void				ft_del_prf2(t_prf *prf, t_fmt *arg);
void				ft_del_prfo(t_prf *prf);
t_fmt				ft_analyze_arg(const char *str);
char				*ft_conv_int(va_list ap, t_fmt para);
char				*ft_conv_str(va_list ap, t_fmt para, int *cpt);
char				*ft_conv_ws(va_list ap, t_fmt para, int *cpt);
char				*ft_conv_c(va_list ap, t_fmt para, int *cpt);
char				*ft_conv_wc(va_list ap, t_fmt para, int *cpt);
char				*ft_conv_u(va_list ap, t_fmt para);
char				*ft_conv_b(va_list ap, t_fmt para);
char				*ft_conv_o(va_list ap, t_fmt para);
char				*ft_conv_p(va_list ap, t_fmt para);
char				*ft_conv_per(t_fmt para);
char				*ft_conv_error(t_fmt para);
char				*ft_conv_h(va_list ap, t_fmt para);
char				*ft_get_conv(va_list ap, t_fmt *arg, int *cpt);

#endif
