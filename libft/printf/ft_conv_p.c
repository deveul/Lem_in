/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:26:50 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:49:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_zerwithacy(t_fmt para)
{
	char	*str;

	if (para.acy == 0)
		return (ft_strdup("0x"));
	if (!(str = ft_memalloc(para.acy + 1)))
		return (NULL);
	ft_memset(str, '0', para.acy);
	str = ft_strjoinfreesec("0x", str);
	return (str);
}

static char	*ft_get_arg(t_fmt para, uintmax_t arg)
{
	int		len;
	int		save;
	char	*str;
	char	*tmp;

	if (!(str = ft_uintmax_to_hex(arg, 'x')))
		return (NULL);
	len = ft_strlen(str);
	save = len;
	if (para.acy > len)
		len = para.acy;
	if ((tmp = ft_memalloc(len - save + 1)) == 0)
		return (NULL);
	ft_memset(tmp, '0', (len - save));
	if (!(str = ft_strjoinfreeall(tmp, str)))
		return (NULL);
	str = ft_strjoinfreesec("0x", str);
	return (str);
}

char		*ft_conv_p(va_list ap, t_fmt p)
{
	char	*str;
	char	*tmp;
	void	*arg;
	int		len;

	arg = va_arg(ap, void*);
	if (p.acy != -1 && arg == 0)
		return (ft_zerwithacy(p));
	if (!(str = ft_get_arg(p, (uintmax_t)arg)))
		return (NULL);
	len = ft_strlen(str);
	if (len > p.width)
		return (str);
	if ((tmp = ft_memalloc(p.width - len + 1)) == 0)
		return (NULL);
	ft_memset(tmp, ' ', (p.width - len));
	if (len < p.width && p.minus == 0)
	{
		if (p.zero == 1)
			return (ft_strjoinfree(str, ft_memset(tmp, '0', (p.width - len))));
		return (ft_strjoinfree(tmp, str));
	}
	else
		return (ft_strjoinfree(str, tmp));
}
