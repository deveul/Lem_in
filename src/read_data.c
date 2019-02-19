/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:21:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/19 11:35:21 by vrenaudi         ###   ########.fr       */
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
				ft_strdel(&line);
				if (env->nb_ants <= 0 && ft_printf("Wrong number of ants.\n"))
					exit (-1);
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

	if (env->delimiter == 1)
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
