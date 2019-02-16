/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:30:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/16 15:25:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	int	compare_paths(t_path p1, t_path p2)
{
	int		i;

	i = 1;
	if (p1.len == 1)
		return (1);
	while (i < p1.len)
	{
		if (p1.path[i] == p2.path[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_path_list(t_env *env, t_path tmp)
{
	t_res *tmp_res;

	if (env->nb_path > 0)
	{
		tmp_res = env->results;
		while (tmp_res != NULL)
		{
			if (tmp.len == tmp_res->path.len 
				&& compare_paths(tmp, tmp_res->path) == 1)
					return (-1);	
			tmp_res = tmp_res->next;
		}
	}
	return (0);
}

int	save_path(t_env *env, t_dij *dij)
{
	t_path 	tmp;
	int 	j;
	int 	i;
	int 	x;

	i = 0;
	x = 0;
	j = 0;
	while (i < env->nb_nodes)
	{
		if (i == env->end_index)
		{
			if (dij->distance[i] == INFINITE || dij->distance[i] == 0)
				break ;
			if (!(tmp.path = ft_memalloc(sizeof(int) * (dij->distance[i] + 1))))
				exit (-1);
			tmp.len = dij->distance[i];
			x = tmp.len;
			tmp.path[x] = i;
			x--;
			j = i;
			while (j != env->start_index)
			{
				j = dij->pred[j];
				tmp.path[x] = j;
				x--;
			}
			if (check_path_list(env, tmp) == -1)
				break ;
			add_result(&env->results, tmp);
			//free (tmp.path);
			return (0);
		}
		i++;
	}
	//free(tmp.path);
	return (-1);
}