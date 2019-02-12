/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/11 18:15:43 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		free_memory(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_nodes)
	{
		free(env->rooms[i].name);
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
		free(env->matrice[i]);
		i++;
	}
	free(env->matrice);
	free(env->fifo);
}

void			add_node(t_node **nodes, t_room room)
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

static int		read_data(t_env *env)
{
	char	*line;

	line = NULL;
	if (get_ants_nb(env, line) == -1)
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (line && line[0] == '#')
		{
			if (handle_start_end_com(env, line) == -1)
			{
				ft_strdel(&line);
				return (-1);
			}
		}
		else if (analyze_node_edge(env, line) == -1)
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
	}
	return (0);
}

static void		init_env(t_env *env)
{
	env->nodes = NULL;
	env->rooms = NULL;
	env->matrice = NULL;
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

int				main(void)
{
	t_env	env;
	int		nb_path;
	int		i;

	init_env(&env);
	i = 0;
	nb_path = 0;
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
	while (env.matrice[env.end_index][i])
	{
		if (env.matrice[env.end_index][i] == 1)
			nb_path++;
		i++;
	}
	while (nb_path-- > 0)
	{
		//print_env(&env);
		if (dijkstra(&env, env.nb_nodes, env.start_index, env.end_index) == -1)
			break ;
	}
	//return (0);
	if (algo(&env) == -1)
		return (-1);
	if (env.nb_path_ok == 0)
		ft_putendl("No passaran");
	free_memory(&env);
	return (0);
}
