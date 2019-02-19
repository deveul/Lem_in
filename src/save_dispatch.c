/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:00:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/19 11:22:35 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_turn_lenght(t_env *env, int *len)
{
	int		i;
	int		index_long;

	i = 1;
	index_long = 0;
	(*len) = env->paths[env->final_combi[env->combi_chosen].index_array[0]].len;
	while (i < env->final_combi[env->combi_chosen].nb_combi)
	{
		if (env->paths[env->final_combi[env->combi_chosen].index_array[i]].len > (*len))
		{
			index_long = i;
			(*len) = env->paths[env->final_combi[env->combi_chosen].index_array[i]].len;
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
	while (i < env->final_combi[env->combi_chosen].nb_combi)
	{
		if (i != index_long)
		{
			ants += (1 + len - env->paths[env->final_combi[env->combi_chosen].index_array[i]].len);
			env->final_combi[env->combi_chosen].ants_by_index[i] = 1 + len - env->paths[env->final_combi[env->combi_chosen].index_array[i]].len;
		}
		else
			env->final_combi[env->combi_chosen].ants_by_index[i] = 1;
		i++;
	}
	return (ants);
}

void		move_ants(t_env *env, int ants_by_turn, int len)
{
	int		i;
	int		j;
	int		nb_ants;
	int		ants_in;
	int		nb_path;
	int		line_printed;
	int		set;

	nb_ants = env->nb_ants;
	nb_path = env->final_combi[env->combi_chosen].nb_combi;
	ants_in = 1;
	line_printed = ants_by_turn;
	line_printed = len;
	line_printed = 0;
	set = -1;
	while (++set < nb_path)
		env->paths[env->final_combi[env->combi_chosen].index_array[set]].ants_launched = 0;
	while (nb_ants > 0)
	{
		i = 0;
		while (i < nb_path)
		{
			j = env->paths[env->final_combi[env->combi_chosen].index_array[i]].len;
			while (j > 0)
			{
				if (env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j]].room_content == 0)
				{
					if (j == env->paths[env->final_combi[env->combi_chosen].index_array[i]].len && env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content != 0)
					{
						//	ft_printf("L%d-%s ", env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content, env->rooms[env->end_index].name);
						env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content = 0;
						nb_ants--;
					}
					else if (j > 1 && env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content != 0)
					{
						//	ft_printf("L%d-%s ", env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content, env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j]].name);
						env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j]].room_content = env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content;
						env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j - 1]].room_content = 0;
					}
					else if (j == 1)
						if (ants_in < env->nb_ants + 1)
							if (env->paths[env->final_combi[env->combi_chosen].index_array[i]].ants_launched <= env->final_combi[env->combi_chosen].ants_by_index[i])
							{
								//			ft_printf("L%d-%s ", ants_in, env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[1]].name);
								env->rooms[env->paths[env->final_combi[env->combi_chosen].index_array[i]].path[j]].room_content = ants_in++;
								env->paths[env->final_combi[env->combi_chosen].index_array[i]].ants_launched++;
							}
				}
				j--;
			}
			i++;
		}
		line_printed++;
		//	ft_putendl("");
	}
	ft_printf("line printed:%d\n", line_printed);
}

void		dispatch_ants(t_env *env, int nb)
{
	int		i;
	int		j;
	int		len;
	int		index_long;
	int		ants_by_turn;
	int		*tmp;
	int		same_ants_nb;
	int		ants_missing;

	env->combi_chosen = nb;
	env->final_combi[env->combi_chosen].ants_by_index = ft_memalloc(sizeof(int) * env->final_combi[env->combi_chosen].nb_combi);
	index_long = get_turn_lenght(env, &len);
	ft_printf("len_turn:%d\n", len);
	ft_printf("index_long:%d\n", index_long);
	ants_by_turn = get_ants_by_turn(env, len, index_long);
	ft_printf("ants_by_turn:%d\n", ants_by_turn);
	same_ants_nb = (env->nb_ants - ants_by_turn) / env->final_combi[env->combi_chosen].nb_combi;
	if ((same_ants_nb * env->final_combi[env->combi_chosen].nb_combi) + ants_by_turn != env->nb_ants)
	{
		ants_missing = env->nb_ants - ((same_ants_nb * env->final_combi[env->combi_chosen].nb_combi) + ants_by_turn);
		ft_printf("ants_missing:%d\n", ants_missing);
		tmp = ft_memalloc(sizeof(int) * env->final_combi[env->combi_chosen].nb_combi);
		ft_revsort_int_tab(tmp, env->final_combi[env->combi_chosen].nb_combi);
		j = 0;
		while (j < ants_missing)
		{
			i = 0;
			while (i < env->final_combi[env->combi_chosen].nb_combi)
			{
				if (i == tmp[j])
				{
					env->final_combi[env->combi_chosen].ants_by_index[i]++;
					j++;
				}
				i++;
			}
		}
	}
	ft_printf("same_ants_nb:%d\n", same_ants_nb);
	i = 0;
	while (i < env->final_combi[env->combi_chosen].nb_combi)
	{
		//		ft_printf("index[%d] : %d ants_by_index\n", i, env->final_combi[env->combi_chosen].ants_by_index[i]);
		env->final_combi[env->combi_chosen].ants_by_index[i] += same_ants_nb;
		ft_printf("index[%d] : %d ants_by_index\n", i, env->final_combi[env->combi_chosen].ants_by_index[i]);
		i++;
	}
	move_ants(env, ants_by_turn, len);
	/*	ft_printf("\nNB : %d\n\n", nb);
		sleep(1);
		if (nb < env->nb_f_c - 1)
		dispatch_ants(env, (nb + 1));*/
}
