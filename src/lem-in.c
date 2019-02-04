/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/04 13:44:32 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void init_env(t_env *env)
{
	env->nodes = ft_memalloc(1000 * sizeof(t_node));
	env->nodes->nb_edges = 0;
	env->nb_ants = -1;
	env->nb_nodes = 0;
	env->start = 0;
	env->end = 0;
	env->delimiter = 0;
}

int		main(void)
{
	t_env	env;

	init_env(&env);
	if (read_data(&env) == -1 || env.start == 0 || env.end == 0)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	print_env(&env);
	return (0);
}
