/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:30:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/01 12:00:49 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	check_visited_rooms(t_path tmp, t_env *env)
{
	int i;

	i = 0;
	while (i < tmp.len)
	{
		env->matrice[tmp.path[i]][tmp.path[i + 1]] = INFINITE;
		env->matrice[tmp.path[i + 1]][tmp.path[i]] = INFINITE;
		env->flow[tmp.path[i]][tmp.path[i + 1]] = INFINITE;
		env->rooms[tmp.path[i]].check = 1;
		i++;
	}
}

void			add_result(t_res **results, t_path path)
{
	t_res	*tmp;
	t_res	*new;

	tmp = *results;
	if (!(new = ft_memalloc(sizeof(t_res))))
		exit(-1);
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

void			save_path(t_env *env, t_dij *dij)
{
	t_path	tmp;
	int		i;
	int		x;

	i = env->end_index;
	x = 0;
	if (dij->distance[i] == INFINITE || dij->distance[i] == 0)
		return ;
	if (!(tmp.path = ft_memalloc(sizeof(int) * (dij->distance[i] + 1))))
		exit(-1);
	tmp.len = dij->distance[i];
	x = tmp.len;
	tmp.path[x] = i;
	x--;
	while (i != env->start_index)
	{
		i = dij->pred[i];
		tmp.path[x] = i;
		x--;
	}
	check_visited_rooms(tmp, env);
	add_result(&env->results, tmp);
	env->nb_path++;
}

void			create_path_tab(t_res *res, t_path **paths, int nb_paths)
{
	t_res	*tmp;
	int		i;

	i = 0;
	tmp = res;
	if (!(*paths = ft_memalloc(sizeof(t_path) * nb_paths)))
		exit(-1);
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
