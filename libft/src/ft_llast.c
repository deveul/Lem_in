/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:48:22 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_llast(t_list *lst, void *content, size_t content_size)
{
	t_list	*element;
	t_list	*tmp;

	if ((element = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (element)
	{
		element->content = content;
		element->content_size = content_size;
		element->next = NULL;
		if (lst == NULL)
			lst = element;
		else
		{
			tmp = lst;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = element;
		}
	}
	return (lst);
}
