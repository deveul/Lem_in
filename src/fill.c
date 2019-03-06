/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:13:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 17:47:48 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		check_unicity(t_node *nodes, char *name)
{
	t_node	*tmp;

	tmp = nodes;
	while (tmp)
	{
		if (ft_strequ(name, tmp->room.name))
		{
			ft_putendl(ERROR_DUPLICATE_ROOM);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}

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

static void		add_node(t_node **nodes, t_room room)
{
	t_node *tmp;
	t_node *new;

	tmp = *nodes;
	if (!(new = ft_memalloc(sizeof(t_node))))
		exit(-1);
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

int				fill_room(t_env *env, char **tab)
{
	t_room tmp;

	tmp.name = NULL;
	tmp.start = 0;
	tmp.end = 0;
	tmp.check = 0;
	tmp.index = 0;
	tmp.v_in = -1;
	tmp.v_out = -1;
	if (check_unicity(env->nodes, tab[0]) == -1)
		return (-1);
	if (ft_isnumber(tab[1]) == -1 || ft_isnumber(tab[2]) == -1)
	{
		ft_putendl(ERROR_IN_COORDINATES);
		return (-1);
	}
	tmp.name = ft_strdup(tab[0]);
	check_start_end(env, &tmp);
	tmp.index = env->nb_nodes;
	tmp.check = 0;
	tmp.room_content = 0;
	tmp.capacity = 0;
	add_node(&env->nodes, tmp);
	env->nb_nodes++;
	return (0);
}

int				fill_matrice(t_env *env, char **tab)
{
	int		i;
	int		j;

	i = 0;
	if (env->rooms == NULL)
		create_rooms(env->nodes, &env->rooms, env->nb_nodes);
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
					return (0);
				}
				j++;
			}
		}
		i++;
	}
	return (-1);
}
