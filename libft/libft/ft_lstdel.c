/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:08:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/17 16:31:47 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*nxttmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		nxttmp = tmp->next;
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = nxttmp;
	}
	*alst = NULL;
}
