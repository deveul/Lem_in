/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:13:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/01 19:10:14 by vrenaudi         ###   ########.fr       */
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
	env->nodes[env->nb_nodes].x = ft_atoi(tab[1]);
	env->nodes[env->nb_nodes].y = ft_atoi(tab[2]);
	env->nodes[env->nb_nodes++].edges = ft_memalloc(100 * sizeof(char *));
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
	return (0);
}

void		fill_edge(t_env *env, char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_nodes)
	{
		if (ft_strequ(tab[0], env->nodes[i].name))
		{
			j = 0;
			while (j < env->nb_nodes)
			{
				if (ft_strequ(tab[1], env->nodes[j].name))
				{
					env->nodes[j].edges[env->nodes[j].nb_edges++] = ft_strdup(tab[0]);
				}
				j++;
			}
			env->nodes[i].edges[env->nodes[i].nb_edges++] = ft_strdup(tab[1]);
		}
		i++;
	}
}
