/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:55:19 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 15:04:42 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((new->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
