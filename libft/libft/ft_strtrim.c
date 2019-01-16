/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:35:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 15:16:57 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		*ft_find_lim(char const *s, int *cpt)
{
	int		i;

	i = 0;
	ft_memset(cpt, 0, 8);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		cpt[0]++;
		i++;
	}
	if (!s[i])
		return (cpt);
	while (s[i])
		i++;
	i--;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		cpt[1]++;
		i--;
	}
	return (cpt);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	int		cpt[2];
	int		size;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	ft_find_lim(s, cpt);
	if (cpt[0] == 0 && cpt[1] == 0)
		return (ft_strdup(s));
	size = ft_strlen(s) - cpt[0] - cpt[1];
	if ((trim = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	while (i < size)
	{
		trim[i] = s[i + cpt[0]];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
