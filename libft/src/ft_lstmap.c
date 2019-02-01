/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:01:15 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((new->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
