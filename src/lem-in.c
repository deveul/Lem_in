/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 12:06:11 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	free_memory(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env->nb_nodes)
	{
		j = 0;
		while (j < env->rooms[i].nb_edges)
			ft_strdel(&env->rooms[i].edges[j++]);
		free (env->rooms[i].edges);
		free (env->rooms[i].connexion);
		free (env->rooms[i].name);
		i++;
	}
	free(env->rooms);
	free(env->ants);
}

void	add_node(t_node **nodes, t_room room)
{
	t_node *tmp;
	t_node *new;
	
	tmp = *nodes;
	if (!(new = ft_memalloc(sizeof(t_node))))
		return ;
	new->room = room;
	new->next = NULL;
	if (*nodes == NULL)
	{
		*nodes = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static void init_env(t_env *env)
{
	env->nodes = NULL;
	env->rooms = NULL;
	env->nb_ants = -1;
	env->nb_nodes = 0;
	env->nb_path = 0;
	env->start = 0;
	env->end = 0;
	env->delimiter = 0;
}

int		main(void)
{
	t_env	env;

	init_env(&env);
	if (read_data(&env) == -1 || env.start == 0 || env.end == 0)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	fill_matrice(&env);
	print_env(&env);
	algo(&env);
	free_memory(&env);
	return (0);
}
