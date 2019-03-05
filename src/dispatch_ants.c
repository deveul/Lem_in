/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:00:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/05 10:36:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_turn_lenght(t_env *env, int *len)
{
	int		i;
	int		index_long;

	i = -1;
	while (++i < env->final_combi[env->c_c].nb_combi)
		if (env->final_combi[env->c_c].ants_by_index[i] != -1)
		{
			index_long = i;
			(*len) = env->paths[env->final_combi[env->c_c].index_array[i]].len;
			break ;
		}
	i = -1;
	while (++i < env->final_combi[env->c_c].nb_combi)
		if (env->final_combi[env->c_c].ants_by_index[i] != -1)
			if (env->paths[env->final_combi[env->c_c].index_array[i]].len
					> (*len))
			{
				index_long = i;
				(*len) = env->paths[env->final_combi[env->c_c].index_array[i]].len;
			}
	return (index_long);
}

static int	get_ants_by_turn(t_env *env, int len)
{
	int		ants;
	int		i;
	int		tmp;

	i = 0;
	ants = 0;
	while (i < env->final_combi[env->c_c].nb_combi)
	{
		if (env->final_combi[env->c_c].ants_by_index[i] != -1)
		{
			ants += (1 + len);
			ants -= env->paths[env->final_combi[env->c_c].index_array[i]].len;
			tmp = env->paths[env->final_combi[env->c_c].index_array[i]].len;
			env->final_combi[env->c_c].ants_by_index[i] = 1 + len - tmp;
		}
		i++;
	}
	return (ants);
}

void		dispatch_remaining(t_ants ants, int *ants_by_index, int nb_path)
{
	int		*tmp;
	int		ants_missing;
	int		i;
	int		j;

	ants_missing = (ants.same_ants_nb * ants.nb_path) + ants.by_turn;
	if (ants_missing != ants.nb_ants)
	{
		ants_missing = ants.nb_ants - ants_missing;
		if (!(tmp = ft_memalloc(sizeof(int) * nb_path)))
			exit(-1);
		i = -1;
		while (++i < nb_path)
			tmp[i] = ants_by_index[i];
		ft_revsort_int_tab(tmp, nb_path);
		j = 0;
		i = -1;
		while (++i < nb_path && j < ants_missing)
			if (ants_by_index[i] != -1)
			{
				ants_by_index[i]++;
				j++;
			}
		free(tmp);
	}
}

static void	fill_ants_by_index(t_env *env, t_ants ants)
{
	int		i;

	dispatch_remaining(ants, env->final_combi[env->c_c].ants_by_index,
			env->final_combi[env->c_c].nb_combi);
	i = -1;
	while (++i < env->final_combi[env->c_c].nb_combi)
	{
		if (env->final_combi[env->c_c].ants_by_index[i] != -1)
			env->final_combi[env->c_c].ants_by_index[i] += ants.same_ants_nb;
		env->paths[env->final_combi[env->c_c].index_array[i]].ants_launched = 0;
	}
	i = -1;
	while (++i < env->final_combi[env->c_c].nb_combi)
	{
		ft_printf("ants_by_index[%d]:%d\n", i,
				env->final_combi[env->c_c].ants_by_index[i]);
		ft_printf("len_index[%d]:%d\n", i,
				env->paths[env->final_combi[env->c_c].index_array[i]].len);
	}
	move_ants(env);
}

void		dispatch_ants(t_env *env)
{
	int		len;
	int		index_long;
	t_ants	ants;

	len = 0;
	ants.nb_ants = env->nb_ants;
	ants.nb_path = env->final_combi[env->c_c].nb_combi;
	if (!(env->final_combi[env->c_c].ants_by_index = ft_memalloc(sizeof(int)
					* ants.nb_path)))
		exit(-1);
	index_long = get_turn_lenght(env, &len);
	ants.by_turn = get_ants_by_turn(env, len);
	while (ants.by_turn > env->nb_ants && ants.nb_path > 1)
	{
		env->final_combi[env->c_c].ants_by_index[index_long] = -1;
		ants.nb_path--;
		index_long = get_turn_lenght(env, &len);
		ants.by_turn = get_ants_by_turn(env, len);
	}
	ants.same_ants_nb = (env->nb_ants - ants.by_turn) / ants.nb_path;
	fill_ants_by_index(env, ants);
}
