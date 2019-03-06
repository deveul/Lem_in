/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_combinations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:10:03 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 10:02:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		fill_combinations(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->combi.index_array = ft_memalloc(sizeof(int)*env->nb_path)))
		exit(-1);
	while (i < env->nb_path)
	{
		env->combi.index_array[i] = i;
		i++;
	}
}
