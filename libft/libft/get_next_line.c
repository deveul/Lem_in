/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:18:19 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/14 16:55:54 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_streraseuntilc(char *src, char c)
{
	int		i;
	int		a;
	char	*new;

	i = 0;
	a = 0;
	while (src[i] && src[i] != c)
		i++;
	if (!src[i])
	{
		if ((new = ft_memalloc(1)) == 0)
			return (NULL);
	}
	else
	{
		if ((new = ft_memalloc((ft_strlen(src) - i))) == 0)
			return (NULL);
		i++;
		while (src[i])
			new[a++] = src[i++];
	}
	ft_strdel(&src);
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*str = NULL;

	if ((fd < 0 || read(fd, buf, 0) < 0) || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((str = ft_strjoinfree(str, buf)) == 0)
			return (-1);
		if (ft_memchr(buf, '\n', ret))
			break ;
	}
	if ((ret < BUFF_SIZE && (!str || !ft_strlen(str))))
		return (0);
	if (!(*line = ft_strndup(str, ft_strlenuntilc(str, '\n')))
			|| !(str = ft_streraseuntilc(str, '\n')))
		return (-1);
	return (1);
}
