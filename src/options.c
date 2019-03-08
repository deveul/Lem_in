/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:26:34 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/07 14:55:46 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_option(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	if (env->print_option == 2)
		ft_printf("\nnumber of line printed : %d\n", env->line_printed);
	if (env->print_option != 1)
		return ;
	ft_putendl("\n>>>>>>>>>>>>>>>>>>>>>>>PATHS<<<<<<<<<<<<<<<<<<<<<<<");
	while (i < env->nb_path)
	{
		ft_putendl("");
		ft_printf("Path[%2d]: ", i);
		j = 0;
		while (j <= env->paths[i].len)
		{
			ft_printf("%-10s", env->rooms[env->paths[i].path[j]].name);
			j++;
		}
		ft_putendl("");
		i++;
	}
	ft_putendl("");
}

void	analyze_options(t_env *env, char *option)
{
	if (ft_strequ(option, "--print_paths"))
		env->print_option = 1;
	else if (ft_strequ(option, "--print_line_number"))
		env->print_option = 2;
}
