/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:07:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/05 11:10:22 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	free_memory(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env->nb_nodes)
	{
		j = 0;
		while (j < env->nodes[i].nb_edges)
			ft_strdel(&env->nodes[i].edges[j++]);
		free (env->nodes[i].edges);
		free (env->nodes[i].connexion);
		free (env->nodes[i].name);
		i++;
	}
	free(env->nodes);
	free(env->ants);
}

static void init_env(t_env *env)
{
	env->nodes = ft_memalloc(20 * sizeof(t_node));
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
	algo(&env);
	free_memory(&env);
	return (0);
}
