/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:21:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 17:31:34 by vrenaudi         ###   ########.fr       */
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
				if (env->nb_ants <= 0)
				{
					ft_printf("Wrong number of ants.\n");
					return (-1);
				}
				else
					if (!(env->ants = ft_memalloc(env->nb_ants * sizeof(t_ant))))
						return (-1);
			}
		}
		else
		{
			ft_printf("Empty spaces, what are we waiting for ?\n");
			return (-1);
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

static void	delete_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}

static int	tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	analyze_node_edge(t_env *env, char *line)
{
	char **tab;

	tab = NULL;
	if (line[0] == 'L')
	{
		ft_printf("Wrong name for node\n");
		return (-1);
	}
	else if (ft_strchr(line, ' '))
	{
		if (env->delimiter == 1)
			return (-1);
		tab = ft_strsplit(line, ' ');
		if (tablen(tab) != 3)
		{
			ft_printf("too many coordinates\n");
			return (-1);
		}
		if (fill_room(env, tab) == -1)
			return (-1);
	}
	else if (ft_strchr(line, '-'))
	{
		if (env->start_index == -1 || env->end_index == -1)
		{
			ft_printf("Missing end or start\n");
			return (-1);
		}
		if (env->start_index == env->end_index && env->start_index != -1)
		{
			ft_printf("Same end and start fdp\n");
			return (-1);
		}
		if (env->delimiter == 0)
		{
			create_matrice(env);
			env->delimiter = 1;
		}
		tab = ft_strsplit(line, '-');
		if (tablen(tab) != 2)
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
	}
	delete_tab(tab);
	return (0);
}

void	create_rooms(t_node *node, t_room **rooms)
{
	t_node *tmp;
	int i;

	tmp = node;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (!(*rooms = ft_memalloc(sizeof(t_room) * i)))
		return ;
	tmp = node;
	i = 0;
	while (tmp != NULL)
	{
		(*rooms)[i] = tmp->room;
		tmp = tmp->next;
		i++;
	}
	tmp = node;
	while (node->next)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(node);
}		

int		read_data(t_env *env)
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
		else
		{
			if (analyze_node_edge(env, line) == -1)
			{
				ft_strdel(&line);
				return (-1);
			}
		}
		ft_strdel(&line);
	}
	return (0);
}
