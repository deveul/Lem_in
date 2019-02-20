/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:00:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/19 19:24:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	get_len_min(t_env *env)
{
	int		i;
	int		len;

	i = 1;
	len = env->paths[env->final_combi[env->c_c].index_array[0]].len;
	while (i < env->final_combi[env->c_c].nb_path)
	{
		if (env->paths[env->final_combi[env->c_c].index_array[i]].len < len)
			len = env->paths[env->final_combi[env->c_c].index_array[i]].len;
		i++;
	}
	env->len_min = len;
}

void		dispatch_ants(t_env *env)
{
	get_len_min(env);
	move_ants(env);
}
