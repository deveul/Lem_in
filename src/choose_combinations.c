/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_combinations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:59:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/04 11:17:30 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	sum_lenght(t_env *env, int index)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < env->final_combi[index].nb_combi)
	{
		len += env->paths[env->final_combi[index].index_array[i]].len;
		i++;
	}
	return (len);
}

void		choose_combinations(t_env *env)
{
	int		i;
	int		nb_line;
	int		tmp;
	int		save;
	int		sum;

	sum = sum_lenght(env, 0);
	nb_line = (sum + env->nb_ants) / env->final_combi[0].nb_combi;
	if ((sum + env->nb_ants) % env->final_combi[0].nb_combi == 0)
		nb_line--;
	save = 0;
	i = 1;
	while (i < env->nb_f_c)
	{
		sum = sum_lenght(env, i);
		tmp = (sum + env->nb_ants) / env->final_combi[i].nb_combi;
		if ((sum + env->nb_ants) % env->final_combi[0].nb_combi == 0)
			tmp--;
		if (tmp < nb_line && (save = i))
			nb_line = tmp;
		i++;
	}
	env->c_c = save;
	env->nb_line = nb_line;
	ft_printf("line estimated:%d\n", nb_line);
}
