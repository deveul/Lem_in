/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:04:12 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/07 15:01:48 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	move_to_last_room(t_env *env, int *tmp, int j)
{
	if (env->rooms[tmp[j - 1]].room_content != 0
			|| tmp[j - 1] == env->start_index)
	{
		ft_printf("L%d-%s ", env->rooms[tmp[j - 1]].room_content,
				env->rooms[env->end_index].name);
		env->rooms[tmp[j - 1]].room_content = 0;
		env->nb_ants--;
	}
}

static void	move_in_graph(t_env *env, int *tmp, int j)
{
	if (j > 1 && env->rooms[tmp[j - 1]].room_content != 0)
	{
		ft_printf("L%d-%s ", env->rooms[tmp[j - 1]].room_content,
				env->rooms[tmp[j]].name);
		env->rooms[tmp[j]].room_content = env->rooms[tmp[j - 1]].room_content;
		env->rooms[tmp[j - 1]].room_content = 0;
	}
}

static void	move_from_start(t_env *env, int *ants_in, int j, int i)
{
	int		*tmp;

	tmp = env->paths[env->combi.index_array[i]].path;
	if (env->paths[env->combi.index_array[i]].ants_launched
			< env->combi.ants_by_index[i])
	{
		ft_printf("L%d-%s ", (*ants_in), env->rooms[tmp[1]].name);
		env->rooms[tmp[j]].room_content = (*ants_in)++;
		env->paths[env->combi.index_array[i]].ants_launched++;
	}
}

void		move_all(t_env *env)
{
	int		i;

	i = 1;
	while (i < env->nb_ants)
	{
		ft_printf("L%d-%s ", i, env->rooms[env->end_index].name);
		i++;
	}
	ft_printf("L%d-%s\n", i, env->rooms[env->end_index].name);
}

void		move_ants(t_env *env)
{
	int		i;
	int		j;
	int		ants_in;
	int		*tmp;

	ants_in = 1;
	while (env->nb_ants > 0)
	{
		i = -1;
		while (++i < env->nb_path)
		{
			tmp = env->paths[env->combi.index_array[i]].path;
			j = env->paths[env->combi.index_array[i]].len;
			move_to_last_room(env, tmp, j);
			while (--j > 0)
				if (env->rooms[tmp[j]].room_content == 0)
				{
					move_in_graph(env, tmp, j);
					if (j == 1)
						move_from_start(env, &ants_in, j, i);
				}
		}
		ft_putendl("");
		env->line_printed++;
	}
}
