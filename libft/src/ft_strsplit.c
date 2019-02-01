/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:24:47 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:30 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		nb_w(char const *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static int		len_w(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i + j] != c && s[i + j])
		j++;
	return (j + 1);
}

static char		*mem_word(char const *s, char c, int i)
{
	char	*word;
	int		j;

	j = 0;
	if ((word = ft_memalloc(sizeof(char) * len_w(s, c, i))) == NULL)
		return (NULL);
	while (s[i + j] != c && s[i + j])
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if ((tab = malloc(sizeof(char*) * (nb_w(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (j < nb_w(s, c) && s[i] != c)
		{
			tab[j] = mem_word(s, c, i);
			j++;
		}
		i = i + len_w(s, c, i);
	}
	tab[j] = NULL;
	return (tab);
}
