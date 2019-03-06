/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:21:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 18:21:52 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		get_ants_nb(t_env *env, char *line)
{
	if (!(env->data = ft_memalloc(sizeof(char*) * NB_LINE + 1)))
		exit(-1);
	while (env->nb_ants == -1 && get_next_line(0, &line) > 0)
	{
		if (line[0] != '#')
		{
			env->nb_ants = ft_atoi(line);
			if (env->nb_ants <= 0 || env->nb_ants > INT_MAX)
			{
				ft_putendl(ERROR_NUMBER_ANTS);
				exit(-1);
			}
			env->data[env->nb_line++] = line;
		}
		else
			ft_strdel(&line);
	}
}

static void		handle_start_end_com(t_env *env, int *re, char *line)
{
	if (ft_strequ(line, "##start"))
	{
		if (env->start == 2)
		{
			ft_putendl(ERROR_TOO_MANY_STARTS);
			exit(-1);
		}
		env->start = 1;
	}
	else if (ft_strequ(line, "##end"))
	{
		if (env->end == 2)
		{
			ft_putendl(ERROR_TOO_MANY_ENDS);
			exit(-1);
		}
		env->end = 1;
	}
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
	{
		if (env->nb_line < ((NB_LINE * (*re)) - 1))
			env->data[env->nb_line++] = line;
		else
			env->data = increase_size(env->data, line, re, &env->nb_line);
	}
}

static void		get_connexion_start_end(t_env *env)
{
	int		i;

	i = 0;
	env->start = 0;
	env->end = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1)
			env->start++;
		if (env->matrice[env->end_index][i] == 1)
			env->end++;
		i++;
	}
}

int				read_data(t_env *env)
{
	char	*line;
	int		re;

	line = NULL;
	re = 1;
	get_ants_nb(env, line);
	while (get_next_line(0, &line) > 0)
	{
		if (env->nb_line < ((NB_LINE * re) - 1) && line[0] != '#')
			env->data[env->nb_line++] = line;
		else if (env->nb_line >= ((NB_LINE * re) - 1) && line[0] != '#')
			env->data = increase_size(env->data, line, &re, &env->nb_line);
		if (line && line[0] == '#')
			handle_start_end_com(env, &re, line);
		else if (analyze_node_edge(env, line) == -1)
			break ;
	}
	if (env->nb_edges == 0)
	{
		ft_putendl(ERROR_NO_EDGE);
		exit(-1);
	}
	get_connexion_start_end(env);
	return (0);
}
