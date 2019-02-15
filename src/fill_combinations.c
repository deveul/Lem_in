/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_combinations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:10:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 16:38:38 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		print_combi(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_no_dup)
	{
		ft_putendl("--------------");
		j = 0;
		while (j < env->combi[i].nb_combi)
		{
			ft_printf("%d-", env->combi[i].index_array[j]);
			j++;
		}
		ft_putendl("");
		ft_printf("Nb path in combi : %d\n", env->combi[i].nb_combi);
		ft_putendl("--------------");
		i++;
	}
}
/*
void		del_dup_combi(t_env *env)
{

}
*/
void		init_combi(t_env *env, int i)
{
	env->combi[i].index_array = ft_memalloc(env->nb_no_dup * sizeof(int));
	env->combi[i].index_array[0] = i;
	env->combi[i].nb_combi = 1;
}

int			search_node_in_path(int node, t_path p)
{
	int		i;

	i = 1;
	while (i < p.len)
	{
		if (node == p.path[i])
			return (-1);
		i++;
	}
	return (0);
}

int			confront_two_paths(t_path p1, t_path p2)
{
	int		j;

	j = 1;
	while (j < p1.len)
	{
		if (search_node_in_path(p1.path[j], p2) == -1)
			return (-1);
		j++;
	}
	return (0);
}

void		check_combi(t_env *env, int i)
{
	int		k;
	int		l;
	int		add;

	k = 0;
	add = 1;
	init_combi(env, i);
	while (k < env->nb_no_dup)
	{
		if (i != k)
			if (confront_two_paths(env->paths_no_dup[i], env->paths_no_dup[k]) == 0)
			{
				l = 1;
				while (l < env->combi[i].nb_combi)
				{
					if (confront_two_paths(env->paths_no_dup[env->combi[i].index_array[l]], env->paths_no_dup[k]) == -1)
						break ;
					l++;
				}
				if (l == env->combi[i].nb_combi)
				{
					env->combi[i].index_array[add++] = k;
					env->combi[i].nb_combi++;
				}
			}
		k++;
	}
}

void		fill_combinations(t_env *env)
{
	int		i;

	i = 0;
	env->combi = ft_memalloc(env->nb_no_dup * sizeof(t_combinations));
	while (i < env->nb_no_dup)
	{
		check_combi(env, i);
		i++;
	}
//	del_dup_combi(env);
	print_combi(env);
}
