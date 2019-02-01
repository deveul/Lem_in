/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:43:19 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/01/16 14:27:16 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		ft_analyze_data(t_lem *env)
{
	char	*line;
	int		nb;

	if (get_next_line(0, &line) > 0)
	{
		nb = ft_atoi(line);
		ft_strdel(&line);
		if (nb <= 0)
			return (-1);
		else
			env->nb_ants = nb;
	}
	while (get_next_line(0, &line) > 0)
	{

	}
	return (1);
}

int		main(void)
{
	t_lem	env;

	ft_analyze_data(&env);
	return (0);
}
