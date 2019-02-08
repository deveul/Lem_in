/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 12:24:01 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 14:10:03 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s, char c)
{
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			cpt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cpt);
}

static int		ft_l(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char		*ft_splcpy(char *dest, char const *src, char c)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wordct;
	int		start;
	int		i[2];

	if (!s)
		return (NULL);
	ft_memset(i, 0, 8);
	wordct = ft_wordcount(s, c);
	if ((tab = malloc(sizeof(char*) * (wordct + 1))) == 0)
		return (NULL);
	while (i[1] < wordct)
	{
		while (s[i[0]] && s[i[0]] == c)
			i[0]++;
		start = i[0];
		if (!(tab[i[1]] = ft_memalloc((ft_l((s + start), c) + 1))))
			return (NULL);
		while (s[i[0]] && s[i[0]] != c)
			i[0]++;
		ft_splcpy(tab[i[1]], (s + start), c);
		i[1]++;
	}
	tab[wordct] = NULL;
	return (tab);
}
