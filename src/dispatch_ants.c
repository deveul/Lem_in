/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:00:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/19 15:35:33 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_turn_lenght(t_env *env, int *len)
{
	int		i;
	int		index_long;

	i = 1;
	index_long = 0;
	(*len) = env->paths[env->final_combi[env->c_c].index_array[0]].len;
	while (i < env->final_combi[env->c_c].nb_combi)
	{
		if (env->paths[env->final_combi[env->c_c].index_array[i]].len > (*len))
		{
			index_long = i;
			(*len) = env->paths[env->final_combi[env->c_c].index_array[i]].len;
		}
		i++;
	}
	return (index_long);
}

static int	get_ants_by_turn(t_env *env, int len, int index_long)
{
	int		ants;
	int		i;

	i = 0;
	ants = 1;
	while (i < env->final_combi[env->c_c].nb_combi)
	{
		if (i != index_long)
		{
			ants += (1 + len - env->paths[env->final_combi[env->c_c].index_array[i]].len);
			env->final_combi[env->c_c].ants_by_index[i] = 1 + len - env->paths[env->final_combi[env->c_c].index_array[i]].len;
		}
		else
			env->final_combi[env->c_c].ants_by_index[i] = 1;
		i++;
	}
	return (ants);
}

void		dispatch_remaining_ants(t_ants ants, int *ants_by_index)
{
	int		*tmp;
	int		ants_missing;
	int		i;
	int		j;

	if ((ants.same_ants_nb * ants.nb_path) + ants.by_turn != ants.nb_ants)
	{
		ants_missing = ants.nb_ants - ((ants.same_ants_nb * ants.nb_path) + ants.by_turn);
		if (!(tmp = ft_memalloc(sizeof(int) * ants.nb_path)))
			exit(-1);
		ft_revsort_int_tab(tmp, ants.nb_path);
		j = 0;
		while (j < ants_missing)
		{
			i = -1;
			while (++i < ants.nb_path)
				if (i == tmp[j])
				{
					ants_by_index[i]++;
					j++;
				}
		}
		free(tmp);
	}
}

void		dispatch_ants(t_env *env)
{
	int		i;
	int		len;
	int		index_long;
	t_ants	ants;

	len = 0;
	ants.nb_ants = env->nb_ants;
	ants.nb_path = env->final_combi[env->c_c].nb_combi;
	if (!(env->final_combi[env->c_c].ants_by_index = ft_memalloc(sizeof(int) * ants.nb_path)))
		exit(-1);
	index_long = get_turn_lenght(env, &len);
	ants.by_turn = get_ants_by_turn(env, len, index_long);
	ants.same_ants_nb = (env->nb_ants - ants.by_turn) / ants.nb_path;
	ft_printf("same_ants_nb:%d\n", ants.same_ants_nb);
	ft_printf("ants_by_turn:%d\n", ants.by_turn);
	dispatch_remaining_ants(ants, env->final_combi[env->c_c].ants_by_index);
	i = -1;
	while (++i < ants.nb_path)
	{
		env->final_combi[env->c_c].ants_by_index[i] += ants.same_ants_nb;
		ft_printf("index[%d]:%dants\n", i, env->final_combi[env->c_c].ants_by_index[i]);
		env->paths[env->final_combi[env->c_c].index_array[i]].ants_launched = 0;
	}
	move_ants(env, ants);
}
