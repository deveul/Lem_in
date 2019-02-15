/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 16:12:01 by vrenaudi         ###   ########.fr       */
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
	while (i < env->nb_nodes)
	{
		free(env->matrice[i]);
		i++;
	}
	i = 0;
	free(env->matrice);
	//free(env->fifo);
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

void		add_result(t_res **results, t_path path)
{
	t_res	*tmp;
	t_res	*new;

	tmp = *results;
	if (!(new = ft_memalloc(sizeof(t_res))))
		return ;
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

void		create_path_tab(t_res *res, t_path **paths_ok, int nb_paths)
{
	t_res *tmp;
	int i;

	i = 0;
	tmp = res;
	if (!(*paths_ok = ft_memalloc(sizeof(t_path) * nb_paths)))
		return ;
	while (tmp != NULL)
	{
		(*paths_ok)[i] = tmp->path;
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

static void		init_env(t_env *env)
{
	env->nodes = NULL;
	env->results = NULL;
	env->rooms = NULL;
	env->matrice = NULL;
	env->nb_ants = -1;
	env->nb_nodes = 0;
	env->nb_path = 0;
	env->nb_path_ok = 0;
	env->nb_edges = 0;
	env->start = 0;
	env->start_nb = 0;
	env->end = 0;
	env->end_nb = 0;
	env->start_index = -1;
	env->end_index = -1;
	env->delimiter = 0;
	env->nb_dup = 0;
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
	int 	j;

	init_env(&env);
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
	i = 0;
	if (env.start_nb > 1 && env.end_nb > 1)
	{
		while (i <= env.start_nb + env.end_nb)
		{
	//		print_env(&env);
			dijkstra(&env, env.nb_nodes, i++);		
		}
	}
	else
		dijkstra(&env, env.nb_nodes, i);
	create_path_tab(env.results, &env.paths_ok, env.nb_path_ok);
	i = 0;
	while (i < env.nb_path_ok)
	{
		j = 0;
		ft_printf("len = %d\n", env.paths_ok[i].len);
		if (env.paths_ok[i].len > 0)
		{
			while (j <= env.paths_ok[i].len)
			{
				ft_printf("path[%d][%d] = %s\n", i, j, env.rooms[env.paths_ok[i].path[j]].name);
				j++;
			}
		}
		i++;
		ft_putendl("");
	}
	if (env.nb_path_ok == 0)
		ft_putendl("No passaran");
	del_dup_paths(&env);
	fill_combinations(&env);
	free_memory(&env);
	return (0);
}
