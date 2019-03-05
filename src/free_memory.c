/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:07:08 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/05 23:14:16 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	free_rooms(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_nodes)
	{
		free(env->rooms[i].name);
		i++;
	}
	free(env->rooms);
}

static	void	free_matrice(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_nodes)
	{
		free(env->matrice[i]);
		free(env->flow[i]);
		free(env->best_flow[i]);
		i++;
	}
	free(env->matrice);
	free(env->flow);
	free(env->best_flow);
}

static	void	free_paths(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_path)
	{
		free(env->paths[i].path);
		i++;
	}
	free(env->paths);
}

void			free_memory(t_env *env)
{
	int i;

	free_rooms(env);
	free_matrice(env);
	free_paths(env);
	i = 0;
	while (i < env->nb_path)
		free(env->combi[i++].index_array);
	free(env->final_combi[env->c_c].ants_by_index);
	free(env->combi);
	i = 0;
	while (env->data[i])
		free(env->data[i++]);
	free(env->data);
	free(env->final_combi);
	free(env->start_links);
	free(env->end_links);
}
