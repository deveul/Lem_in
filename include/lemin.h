/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/02/11 17:55:52 by smakni           ###   ########.fr       */
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
	long			nb_ants;
	int				nb_nodes;
	int				nb_edges;
	int				nb_path_ok;
	int				nb_path;
	int				nb_fifo;
	int				delimiter;
}					t_env;

void				add_node(t_node **nodes, t_room room);
void				create_rooms(t_node *node, t_room **rooms, int nb_nodes);
int					algo(t_env *env);
int					init_paths(t_env *env);
void				fill_initial_fifo(t_env *env);
int					create_matrice(t_env *env);
void				print_env(t_env *env);
void				print_path(t_env *env);
int					fill_room(t_env *env, char **tab);
int					fill_matrice(t_env *env, char **tab);
int					*dup_table(int *src, int len);
int					*expand_table(int *src, int len, int to_add);
t_path				*add_path(t_path *tocpy, int nb_path, int pathtocpy);
int					get_ants_nb(t_env *env, char *line);
int					handle_start_end_com(t_env *env, char *line);
int					analyze_node(t_env *env, char *line);
int					analyze_edge(t_env *env, char *line);
int					analyze_node_edge(t_env *env, char *line);
int					dijkstra(t_env *env, int n, int startnode, int endnode);

#endif
