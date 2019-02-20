/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:53:12 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/16 15:41:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		create_rooms(t_node *node, t_room **rooms, int nb_nodes)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = node;
	if (!(*rooms = ft_memalloc(sizeof(t_room) * nb_nodes)))
		exit (-1);
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
