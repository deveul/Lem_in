/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/02/14 14:32:56 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef struct		s_room
{
	char			*name;
	int				check;
	int				end;
	int				index;
	int				start;
//	int				x;
//	int				y;
}					t_room;

typedef struct		s_node
{
	t_room			room;
	struct	s_node 	*next;
}					t_node;

typedef struct		s_ant
{
	char			*current_node;
	int				nb;
}					t_ant;

typedef struct		s_path
{
	int				*path;
	int				end_found;
	int				len;
}					t_path;

typedef struct		s_res
{
	t_path			path;
	struct	s_res	*next;
}					t_res;

typedef struct		s_dij
{
	int				*distance;
	int				*pred;
	int				*visited;
	int				min;
	int				nextnode;
}					t_dij;

typedef struct		s_fifo
{
	int				index;
	int				path_index;
}					t_fifo;

typedef struct		s_env
{
	int				**matrice;
	int				delimiter;
	int				end;
	int				end_index;
	int				fifo_index;
	int				nb_edges;
	int				nb_fifo;
	int				nb_nodes;
	int				nb_path;
	int				nb_path_ok;
	int				start;
	int				start_index;
	long			nb_ants;
	int				start_nb;
	int				end_nb;
	int				*start_links;
	int				*end_links;
	t_ant			*ants;
	t_fifo			*fifo;
	t_node			*nodes;
	t_res			*results;
	t_path			first_path;
	t_path			*paths_ok;
	t_path			*paths;
	t_room			*rooms;
}					t_env;

int					*dup_table(int *src, int len);
int					*expand_table(int *src, int len, int to_add);
int					algo(t_env *env);
int					analyze_edge(t_env *env, char *line);
int					analyze_node(t_env *env, char *line);
int					analyze_node_edge(t_env *env, char *line);
int					create_matrice(t_env *env);
int					fill_matrice(t_env *env, char **tab);
int					fill_room(t_env *env, char **tab);
int					get_ants_nb(t_env *env, char *line);
int					handle_start_end_com(t_env *env, char *line);
int					init_paths(t_env *env);
t_path				*add_path(t_path *tocpy, int nb_path, int pathtocpy);
void				add_node(t_node **nodes, t_room room);
void				add_result(t_res **results, t_path path);
void				create_rooms(t_node *node, t_room **rooms, int nb_nodes);
void				fill_initial_fifo(t_env *env);
void				print_env(t_env *env);
void				print_path(t_env *env);
int					analyze_node(t_env *env, char *line);
int					analyze_edge(t_env *env, char *line);
int					analyze_node_edge(t_env *env, char *line);
int					dijkstra(t_env *env, int n, int index);
void				aff_data_1(t_dij *dij, int n, int count);
void				aff_data_2(t_dij *dij, int i);
void				aff_data_3(t_dij *dij, int i, t_env *env);
void				create_path_tab(t_res *res, t_path **paths_ok, int nb_paths);


#endif
