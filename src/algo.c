/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/07 17:28:39 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_path(t_env *env)
{
	int 	i;
	int		j;

	i = 0;
	while (i < env->nb_path)
	{
		ft_printf("path [%d]: ", i);
		j = 0;
		while (j < env->paths[i].len)
		{
			ft_printf("%d\t", env->paths[i].path[j]);
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
	env->nodes[env->start_index].check = 1;
	while (i < env->nb_path)
	{
		env->paths[i].path = expand_table(NULL, 0, env->start_index);
		env->paths[i].len = 1;
		i++;
	}
}

void	fill_initial_fifo(t_env *env)
{
	int		i;

	i = 0;
	ft_printf("nb_path:%d\n", env->nb_path);
	while (i < env->nb_path)
	{
		env->fifo[i].index = env->nodes[env->start_index].connexion[i];
		env->fifo[i].path_index = i;
		env->nodes[env->nodes[env->start_index].connexion[i]].check = 1;
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
	env->paths[tmp.path_index].path = expand_table(env->paths[tmp.path_index].path, env->paths[tmp.path_index].len, tmp.index);
	env->paths[tmp.path_index].len++;
	env->nb_fifo--;
}

void	algo(t_env *env)
{
	int 	i;
	t_fifo	tmp;
	int		nb_path_needed;

	env->nb_path = env->nodes[env->start_index].nb_edges;
	env->paths = ft_memalloc(sizeof(t_path) * env->nb_path);
	env->nb_fifo = env->nb_path;
	init_paths(env);
	env->fifo = ft_memalloc(sizeof(t_fifo) * env->nb_nodes);
	fill_initial_fifo(env);
	ft_printf("nb_fifo:%d\n", env->nb_fifo);
	while (env->nb_fifo != 0)
	{
		tmp = env->fifo[0];
		remove_elem_fifo(env);
		i = 0;
		nb_path_needed = 0;
		while (i < env->nb_nodes)
		{
			if (env->matrice[tmp.index][i] == 1 && env->nodes[i].check == 0)
			{
				env->fifo[env->nb_fifo].index = i;
				if (i != env->end_index)
					env->nodes[i].check = 1;
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
