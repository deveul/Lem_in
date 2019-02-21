/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:30:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/21 12:11:45 by marvin           ###   ########.fr       */
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

void		add_result(t_res **results, t_path path)
{
	t_res	*tmp;
	t_res	*new;

	tmp = *results;
	if (!(new = ft_memalloc(sizeof(t_res))))
		exit (-1);
	new->path = path;
	new->next = NULL;
	if (*results == NULL)
	{
		*results = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	save_path(t_env *env, t_dij *dij)
{
	t_path 	tmp;
	int 	j;
	int 	i;
	int 	x;

	i = env->end_index;
	x = 0;
	j = 0;
	if (dij->distance[i] == INFINITE || dij->distance[i] == 0)
		return (-1);
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
		if (j != env->end_index || j != env->start_index)
			env->rooms[j].check = 1;
		x--;
	}
	if (check_path_list(env, tmp) == -1)
		return (-1);
	add_result(&env->results, tmp);
	return (0);
}

void		create_path_tab(t_res *res, t_path **paths, int nb_paths)
{
	t_res *tmp;
	int i;

	i = 0;
	tmp = res;
	if (!(*paths = ft_memalloc(sizeof(t_path) * nb_paths)))
		exit (-1);
	while (tmp != NULL)
	{
		(*paths)[i] = tmp->path;
		tmp = tmp->next;
		i++;
	}
	tmp = res;
	while (res->next)
	{
		tmp = res->next;
		free(res);
		res = tmp;
	}
	free(res);
}