/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:13:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/04 13:41:04 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	check_unicity(t_env *env, char *name)
{
	int		i;

	i = 0;
	while (i < env->nb_nodes)
	{
		if (ft_strequ(name, env->nodes[i].name))
		{
			ft_printf("Duplicate room\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static	void	check_start_end(t_env *env)
{
	if (env->start == 1)
	{
		env->nodes[env->nb_nodes].start = 1;
		env->start = 2;
	}
	if (env->end == 1)
	{
		env->nodes[env->nb_nodes].end = 1;
		env->end = 2;
	}
}

int			fill_node(t_env *env, char **tab)
{
	if (check_unicity(env, tab[0]) == -1)
		return (-1);
	env->nodes[env->nb_nodes].name = ft_strdup(tab[0]);
	if (ft_isnumber(tab[1]) == -1 || ft_isnumber(tab[2]) == -1)
	{
		ft_printf("Wrong coordinates\n");
		return (-1);
	}	
	check_start_end(env);
	env->nodes[env->nb_nodes].x = ft_atoi(tab[1]);
	env->nodes[env->nb_nodes].y = ft_atoi(tab[2]);
	env->nodes[env->nb_nodes++].edges = ft_memalloc(100 * sizeof(char *));
	return (0);
}

static	int	check_edge(t_env *env, char *new_edge, int index)
{
	int i;

	i = 0;
	while (i < env->nodes[index].nb_edges)
	{
		if (ft_strequ(env->nodes[index].edges[i], new_edge))
			return (-1);
		i++;
	}
	return (0);
}	

int			fill_edge(t_env *env, char **tab)
{
	int		i;
	int		j;
	int		trigger;

	i = 0;
	trigger = 0;
	while (i < env->nb_nodes)
	{
		if (ft_strequ(tab[0], env->nodes[i].name)
				&& check_edge(env, tab[1], i) == 0)
		{
			j = 0;
			while (j < env->nb_nodes)
			{
				if (ft_strequ(tab[1], env->nodes[j].name)
						&& check_edge(env, tab[0], j) == 0)
				{
					env->nodes[i].edges[env->nodes[i].nb_edges++] = ft_strdup(tab[1]);
					env->nodes[j].edges[env->nodes[j].nb_edges++] = ft_strdup(tab[0]);
					trigger++;
				}
				j++;
			}
		}
		i++;
	}
	if (trigger != 1)
		return (-1);
	return (0);
}
