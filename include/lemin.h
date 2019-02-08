/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/02/08 12:19:46 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef struct		s_room
{
	char	*name;
	int		x;
	int		y;
	int		nb_edges;
	char	**edges;
	int		*connexion;
	int		start;
	int		end;
	int		check;
	int		index;
}					t_room;

typedef struct		s_node
{
	t_room			room;
	struct	s_node 	*next;
}					t_node;

typedef struct		s_ant
{
	int				nb;
	char			*current_node;
}					t_ant;

typedef struct		s_path
{
	int				*path;
	int				len;
	int				end_found;
}					t_path;

typedef struct		s_fifo
{
	int				index;
	int				path_index;
}					t_fifo;

typedef struct		s_env
{
	t_node			*nodes;
	t_room			*rooms;
	t_ant			*ants;
	t_path			*paths;
	t_fifo			*fifo;
	int				**matrice;
	int				fifo_index;
	int				start;
	int				start_index;
	int				end;
	int				end_index;
	int				nb_ants;
	int				nb_nodes;
	int				nb_path;
	int				nb_fifo;
	int				delimiter;
}					t_env;

void				add_node(t_node **nodes, t_room room);
void				create_rooms(t_node *node, t_room **rooms);
void				algo(t_env *env);
int					read_data(t_env *env);
int					fill_matrice(t_env *env);
void				print_env(t_env *env);
int					fill_room(t_env *env, char **tab);
int					fill_edge(t_env *env, char **tab);
int					*dup_table(int *src, int len);
int					*expand_table(int *src, int len, int to_add);
t_path				*add_path(t_path *tocpy, int nb_path, int pathtocpy);

#endif
