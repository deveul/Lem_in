/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_combinations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:10:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/16 02:51:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		print_combi_ini(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_putendl(">>>>>>>>>>>>>>>Initial combinations<<<<<<<<<<<<<<<<");
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
void		print_combi(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_putendl(">>>>>>>>>>>>>>>Final combinations<<<<<<<<<<<<<<<<");
	while (i < env->nb_f_c)
	{
		ft_putendl("--------------");
		j = 0;
		while (j < env->final_combi[i].nb_combi)
		{
			ft_printf("%d-", env->final_combi[i].index_array[j]);
			j++;
		}
		ft_putendl("");
		ft_printf("Nb path in combi : %d\n", env->final_combi[i].nb_combi);
		ft_putendl("--------------");
		i++;
	}
}

void		count_dup(t_env *env)
{
	int		i;
	int		j;
	int		k;
	int		eq;

	i = 0;
	env->nb_c_dup = 0;
	while (i < env->nb_path_ok)
	{
		j = i + 1;
		while (j < env->nb_path_ok)
		{
			if (env->combi[i].nb_combi == env->combi[j].nb_combi)
			{
				k = 0;
				eq = 0;
				while (k < env->combi[i].nb_combi)
				{
					if (env->combi[i].index_array[k] == env->combi[j].index_array[k])
						eq++;
					if (eq == env->combi[j].nb_combi && env->combi[j].dup == 0)
					{
						env->nb_c_dup++;
						env->combi[j].dup = 1;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	env->nb_f_c = env->nb_path_ok - env->nb_c_dup;
}

void		del_dup_combi(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_path_ok)
	{
		ft_sort_int_tab(env->combi[i].index_array, env->combi[i].nb_combi);
		env->combi[i].dup = 0;
		i++;
	}
	count_dup(env);
	if (!(env->final_combi = ft_memalloc(env->nb_f_c * sizeof(t_combinations))))
	{
		ft_printf("env->nb_f_c:%d\n", env->nb_f_c);
		ft_printf("malloc_error\n");
		return ;
	}
	i = 0;
	j = 0;
	while (i < env->nb_path_ok && j < env->nb_f_c)
	{
		if (env->combi[i].dup == 0)
			env->final_combi[j++] = env->combi[i++];
		else
			i++;
	}
}

void		init_combi(t_env *env, int i)
{
	env->combi[i].index_array = ft_memalloc(env->nb_path_ok * sizeof(int));
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
	while (k < env->nb_path_ok)
	{
		if (i != k)
			if (confront_two_paths(env->paths_ok[i], env->paths_ok[k]) == 0)
			{
				l = 1;
				while (l < env->combi[i].nb_combi)
				{
					if (confront_two_paths(env->paths_ok[env->combi[i].index_array[l]], env->paths_ok[k]) == -1)
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
	env->combi = ft_memalloc(env->nb_path_ok * sizeof(t_combinations));
	while (i < env->nb_path_ok)
	{
		check_combi(env, i);
		i++;
	}
//	print_combi_ini(env);
	del_dup_combi(env);
	print_combi(env);
}
