/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:00:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/11 10:43:08 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_turn_lenght(t_env *env, int *len)
{
	int		i;
	int		index_long;

	i = -1;
	while (++i < env->nb_path)
		if (env->combi.ants_by_index[i] != -1)
		{
			index_long = i;
			(*len) = env->paths[env->combi.index_array[i]].len;
			break ;
		}
	i = -1;
	while (++i < env->nb_path)
		if (env->combi.ants_by_index[i] != -1)
			if (env->paths[env->combi.index_array[i]].len
					> (*len))
			{
				index_long = i;
				(*len) = env->paths[env->combi.index_array[i]].len;
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
	while (i < env->nb_path)
	{
		if (env->combi.ants_by_index[i] != -1)
		{
			ants += (1 + len);
			ants -= env->paths[env->combi.index_array[i]].len;
			tmp = env->paths[env->combi.index_array[i]].len;
			env->combi.ants_by_index[i] = 1 + len - tmp;
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

	dispatch_remaining(ants, env->combi.ants_by_index,
			env->nb_path);
	i = -1;
	while (++i < env->nb_path)
	{
		if (env->combi.ants_by_index[i] != -1)
			env->combi.ants_by_index[i] += ants.same_ants_nb;
		env->paths[env->combi.index_array[i]].ants_launched = 0;
	}
	i = -1;
	while (++i < env->nb_path)
		if (env->paths[i].len == 1)
			return (move_all(env));
	move_ants(env);
}

void		dispatch_ants(t_env *env)
{
	int		len;
	int		index_long;
	t_ants	ants;

	len = 0;
	ants.nb_ants = env->nb_ants;
	ants.nb_path = env->nb_path;
	if (!(env->combi.ants_by_index = ft_memalloc(sizeof(int)
					* ants.nb_path)))
		exit(-1);
	index_long = get_turn_lenght(env, &len);
	ants.by_turn = get_ants_by_turn(env, len);
	while (ants.by_turn > env->nb_ants && ants.nb_path > 1)
	{
		env->combi.ants_by_index[index_long] = -1;
		ants.nb_path--;
		index_long = get_turn_lenght(env, &len);
		ants.by_turn = get_ants_by_turn(env, len);
	}
	ants.same_ants_nb = (env->nb_ants - ants.by_turn) / ants.nb_path;
	fill_ants_by_index(env, ants);
}
