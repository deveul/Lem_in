/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:21:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/23 13:27:04 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int	get_ants_nb(t_env *env, char *line)
{
	while (env->nb_ants == -1)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (line[0] != '#')
			{
				env->nb_ants = ft_atoi(line);
				if (env->nb_ants <= 0 && ft_printf("Wrong number of ants.\n"))
					exit (-1);
				env->data[env->nb_line++] = line;
			}
			else
				ft_strdel(&line);
		}
		else
		{
			ft_printf("Empty spaces, what are we waiting for ?\n");
			return (-1);
		}
	}
	return (0);
}

int	handle_start_end_com(t_env *env, char *line)
{
	if (ft_strequ(line, "##start"))
	{
		if (env->start == 2)
		{
			ft_printf("Too many ##start\n");
			return (-1);
		}
		env->start = 1;
	}
	else if (ft_strequ(line, "##end"))
	{
		if (env->end == 2)
		{
			ft_printf("Too many ##end\n");
			return (-1);
		}
		env->end = 1;
	}
	return (0);
}

int	analyze_node(t_env *env, char *line)
{
	char	**tab;

	if (env->matrice)
		return (-1);
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
	{
		ft_printf("too many coordinates\n");
		return (-1);
	}
	if (fill_room(env, tab) == -1)
		return (-1);
	ft_delete_tab(tab);
	return (0);
}

int	analyze_edge(t_env *env, char *line)
{
	char	**tab;

	if ((env->start_index == -1 || env->end_index == -1)
			|| (env->start_index == env->end_index && env->start_index != -1))
	{
		ft_printf("Problem with end or start\n");
		return (-1);
	}
	if (!env->matrice)
		create_matrice(env);
	tab = ft_strsplit(line, '-');
	if (ft_tablen(tab) != 2)
	{
		ft_printf("edge should be : room1-romm2\n");
		return (-1);
	}
	if (fill_matrice(env, tab) == -1)
	{
		ft_printf("Ground control to Major Tom\n");
		return (-1);
	}
	env->nb_edges++;
	ft_delete_tab(tab);
	return (0);
}

int	analyze_node_edge(t_env *env, char *line)
{
	if (line[0] == 'L')
	{
		ft_printf("Wrong name for node\n");
		return (-1);
	}
	else if (ft_strchr(line, ' '))
	{
		if (analyze_node(env, line) == -1)
			return (-1);
	}
	else if (ft_strchr(line, '-'))
	{
		if (analyze_edge(env, line) == -1)
			return (-1);
	}
	return (0);
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

int		read_data(t_env *env)
{
	char	*line;
	int		realloc;

	line = NULL;
	realloc = 1;
	env->data = ft_memalloc(sizeof(char*) * NB_LINE + 1);
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
		if (line && line[0] == '#' && !ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
			ft_strdel(&line);
		else if (env->nb_line < (NB_LINE * realloc) - 1)
			env->data[env->nb_line++] = line;
		else
		{
			env->data = increment_size(env->data, line, ++realloc);
			env->nb_line++;
		}
	}
	if (env->nb_edges == 0)
		return (-1);
	get_connexion_start_end(env);
	return (0);
}
