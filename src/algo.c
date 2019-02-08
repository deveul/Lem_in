/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/08 14:50:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_path(t_env *env)
{
	int 	i;
	int		j;

	i = 0;
	ft_putendl(">>>>>>>>>>>Paths<<<<<<<<<<<<<<<");
	while (i < env->nb_path)
	{
		ft_printf("path [%d]: ", i);
		j = 0;
		while (j < env->paths[i].len)
		{
			ft_printf("%-7d", env->paths[i].path[j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
}

void	init_paths(t_env *env)
{
	int		i;

	i = 0;
	env->rooms[env->start_index].check = 1;
	while (i < env->nb_path)
	{
		env->paths[i].path = expand_table(NULL, 0, env->start_index);
		env->paths[i].len = 1;
		env->paths[i].end_found = 0;
		i++;
	}
}

void	fill_initial_fifo(t_env *env)
{
	int		i;
	int		path_index;

	i = 0;
	path_index = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1)
		{
			env->fifo[path_index].index = i;
			env->fifo[path_index].path_index = path_index;
			env->rooms[i].check = 1;
			path_index++;
		}
		i++;
	}
}

void	remove_elem_fifo(t_env *env)
{
	int		i;
	int		j;
	t_fifo	tmp;

	i = 1;
	j = 0;
	tmp = env->fifo[0];
	while (i < env->nb_fifo)
	{
		env->fifo[j].index = env->fifo[i].index;
		env->fifo[j++].path_index = env->fifo[i++].path_index;
	}
	if (env->paths[tmp.path_index].end_found == 0)
	{
		env->paths[tmp.path_index].path = expand_table(env->paths[tmp.path_index].path, env->paths[tmp.path_index].len, tmp.index);
		env->paths[tmp.path_index].len++;
		if (tmp.index == env->end_index)
			env->paths[tmp.path_index].end_found = 1;
	}
	env->nb_fifo--;
}

void	algo(t_env *env)
{
	int 	i;
	t_fifo	tmp;
	int		nb_path_needed;

	i = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1)
			env->nb_path++;
		i++;
	}
	env->paths = ft_memalloc(sizeof(t_path) * env->nb_path);
	env->nb_fifo = env->nb_path;
	init_paths(env);
	env->fifo = ft_memalloc(sizeof(t_fifo) * env->nb_nodes);
	fill_initial_fifo(env);
	while (env->nb_fifo != 0)
	{
		tmp = env->fifo[0];
		remove_elem_fifo(env);
		i = 0;
		nb_path_needed = 0;
		while (i < env->nb_nodes)
		{
			if (env->matrice[tmp.index][i] == 1 && env->rooms[i].check == 0)
			{
				env->fifo[env->nb_fifo].index = i;
				if (i != env->end_index)
					env->rooms[i].check = 1;
				if (nb_path_needed == 0)
				{
					env->fifo[env->nb_fifo].path_index = tmp.path_index;
					nb_path_needed++;
				}
				else
				{
					env->paths = add_path(env->paths, env->nb_path, tmp.path_index);
					env->fifo[env->nb_fifo].path_index = env->nb_path;
					env->nb_path++;
				}
				env->nb_fifo++;
			}
			i++;
		}
	}
	print_path(env);
}
