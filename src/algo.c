/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/04 19:18:44 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		check_path(t_env *env, int index, int index_2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < env->paths[j].len)
	{
		ft_printf("path = %s | edge = %s\n",  env->paths[j].path[i], env->nodes[index].edges[index_2]);
		if (ft_strstr(env->nodes[index].edges[index_2], env->paths[j].path[i]))
			return (-1);
		i++;
	}
	return (0);
}

int		check_index(t_env *env, int index)
{
	int i;

	i = 0;
	ft_printf("for node name : %s[%d]\n", env->nodes[index].name, index);
	ft_printf("nb_connection = %d\n", env->nodes[index].nb_edges);
	env->nodes[index].check = 1;
	while (i < env->nodes[index].nb_edges)
	{
		ft_printf("for node [%s] |", env->nodes[env->nodes[index].connexion[i]].name);
		ft_printf(" check = [%d]\n", env->nodes[env->nodes[index].connexion[i]].check);
		if (env->nodes[env->nodes[index].connexion[i]].check == 0)
			return (env->nodes[index].connexion[i]);
		i++;
	}
	return (-1);
}

void	fill_path(t_env *env, int index, int j)
{
	int i;
	int z;
	int	x;
	int save;

	i = 0;
	z = 0;
	x = 0;
	save = 0;
	env->paths[j].connexion = ft_memalloc(100 * sizeof(int));
	env->paths[j].path = ft_memalloc(100 * sizeof(char *));
	while (env->nodes[index].end != 1)
	{
		ft_printf("NODE = %s\n", env->nodes[index].name);
		ft_printf(">>>>>>>index = %d<<<<<<<<\n", index);
		env->paths[j].path[i++] = ft_strdup(env->nodes[index].name);
		env->paths[j].len++;
		z = 0;
		env->nodes[index].check = 1;
		while (z < env->nodes[index].nb_edges)
		{
			ft_printf(">>>edge = %s\n", env->nodes[index].edges[z]);
			if (env->nodes[env->nodes[index].connexion[z]].check == 0 
					&& check_path(env, index, z) == 0)
			{
				env->paths[j].path[i] = ft_strdup(env->nodes[index].edges[z]);
				break ;
			}
			z++;
		}
		env->paths[j].len++;
		ft_printf("cp = %s\n", env->paths[j].path[i]);
		if ((index = check_index(env, env->nodes[index].connexion[z])) == -1)
			return ;
		i++;
//		break;
	}
}


void	algo(t_env *env)
{
	int 	i;

	i = 0;
	env->paths = ft_memalloc(100 * sizeof(t_path *));
	while (i < env->nb_nodes)
	{
		if (env->nodes[i].start == 1)
		{
			env->nodes[i].check = 1;
			break ;
		}
		i++;
	}
	fill_path(env, i, 0);
	i = 0;
	while (i < env->paths[0].len)
	{
		ft_printf("path = %s\n", env->paths[0].path[i]);	
		i++;
	}
}	
