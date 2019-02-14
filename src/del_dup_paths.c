/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dup_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:30:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/14 17:08:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_no_dup(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env->nb_no_dup)
	{
		j = 0;
		ft_printf("len = %d\n", env->paths_no_dup[i].len);
		while (j <= env->paths_no_dup[i].len)
		{
			ft_printf("path[%d][%d] = %s\n", i, j, env->rooms[env->paths_no_dup[i].path[j]].name);
			j++;
		}
		i++;
		ft_putendl("");
	}
	
}

void	del_dup(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	env->paths_no_dup = ft_memalloc(sizeof(t_path) * env->nb_no_dup);
	while (i < env->nb_path_ok)
	{
		if (env->paths_ok[i].dup == 0)
		{
			env->paths_no_dup[j] = env->paths_ok[i];
			j++;
		}
		i++;
	}
}

int		compare_paths(t_path p1, t_path p2)
{
	int		i;

	i = 1;
	while (i < p1.len)
	{
		if (p1.path[i] == p2.path[i])
			return (1);
		i++;
	}
	return (0);
}

int		del_dup_paths(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->nb_path_ok)
		env->paths_ok[i].dup = 0;
	i = 1;
	while (i < env->nb_path_ok)
	{
		j = 0;
		while (j < env->nb_path_ok)
		{
			if (i != j && env->paths_ok[i].len == env->paths_ok[j].len
					&& env->paths_ok[j].dup != 1 && env->paths_ok[i].dup != 1)
				if (compare_paths(env->paths_ok[i], env->paths_ok[j]) == 1)
				{
					env->nb_dup++;
					env->paths_ok[j].dup = 1;
				}
			j++;
		}
		i++;
	}
	env->nb_no_dup = env->nb_path_ok - env->nb_dup;
	ft_printf("nb_dup:%d\n", env->nb_dup);
	del_dup(env);
	print_no_dup(env);
	return (0);
}
