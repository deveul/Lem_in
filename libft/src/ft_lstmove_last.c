/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:35:03 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstmove_last(t_list **alst, t_list *elem)
{
	t_list **tmp;

	tmp = alst;
	if (!tmp)
		return ;
	while (*tmp)
		*tmp = (*tmp)->next;
	elem->next = NULL;
}
