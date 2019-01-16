/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:55:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/25 14:41:09 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_get_mask(int len)
{
	char			*tab;

	tab = NULL;
	if (len < 8)
		if (!(tab = ft_strdup("0xxxxxxx")))
			return (NULL);
	if (len >= 8 && len < 12)
		if (!(tab = ft_strdup("110xxxxx10xxxxxx")))
			return (NULL);
	if (len >= 12 && len < 17)
		if (!(tab = ft_strdup("1110xxxx10xxxxxx10xxxxxx")))
			return (NULL);
	if (len >= 17 && len < 22)
		if (!(tab = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx")))
			return (NULL);
	return (tab);
}

static void		ft_writewchar(char *tab)
{
	int		len;
	int		len2;
	char	*octet[4];
	int		part[4];

	len = 0;
	len2 = 0;
	ft_memset(part, 0, 32);
	while (tab[len])
	{
		if ((octet[len2] = ft_strndup(&tab[len], 8)) == 0)
			return ;
		len += 8;
		len2++;
	}
	len = 0;
	while (len2 > 0)
	{
		part[len] = ft_bi_to_dec(octet[len]);
		len2--;
		len++;
	}
	while (len-- > 0)
		write(1, &part[len2++], 1);
}

void			ft_putwchar(wchar_t wc)
{
	char			*tab;
	unsigned int	nb;
	char			*bi;
	int				len;
	int				len2;

	nb = (unsigned int)wc;
	bi = ft_dec_to_bi(nb);
	len = ft_strlen(bi);
	if (!(tab = ft_get_mask(len)))
		return ;
	len2 = ft_strlen(tab);
	len--;
	while (bi[len] && --len2 > 0)
		if (tab[len2] == 'x')
		{
			tab[len2] = bi[len];
			len--;
		}
	ft_strrpcall(tab, 'x', '0');
	ft_writewchar(tab);
}
