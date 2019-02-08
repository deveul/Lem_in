/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 17:19:07 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	free_memory(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_nodes)
	{
		free (env->rooms[i].connexion);
		free (env->rooms[i].name);
		i++;
	}
	free(env->rooms);
	free(env->ants);
	i = 0;
	while (i < env->nb_path)
	{
		free(env->paths[i].path);
		i++;
	}
	free(env->paths);
	i = 0;
	while (i < env->nb_nodes)
	{
		free (env->matrice[i]);
		i++;
	}
	free (env->matrice);
	free (env->fifo);
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
	env->nb_path_ok = 0;
	env->nb_edges = 0;
	env->start = 0;
	env->end = 0;
	env->start_index = -1;
	env->end_index = -1;
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
	if (env.nb_edges == 0)
	{
		ft_putendl("no connexion");
		return (-1);
	}
	print_env(&env);
	algo(&env);
	if (env.nb_path_ok == 0)
		ft_putendl("No passaran");
	free_memory(&env);
	return (0);
}
