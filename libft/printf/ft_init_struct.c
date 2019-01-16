/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:36:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 16:06:24 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_fmt(t_fmt *current)
{
	current->minus = 0;
	current->plus = 0;
	current->zero = 0;
	current->space = 0;
	current->hash = 0;
	current->width = 0;
	current->acy = -1;
	current->size = NULL;
	current->conv = 0;
	current->len = 0;
}

void			ft_init_prf(t_prf *prf)
{
	prf->cpt[0] = 0;
	prf->cpt[1] = 0;
	prf->cpt[2] = 0;
	prf->cpt[3] = 0;
	prf->top = NULL;
	prf->tmp = NULL;
	prf->tmp2 = NULL;
}
