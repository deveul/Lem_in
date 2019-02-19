/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_combinations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:59:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/19 19:15:15 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	sum_lenght(t_env *env, int index)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < env->final_combi[index].nb_path)
	{
		len += env->paths[env->final_combi[index].index_array[i]].len;
		i++;
	}
	return (len);
}

void		choose_combi(t_env *env)
{
	int		i;
	int		nb_line;
	int		tmp;
	int		save;

	nb_line = (sum_lenght(env, 0) + env->nb_ants) / env->final_combi[0].nb_path - 1;
	save = 0;
	i = 1;
	while (i < env->nb_f_c)
	{
		tmp = (sum_lenght(env, i) + env->nb_ants) / env->final_combi[i].nb_path - 1;
		if (tmp < nb_line)
		{
			nb_line = tmp;
			save = i;
		}
		i++;
	}
	env->c_c = save;
	env->nb_line = nb_line;
}
