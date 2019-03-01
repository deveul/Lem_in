/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/01 11:09:58 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		init_env(t_env *env)
{
	env->nodes = NULL;
	env->data = NULL;
	env->results = NULL;
	env->rooms = NULL;
	env->matrice = NULL;
	env->nb_ants = -1;
	env->nb_nodes = 0;
	env->nb_path = 0;
	env->nb_edges = 0;
	env->start = 0;
	env->start_nb = 0;
	env->end = 0;
	env->end_nb = 0;
	env->start_index = -1;
	env->end_index = -1;
	env->i_e = 0;
	env->i_s = 0;
	env->flow = NULL;
	env->nb_path_ok = 0;
	env->nb_line = 0;
}

int				main(void)
{
	t_env	env;

	init_env(&env);
	if (read_data(&env) == -1)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	if (analyze_graph(&env) == -1)
	{
		ft_printf("ERROR\n");
		exit(-1);
	}
	print_data(env.data, env.nb_line);
	fill_combinations(&env);
	choose_combinations(&env);
	dispatch_ants(&env);
	free_memory(&env);
	return (0);
}
