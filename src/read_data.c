/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:21:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/04 14:22:41 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_ants_nb(t_env *env, char *line)
{
	while (env->nb_ants == -1)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (line[0] == '#' && !ft_strequ(line, "##start")
					&& !ft_strequ(line, "##end"))
				ft_strdel(&line);
			else
			{
				env->nb_ants = ft_atoi(line);
				ft_strdel(&line);
			}
			if (env->nb_ants <= 0)
			{
				ft_printf("Wrong number of ants.\n");
				return (-1);
			}
			else
				env->ants = ft_memalloc(env->nb_ants * sizeof(t_ant));
		}
	}
	return (0);
}

static int	handle_start_end_com(t_env *env, char *line)
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

static int	analyze_node_edge(t_env *env, char *line)
{
	char **tab;

	if (line[0] == 'L')
	{
		ft_printf("Wrong name for node\n");
		return (-1);
	}
	if (ft_strchr(line, ' '))
	{
		if (env->delimiter == 1)
			return (-1);
		tab = ft_strsplit(line, ' ');
		if (fill_node(env, tab) == -1)
			return (-1);
	}
	if (ft_strchr(line, '-'))
	{
		env->delimiter = 1;
		tab = ft_strsplit(line, '-');
		if (fill_edge(env, tab) == -1)
			return (-1);
	}
	return (0);
}

int		read_data(t_env *env)
{
	char	*line;

	line = NULL;
	if (get_ants_nb(env, line) == -1)
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (handle_start_end_com(env, line) == -1)
			{
				ft_strdel(&line);
				return (-1);
			}
			ft_strdel(&line);
		}
		else
		{
			if (analyze_node_edge(env, line) == -1)
			{
				ft_strdel(&line);
				return (-1);
			}
			ft_strdel(&line);
		}
	}
	return (0);
}
