/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:44:36 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/23 15:02:12 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		*dup_table(int *src, int len)
{
	int		*dst;

	if (!(dst = ft_memalloc(sizeof(int) * len)))
		return (NULL);
	ft_memcpy(dst, src, len * sizeof(int));
	return (dst);
}

int		*expand_table(int *src, int len, int to_add)
{
	int		*dst;

	if (!(dst = ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	if (src)
	{
		ft_memcpy(dst, src, len * sizeof(int));
		free(src);
	}
	dst[len] = to_add;
	return (dst);
}
/*
t_path	*add_path(t_path *tocpy, int nb_path, int ptocpy, int len)
{
	t_path	*paths;
	int		i;

	if (!(paths = ft_memalloc(sizeof(t_path) * (nb_path + 1))))
		return (NULL);
	i = 0;
	while (i < nb_path)
	{
		paths[i].path = dup_table(tocpy[i].path, len);
		paths[i].len = tocpy[i].len;
		i++;
	}
	paths[nb_path].path = dup_table(tocpy[ptocpy].path, len);
	paths[nb_path].len = tocpy[ptocpy].len;
	i = 0;
	while (i < nb_path)
	{
		free(tocpy[i].path);
		i++;
	}
	free(tocpy);
	return (paths);
}
*/

void	add_path(t_path *tocpy, int nb_path, int ptocpy, int len)
{
	tocpy[nb_path].path = dup_table(tocpy[ptocpy].path, len);
	tocpy[nb_path].len = tocpy[ptocpy].len;
}

char	**increment_size(char **data, char *line, int realloc)
{
	char	**tmp;
	int		i;
	int		size;

	tmp = NULL;
	size = NB_LINE * realloc + 1;
	if (!(tmp = ft_memalloc(sizeof(char *) * size)))
		exit(-1);
	i = 0;
	while (data[i])
	{
		tmp[i] = data[i];
		i++;
	}
	tmp[i] = line;
	free(data);
	return (tmp);
}
