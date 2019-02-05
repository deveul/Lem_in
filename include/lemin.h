/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/02/05 11:17:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef struct		s_node
{
	char	*name;
	int		x;
	int		y;
	int		nb_edges;
	char	**edges;
	int		*connexion;
	int		nb_connexion;
	int		start;
	int		end;
	int		check;
}					t_node;

typedef struct		s_ant
{
	int				nb;
	char			*current_node;
}					t_ant;

typedef struct		s_path
{
	int				*connexion;
	char			**path;
	int				len;
}					t_path;

typedef struct		s_env
{
	t_node			*nodes;
	t_ant			*ants;
	t_path			*paths;
	int				start;
	int				end;
	int				nb_ants;
	int				nb_nodes;
	int		delimiter;
}					t_env;

void				algo(t_env *env);
int					read_data(t_env *env);
void				print_env(t_env *env);
int					fill_node(t_env *env, char **tab);
int					fill_edge(t_env *env, char **tab);

#endif
