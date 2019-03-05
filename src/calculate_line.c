/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:59:09 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/05 22:58:45 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	sum_lenght(t_env *env)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < env->nb_path)
	{
		len += env->paths[i].len;
		i++;
	}
	return (len);
}

int			calculate_line(t_env *env)
{
	int		nb_line;
	int		sum;

	sum = sum_lenght(env);
	nb_line = (sum + env->nb_ants) / env->nb_path;
	if ((sum + env->nb_ants) % env->nb_path == 0)
		nb_line--;
	ft_printf("ICI NB_LINE = %d\n", nb_line);
	ft_printf("ICI sum = %d\n", sum);
	return (nb_line);
}
