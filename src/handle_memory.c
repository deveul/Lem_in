/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:44:36 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 16:25:09 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		*dup_table(int *src, int len)
{
	int		*dst;

	dst = ft_memalloc(sizeof(int) * len);
	ft_memcpy(dst, src, len * sizeof(int));
	return (dst);
}


int		*expand_table(int *src, int len, int to_add)
{
	int		*dst;

	dst = ft_memalloc(sizeof(int) * (len + 1));
	if (src)
	{
		ft_memcpy(dst, src, len * sizeof(int));
		free(src);
	}
	dst[len] = to_add;
	return (dst);
}

t_path	*add_path(t_path *tocpy, int nb_path, int pathtocpy)
{
	t_path	*paths;
	int		i;

	paths = ft_memalloc(sizeof(t_path) * (nb_path + 1));
	i = 0;
	while (i < nb_path)
	{
		paths[i].path = dup_table(tocpy[i].path, tocpy[i].len);
		paths[i].len = tocpy[i].len;
		paths[i].end_found = tocpy[i].end_found;
		i++;
	}
	paths[nb_path].path = dup_table(tocpy[pathtocpy].path, tocpy[pathtocpy].len);
	paths[nb_path].len = tocpy[pathtocpy].len;
	paths[nb_path].end_found = tocpy[pathtocpy].end_found;
	i = 0;
	while (i < nb_path)
	{
		free(tocpy[i].path);
		i++;
	}
	free(tocpy);
	return (paths);
}
