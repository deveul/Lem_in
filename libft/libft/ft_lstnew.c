/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:32:07 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/14 16:46:27 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*newc;

	if ((new = (t_list*)malloc(sizeof(t_list))) == 0)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		newc = ft_memalloc(content_size);
		ft_memcpy(newc, content, content_size);
		new->content = newc;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
