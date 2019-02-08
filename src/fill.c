/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:13:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 16:09:32 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
/*
static int	check_unicity(t_env *env, char *name)
{
	int		i;

	i = 0;
	while (i < env->nb_nodes)
	{
		if (ft_strequ(name, env->rooms[i].name))
		{
			ft_printf("Duplicate room\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
*/
static	void	check_start_end(t_env *env, t_room *tmp)
{
	if (env->start == 1)
	{
		tmp->start = 1;
		env->start = 2;
		env->start_index = env->nb_nodes;
	}
	if (env->end == 1)
	{
		tmp->end = 1;
		env->end = 2;
		env->end_index = env->nb_nodes;
	}
}

int			fill_room(t_env *env, char **tab)
{
	t_room tmp;

	tmp = (t_room){};
//	if (check_unicity(env, tab[0]) == -1)
//		return (-1);
	tmp.name = ft_strdup(tab[0]);
	if (ft_isnumber(tab[1]) == -1 || ft_isnumber(tab[2]) == -1)
	{
		ft_printf("Wrong coordinates\n");
		return (-1);
	}	
	check_start_end(env, &tmp);
	tmp.index = env->nb_nodes;
	tmp.x = ft_atoi(tab[1]);
	tmp.y = ft_atoi(tab[2]);
	tmp.check = 0;
	tmp.connexion = ft_memalloc(100 * sizeof(int));
	add_node(&env->nodes, tmp);
	env->nb_nodes++;
	return (0);
}

int			fill_matrice(t_env *env, char **tab)
{
	int		i;
	int		j;
	int		trigger;

	i = 0;
	trigger = 0;
	if (env->rooms == NULL)
		create_rooms(env->nodes, &env->rooms);
	while (i < env->nb_nodes)
	{
		if (ft_strequ(tab[0], env->rooms[i].name))
		{
			j = 0;
			while (j < env->nb_nodes)
			{
				if (ft_strequ(tab[1], env->rooms[j].name))
				{
					env->matrice[i][j] = 1;
					env->matrice[j][i] = 1;
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
