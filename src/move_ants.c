/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:04:12 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/20 11:07:10 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		move_to_last_room(t_env *env, int *tmp, int j)
{
	if (env->rooms[tmp[j - 1]].room_content != 0)
	{
		ft_printf("L%d-%s ", env->rooms[tmp[j - 1]].room_content, env->rooms[env->end_index].name);
		env->rooms[tmp[j - 1]].room_content = 0;
		env->nb_ants--;
	}
}

void		move_in_graph(t_env *env, int *tmp, int j)
{
	ft_printf("L%d-%s ", env->rooms[tmp[j - 1]].room_content, env->rooms[tmp[j]].name);
	env->rooms[tmp[j]].room_content = env->rooms[tmp[j - 1]].room_content;
	env->rooms[tmp[j - 1]].room_content = 0;
}

void		move_from_start(t_env *env, int *ants_in, int j, int i)
{
	int		*tmp;

	tmp = env->paths[env->final_combi[env->c_c].index_array[i]].path;
	if (env->paths[env->final_combi[env->c_c].index_array[i]].ants_launched < env->final_combi[env->c_c].ants_by_index[i])
	{
		ft_printf("L%d-%s ", (*ants_in), env->rooms[tmp[1]].name);
		env->rooms[tmp[j]].room_content = (*ants_in)++;
		env->paths[env->final_combi[env->c_c].index_array[i]].ants_launched++;
	}
}

void		move_ants(t_env *env, t_ants ants)
{
	int		i;
	int		j;
	int		ants_in;
	int		line_printed;
	int		*tmp;

	ants_in = 1;
	line_printed = 0;
	while (env->nb_ants > 0)
	{
		i = -1;
		while (++i < ants.nb_path)
		{
			tmp = env->paths[env->final_combi[env->c_c].index_array[i]].path;
			j = env->paths[env->final_combi[env->c_c].index_array[i]].len;
			move_to_last_room(env, tmp, j);
			while (--j > 0)
				if (env->rooms[tmp[j]].room_content == 0)
				{
					if (j > 1 && env->rooms[tmp[j - 1]].room_content != 0)
						move_in_graph(env, tmp, j);
					else if (j == 1)
						move_from_start(env, &ants_in, j, i);
				}
		}
		line_printed++;
		ft_putendl("");
	}
	ft_printf("line printed:%d\n", line_printed);
}
