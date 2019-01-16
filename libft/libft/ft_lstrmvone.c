/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmvone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:14:31 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/14 11:37:00 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrmvone(t_list **b, t_list *to_del, void (*del)(void *, size_t))
{
	t_list *previous;
	t_list *current;

	current = *b;
	if (current == to_del)
	{
		*b = current->next;
		ft_lstdelone(&current, del);
		return ;
	}
	while (current->next)
	{
		previous = current;
		current = current->next;
		if (current == to_del)
		{
			previous->next = current->next;
			ft_lstdelone(&current, del);
			return ;
		}
	}
}
