/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/21 12:14:12 by marvin           ###   ########.fr       */
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
	i = 0;
	while (i < env->nb_nodes)
	{
		free(env->matrice[i]);
		i++;
	}
	free(env->matrice);
	i = 0;
	while (i < env->nb_f_c)
		free(env->combi[i++].index_array);
	free(env->combi);
	free(env->final_combi);
	free(env->start_links);
	free(env->end_links);
	free(env->paths);
}

void			add_node(t_node **nodes, t_room room)
{
	t_node *tmp;
	t_node *new;

	tmp = *nodes;
	if (!(new = ft_memalloc(sizeof(t_node))))
		exit (-1);
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
	env->results = NULL;
	env->rooms = NULL;
	env->matrice = NULL;
	env->nb_ants = -1;
	env->nb_nodes = 0;
	env->nb_path = 0;
	env->nb_edges = 0;
	env->start = 0;
	env->start_nb = 0;
	env->end = 0;
	env->end_nb = 0;
	env->start_index = -1;
	env->end_index = -1;
	env->delimiter = 0;
	env->i_e = 0;
	env->i_s = 0;
}

void			get_connexion_start_end(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->start_links = ft_memalloc(sizeof(int) * env->nb_nodes)))
		return ;
	if (!(env->end_links = ft_memalloc(sizeof(int) * env->nb_nodes)))
		return ;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1)
			env->start_links[env->start_nb++] = i;
		if (env->matrice[env->end_index][i] == 1)
			env->end_links[env->end_nb++] = i;
		i++;
	}
}

int				main(void)
{
	t_env	env;
	int		i;

	init_env(&env);
	ft_printf(">>>>>>>>>>>>>>>>>ANALYSE_DATA<<<<<<<<<<<<<<<<<<<<\n");
	i = 0;
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
	get_connexion_start_end(&env);
	ft_printf("\n>>>>>>>>>>>>>>>>>SEARCH_PATH<<<<<<<<<<<<<<<<<<<<\n\n");
	i = 0;
	if (env.start_nb > 1 && env.end_nb > 1)
		while (i < env.start_nb)
			dijkstra(&env, env.nb_nodes, i++);
	else
		dijkstra(&env, env.nb_nodes, i);
	create_path_tab(env.results, &env.paths, env.nb_path);
	ft_printf(">>>>>>>>>>>>>>>>>END_SEARCH<<<<<<<<<<<<<<<<<<<<\n\n");
	print_path(&env);
	if (env.nb_path == 0)
		ft_putendl("No passaran");
	fill_combinations(&env);
	choose_combinations(&env);
	dispatch_ants(&env);
	free_memory(&env);
	return (0);
}
