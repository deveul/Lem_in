/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:55:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/03 19:13:56 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_get_mask(int len)
{
	char	*tab;

	tab = NULL;
	if (len < 8)
		if (!(tab = ft_strdup("0xxxxxxx")))
			return (NULL);
	if (len >= 8 && len < 12)
		if (MB_CUR_MAX <= 1 || !(tab = ft_strdup("110xxxxx10xxxxxx")))
			return (NULL);
	if (len >= 12 && len < 17)
		if (MB_CUR_MAX <= 2 || !(tab = ft_strdup("1110xxxx10xxxxxx10xxxxxx")))
			return (NULL);
	if (len >= 17 && len < 22)
		if (MB_CUR_MAX <= 3
				|| !(tab = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx")))
			return (NULL);
	return (tab);
}

static char		*ft_writewchar(char *tab)
{
	int		len;
	int		len2;
	char	*octet[4];
	char	*str;

	len = 0;
	len2 = 0;
	str = ft_memalloc((ft_strlen(tab) / 4) + 1);
	while (tab[len])
	{
		if ((octet[len2] = ft_strndup(&tab[len], 8)) == 0)
			return (NULL);
		len += 8;
		len2++;
	}
	len = 0;
	while (len2 > 0)
	{
		str[len] = (char)ft_bi_to_dec(octet[len]);
		len2--;
		ft_strdel(&octet[len]);
		len++;
	}
	ft_strdel(&tab);
	return (str);
}

static int		ft_check_arg(unsigned int arg)
{
	if ((arg > 55295 && arg < 57344) || arg > 1114111)
		return (0);
	return (1);
}

static char		*ft_putwcinstr2(char *tab, char *bi, int len)
{
	int		len2;

	len2 = ft_strlen(tab) - 1;
	len--;
	while (len >= 0 && len2 >= 0)
	{
		if (tab[len2] == 'x')
		{
			tab[len2] = bi[len];
			len--;
		}
		len2--;
	}
	ft_strrpcall(tab, 'x', '0');
	ft_strdel(&bi);
	return (ft_writewchar(tab));
}

char			*ft_putwcinstr(wchar_t wc)
{
	char			*tab;
	unsigned int	nb;
	char			*bi;
	int				len;

	nb = (unsigned int)wc;
	if ((ft_check_arg(nb)) == 0)
		return (NULL);
	if (MB_CUR_MAX == 1 && wc < 256)
	{
		if ((tab = ft_memalloc(2)) == 0)
			return (NULL);
		tab[0] = wc;
		return (tab);
	}
	bi = ft_dec_to_bi(nb);
	len = ft_strlen(bi);
	if (!(tab = ft_get_mask(len)))
	{
		ft_strdel(&bi);
		return (NULL);
	}
	return (ft_putwcinstr2(tab, bi, len));
}
