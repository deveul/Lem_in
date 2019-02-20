/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_matrice_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:40:58 by smakni            #+#    #+#             */
/*   Updated: 2019/02/20 18:25:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	update_start(t_env *env)
{
	int i;

	i = 0;
	while (i < env->start_nb)
	{
		if (i != env->i_s)
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
	env->i_s++;
}

static	void	update_end(t_env *env)
{
	int i;

	i = 0;
	while (i < env->end_nb)
	{
		if (i != env->i_e)
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
	env->i_e++;
}

static	void	reset_matrice(t_env *env)
{
	int i;

	i = 0;
	while (i < env->end_nb)
	{
		env->matrice[env->end_index][env->end_links[i]] = 1;
		env->matrice[env->end_links[i]][env->end_index] = 1;
		i++;
	}
	env->i_e = 0;
}

void			update_matrice_2(t_env *env, int index)
{
	if (index <= env->start_nb * env->end_nb)
	{
		if (index % env->end_nb == 0)
		{
			//ft_printf("MODULO\n");
			update_start(env);
			reset_matrice(env);
		}
		update_end(env);
	}
}
