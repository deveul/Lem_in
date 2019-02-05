/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/05 18:18:00 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		*dup_table(int *src, int len)
{
	int		*dst;

	dst = ft_memalloc(sizeof(int) * len);
	ft_memcpy(dst, src, len * sizeof(int));
	free(src);
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

t_path	*add_path(t_path *tocpy, int nb_path)
{
	t_path	*paths;
	int		i;

	paths = ft_memalloc(sizeof(t_path) * (nb_path + 1));
	i = 0;
	while (i < nb_path)
	{
		paths[i].path = dup_table(tocpy[i].path, tocpy[i].len);
		paths[i].len = tocpy[i].len;
		i++;
	}
	paths[nb_path].path = dup_table(tocpy[nb_path - 1].path, tocpy[nb_path -1].len);
	paths[nb_path].len = tocpy[nb_path -1].len;
	return (paths);
}

void	init_paths(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_fifo)
	{
		env->paths[i].path = expand_table(NULL, 0, env->start_index);
		env->paths[i].len = 1;
		i++;
	}
}

void	algo(t_env *env)
{
	int 	i;

	env->paths = ft_memalloc(sizeof(t_path) * env->nodes[env->start_index].nb_edges);
	env->nb_fifo = env->nodes[env->start_index].nb_edges;
	init_paths(env);
	i = 0;
	while (i < env->nb_fifo)
	{
		ft_printf("original path : %d\n", env->paths[i].path[0]);
		i++;
	}
	env->fifo = ft_memalloc(sizeof(int) * env->nb_fifo);
	i = 0;
	while (i < env->nb_fifo)
	{
		env->fifo[i] = env->nodes[env->start_index].connexion[i];
		env->nodes[env->nodes[env->start_index].connexion[i]].check = 1;
		i++;
	}
	i = 0;
	while (env->nb_fifo != env->nb_nodes)
	{

	}
}
