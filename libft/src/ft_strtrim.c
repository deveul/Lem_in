/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:15:43 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:31 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_initial_spaces(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	ft_last_spaces(char const *s)
{
	int i;

	i = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i--;
	i = ft_strlen(s) - i - 1;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char		*s_trim;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		len;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_initial_spaces(s);
	k = ft_last_spaces(s);
	if (j == 0 && k == 0)
		return (ft_strdup((char *)s));
	len = (j != ft_strlen(s) && k != ft_strlen(s)) ? (ft_strlen(s) - j - k) : 0;
	if ((s_trim = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (s[i] && (i < len))
	{
		s_trim[i] = s[j];
		i++;
		j++;
	}
	s_trim[i] = '\0';
	return (s_trim);
}
