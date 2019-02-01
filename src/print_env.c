/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/01 18:10:41 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		print_env(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("Ants number : %d\n\n", env->nb_ants);
	ft_printf("Nodes number : %d\n\n", env->nb_nodes);
	while (i < env->nb_nodes)
	{
		ft_printf ("node name : %s\n[\n", env->nodes[i].name);
		j = 0;
		if (env->nodes[i].start == 1)
			ft_printf("\tstarting node\n");
		if (env->nodes[i].end == 1)
			ft_printf("\tending node\n");
		while (j < env->nodes[i].nb_edges)
		{
			ft_printf("\tconnected with node : %s\n", env->nodes[i].edges[j]);
			j++;
		}
		ft_printf("]\n");
		i++;
	}
}
