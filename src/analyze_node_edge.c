/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_node_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:49:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 17:46:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		create_matrice(t_env *env)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!(env->matrice = ft_memalloc(sizeof(char *) * env->nb_nodes)))
		exit(-1);
	while (i < env->nb_nodes)
	{
		if (!(env->matrice[i] = ft_memalloc(sizeof(char) * env->nb_nodes)))
			exit(-1);
		j = 0;
		while (j < env->nb_nodes)
		{
			env->matrice[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

static int		analyze_node(t_env *env, char *line)
{
	char	**tab;

	if (env->matrice)
		return (-1);
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
	{
		ft_putendl(ERROR_TOO_MANY_SPACES_FOR_NODES);
		ft_delete_tab(tab);
		exit(-1);
	}
	if (ft_strchr(tab[0], '-') || tab[0][0] == 'L')
	{
		ft_putendl(ERROR_IN_NAME_OF_NODE);
		ft_delete_tab(tab);
		exit(-1);
	}
	if (fill_room(env, tab) == -1)
	{
		ft_delete_tab(tab);
		exit(-1);
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
		ft_putendl(ERROR_WITH_START_OR_END);
		exit(-1);
	}
	if (!env->matrice)
		create_matrice(env);
	tab = ft_strsplit(line, '-');
	if (ft_tablen(tab) != 2)
		error = -1;
	if (fill_matrice(env, tab) == -1)
		error = -1;
	if (error == 0)
		env->nb_edges++;
	ft_delete_tab(tab);
	return (error);
}

int				analyze_node_edge(t_env *env, char *line)
{
	if (ft_strchr(line, ' '))
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
