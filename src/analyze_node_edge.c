/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_node_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:49:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/05 11:13:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		analyze_node(t_env *env, char *line)
{
	char	**tab;

	if (env->matrice)
		return (-1);
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
	{
		ft_printf("too many coordinates\n");
		ft_delete_tab(tab);
		return (-1);
	}
	if (fill_room(env, tab) == -1)
	{
		ft_delete_tab(tab);
		return (-1);
	}
	ft_delete_tab(tab);
	return (0);
}

static int		analyze_edge(t_env *env, char *line)
{
	char	**tab;
	int		error;

	error = 0;
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
		error = -1;
	}
	if (fill_matrice(env, tab) == -1)
	{
		ft_printf("Ground control to Major Tom\n");
		error = -1;
	}
	if (error == 0)
		env->nb_edges++;
	ft_delete_tab(tab);
	return (error);
}

int				analyze_node_edge(t_env *env, char *line)
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
