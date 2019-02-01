/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/01 19:14:39 by vrenaudi         ###   ########.fr       */
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
}

int		main(void)
{
	t_env	env;

	init_env(&env);
	read_data(&env);
	print_env(&env);
	return (0);
}
