/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:40:58 by smakni            #+#    #+#             */
/*   Updated: 2019/02/16 15:03:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	update_start(t_env *env, int index)
{
	int i;

	i = 0;
	while (i < env->start_nb)
	{
		if (i != index)
		{
			env->matrice[env->start_index][env->start_links[i]] = INFINITE;
			env->matrice[env->start_links[i]][env->start_index] = INFINITE;
		}
		else
		{
			env->matrice[env->start_index][env->start_links[i]] = 1;
			env->matrice[env->start_links[i]][env->start_index] = 1;
		}
		i++;
	}
}

static	void	update_end(t_env *env, int index)
{
	int i;

	i = 0;
	while (i < env->end_nb)
	{
		if (i != index - env->start_nb)
		{
			env->matrice[env->end_index][env->end_links[i]] = INFINITE;
			env->matrice[env->end_links[i]][env->end_index] = INFINITE;
		}
		else
		{
			env->matrice[env->end_index][env->end_links[i]] = 1;
			env->matrice[env->end_links[i]][env->end_index] = 1;
		}
		i++;
	}
}

static	void	reset_matrice(t_env *env)
{
	int i;

	i = 0;
	while (i < env->start_nb)
	{
		env->matrice[env->start_index][env->start_links[i]] = 1;
		env->matrice[env->start_links[i]][env->start_index] = 1;
		i++;
	}
}

void			update_matrice(t_env *env, int index)
{
	if (index < env->start_nb + env->end_nb)
	{
		if (index < env->start_nb)
			update_start(env, index);
		else if (index - env->start_nb <= env->end_nb)
		{
			if (index == env->start_nb)
				reset_matrice(env);
			update_end(env, index);
		}
	}
}
