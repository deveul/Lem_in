/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:44:36 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 19:14:07 by vrenaudi         ###   ########.fr       */
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

t_path	*add_path(t_path *tocpy, int nb_path, int ptocpy)
{
	t_path	*paths;
	int		i;

	if (!(paths = ft_memalloc(sizeof(t_path) * (nb_path + 1))))
		return (NULL);
	i = 0;
	while (i < nb_path)
	{
		paths[i].path = dup_table(tocpy[i].path, tocpy[i].len);
		paths[i].len = tocpy[i].len;
		paths[i].end_found = tocpy[i].end_found;
		i++;
	}
	paths[nb_path].path = dup_table(tocpy[ptocpy].path, tocpy[ptocpy].len);
	paths[nb_path].len = tocpy[ptocpy].len;
	paths[nb_path].end_found = tocpy[ptocpy].end_found;
	i = 0;
	while (i < nb_path)
	{
		free(tocpy[i].path);
		i++;
	}
	free(tocpy);
	return (paths);
}
